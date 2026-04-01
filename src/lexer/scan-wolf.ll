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
// TODO #define YY_USER_ACTION td.location_ += size();


#define TOKEN(Type)                             \
  lexer::make_ ## Type(td.location_)

#define TOKEN_VAL(Type, Value)                  \
  lexer::make_ ## Type(Value, td.location_)


%}


%class {
	unsigned line;
	unsigned col;
}

%init {
	line = 0;
	col = 0;
}

/* Abbreviations.  */
int             [0-9]+
ID [a-zA-Z][a-zA-Z0-9_]*
RESERVED_ID _[a-zA-Z0-9_]*
BLANK [ \t\v]
STRING_LITERAL "\"".*"\""

%%

. {
	(void)tokens;
	wd.error_get() << "Invalid character: " << yytext[0] << "\n";
	std::cout << yytext[0] << "\n";
}

%%
