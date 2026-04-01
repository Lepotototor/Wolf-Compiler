                                                            /* -*- C++ -*- */
// %option defines the parameters with which the flex will be launched
%option noyywrap

%option lex=lex
// Add a param of function lex() generate in Lexer class
%option params="driver::WolfDriver& wd, std::queue<lexer::Token>& tokens"
%option namespace=lexer
// Name of the class generate by flex
%option lexer=Lexer

%top {

#define YY_EXTERN_C extern "C" // For linkage rule

#include <queue>
#include <cerrno>
#include <climits>
#include <regex>
#include <string>

#include "token.hh"
#include "../driver/wolf-driver.hh"

	/* (Define YY_USER_ACTION to update locations). */
// TODO #define YY_USER_ACTION col += size();


#define TOKEN(Type)                             \
  lexer::make_ ## Type(td.location_)

#define TOKEN_VAL(Type, Value)                  \
  lexer::make_ ## Type(Value, td.location_)


%}


%class {
	std::string file;
	unsigned line;
	unsigned col;

	// Use to got new location
	std::string new_file;
	int new_line;

	// Use to detect subcomment
	unsigned lvl;
}

%init {
	file = "";
	line = 0;
	col = 0;

	new_file = "";
	new_line = 0;

	lvl = 0;
}

/* Abbreviations.  */
int             [0-9]+
ID [a-zA-Z_][a-zA-Z0-9_]*
RESERVED_ID _[a-zA-Z0-9_]*
BLANK [ \t\v]
STRING_LITERAL "\"".*"\""

%x SC_COMMENT SC_NEW_LOC

%%

<SC_COMMENT> "/*" {
		lvl++;
	}

<SC_COMMENT> "*/" {
		lvl--;
		if (lvl == 0)
		{
			start(INITIAL);
		}
	}

<SC_COMMENT> <<EOF>> {
		wd.error_get() << misc::error_type::scan
			<< "Comment never finish at "
			// << td.location_ 
			<< "\n";
	}

<SC_COMMENT> .|\n {}


<SC_NEW_LOC> {int} {
	if (new_line  == -1)
	{
		new_line = std::stoi(text());
	}
}

<SC_NEW_LOC> {STRING_LITERAL} {
	new_file = text();
}

<SC_COMMENT> . {}

<SC_NEW_LOC> \n {
	std::cout << "New Loc: " << new_file<< ":" << new_line << "\n";

	file = new_file;
	col = 0;
	line = new_line;

	start(INITIAL);
}


"/*"		{ lvl = 1; start(SC_COMMENT); }

"# " {
	new_line = -1;
	start(SC_NEW_LOC);
	// TODO Parse new Location
}

{BLANK} { /* DO nothing */ }

\n\r		{ line++; col = 0; }
\r\n		{ line++; col = 0; }
\n			{ line++; col = 0; }
\r			{ line++; col = 0; }

"int" { std::cout << "Got int\n"; }
"void" { std::cout << "Got void\n"; }
"return" { std::cout << "Got return\n"; }
"while" { std::cout << "Got while\n"; }
"do" { std::cout << "Got do\n"; }
"if" { std::cout << "Got if\n"; }
"else" { std::cout << "Got else\n"; }

";" { }
"(" { }
")" { }
"{" { }
"}" { }

"==" { }
"||" { }
"&&" { }
"=" { }
"<=" { }
">=" { }
"<" { }
">" { }
"+" { }
"-" { }
"*" { }
"/" { }
"&" { }
"|" { }

{ID} { std::cout << "Indetifier: " << text() << "\n"; }

0/[0-9]+                // no action, prevent trailing 0
{int} { std::cout << "nb: " << text() << "\n"; }

. {
	(void)tokens;
	wd.error_get() << "Invalid character: " << yytext[0] << "\n";
}

%%
