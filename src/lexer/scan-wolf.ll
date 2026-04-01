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
#include "../misc/location.hh"

	/* (Define YY_USER_ACTION to update locations). */
#define YY_USER_ACTION col += size();

#define GET_LOC Location{file, line, col, col + yyleng - 1}
#define GET_TOK(Type) Type ## _TOK

#define TOKEN(Type)										\
	token_type type = Type ## _TOK;						\
	misc::Location location{file, line, col - YYLeng() + 1, col};	\
	Token token{type, location};						\
	tokens.emplace(token);

#define TOKEN_VAL(Type, Value)										\
	token_type type = Type ## _TOK;									\
	misc::Location location{file, line, col - YYLeng() + 1, col};	\
	Token token{type, location, Value};						\
	tokens.emplace(token);


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
number             [0-9]+
ID [a-zA-Z_][a-zA-Z0-9_]*
BLANK [ \t\v\f]
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


<SC_NEW_LOC> {number} {
	if (new_line  == -1)
	{
		new_line = std::stoi(text());
	}
}

<SC_NEW_LOC> {STRING_LITERAL} {
	new_file = text();
	new_file.erase(0, 1);
	new_file.erase(new_file.size() - 1);
}

<SC_NEW_LOC> . {}

<SC_NEW_LOC> \n {
	// std::cout << "New Loc: " << new_file<< ":" << new_line << "\n";

	file = new_file;
	col = 0;
	line = new_line;

	start(INITIAL);
}


"/*"		{ lvl = 1; start(SC_COMMENT); }

"# " {
	new_line = -1;
	start(SC_NEW_LOC);
}

{BLANK} { /* DO nothing */ }

\n\r		{ line++; col = 0; }
\r\n		{ line++; col = 0; }
\n			{ line++; col = 0; }
\r			{ line++; col = 0; }

"auto" { /* keyword auto is ignored */ }

"void"			{ TOKEN(VOID); }
"int"			{ TOKEN(INT); }
"char"			{ TOKEN(CHAR); }
"flot"			{ TOKEN(FLOAT); }
"double"		{ TOKEN(DOUBLE); }
"unsigned"		{ TOKEN(UNSIGNED); }
"signed"		{ TOKEN(SIGNED); }
"long"			{ TOKEN(LONG); }
"short"			{ TOKEN(SHORT); }
"register"		{ TOKEN(REGISTER); }

"struct"		{ TOKEN(STRUCT); }
"union"			{ TOKEN(UNION); }
"enum"			{ TOKEN(ENUM); }

"typedef"		{ TOKEN(TYPEDEF); }
"extern"		{ TOKEN(EXTERN); }
"const"			{ TOKEN(CONST); }
"static"		{ TOKEN(STATIC); }
"inline"		{ TOKEN(INLINE); }
"volatile"		{ TOKEN(VOLATILE); }

"while"			{ TOKEN(WHILE); }
"for"			{ TOKEN(FOR); }
"do"			{ TOKEN(DO); }
"break"			{ TOKEN(BREAK); }
"continue"		{ TOKEN(CONTINUE); }
"if"			{ TOKEN(IF); }
"else"			{ TOKEN(ELSE); }
"switch"		{ TOKEN(SWITCH); }
"case"			{ TOKEN(CASE); }
"default"		{ TOKEN(DEFAULT); }
"goto"			{ TOKEN(GOTO); }
"sizeof"		{ TOKEN(SIZEOF); }
"return"		{ TOKEN(RETURN); }

"!"				{ TOKEN(NOT); }
"=="			{ TOKEN(EQ); }
"!="			{ TOKEN(NOT); }
"<"				{ TOKEN(LT); }
">"				{ TOKEN(GT); }
"<="			{ TOKEN(LE); }
">="			{ TOKEN(GE); }
"&&"			{ TOKEN(AND); }
"||"			{ TOKEN(OR); }
"+"				{ TOKEN(PLUS); }
"-"				{ TOKEN(MINUS); }
"*"				{ TOKEN(STAR); }
"/"				{ TOKEN(DIV); }
"%"				{ TOKEN(MOD); }
"~"				{ TOKEN(TILD); }
"&"				{ TOKEN(AMP); }
"|"				{ TOKEN(PIPE); }
"^"				{ TOKEN(XOR); }
">>"			{ TOKEN(RSHIFT); }
"<<"			{ TOKEN(LSHIFT); }
"?"				{ TOKEN(QUESTION); }

"++"			{ TOKEN(INC); }
"--"			{ TOKEN(DEC); }

"+="			{ TOKEN(PLUS_ASSIGN); }
"-="			{ TOKEN(MINUS_ASSIGN); }
"*="			{ TOKEN(MULT_ASSIGN); }
"/="			{ TOKEN(DIV_ASSIGN); }
"%="			{ TOKEN(MOD_ASSIGN); }
"&="			{ TOKEN(AMP_ASSIGN); }
"|="			{ TOKEN(PIPE_ASSIGN); }
"^="			{ TOKEN(XOR_ASSIGN); }
">>="			{ TOKEN(RSHIFT_ASSIGN); }
"<<="			{ TOKEN(LSHIFT_ASSIGN); }

"="				{ TOKEN(ASSIGN); }
"."				{ TOKEN(DOT); }
"->"			{ TOKEN(ARROW); }
","				{ TOKEN(COMMA); }
";"				{ TOKEN(SEMICOLON); }
":"				{ TOKEN(COLON); }
"..."			{ TOKEN(ELLIPSIS); }

"("				{ TOKEN(OPAR); }
")"				{ TOKEN(CPAR); }
"{"|"<%"		{ TOKEN(OCURL); }
"}"|"%>"		{ TOKEN(CCURL); }
"["|"<:"		{ TOKEN(OBRA); }
"]"|":>"		{ TOKEN(CBRA); }

{number}			{ TOKEN_VAL(NUM, text()); }
{STRING_LITERAL}	{ TOKEN_VAL(STRING, text()); }
{ID}				{ TOKEN_VAL(IDENTIFIER, text()); }

. {
	(void)tokens;
	wd.error_get() << "Invalid character: " << yytext[0] << "\n";
}

%%
