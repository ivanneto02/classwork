%{
	#include<stdio.h>
	#include<stdlib.h>
	#include "y.tab.h"
	#define yyterminate() return END
%}

DIGIT [0-9]
NUMBER (\-)?{DIGIT}+
PLUS \+
MINUS \-
MULT \*
DIV \/
L_PAREN \(
R_PAREN \)
EQUAL \=
MOD \%
STRING [^\-][a-zA-Z]+

%%

[ \t\r\n]+	{}
{NUMBER} { yylval.integer = yytext; return NUMBER; }
{STRING} { return STRING; }
{PLUS} { return PLUS; }
{MINUS} { return MINUS; }
{MULT} { return MULT; }
{MOD} { return MOD; }
{DIV} { return DIV; }
{L_PAREN} { return L_PAREN; }
{R_PAREN} { return R_PAREN; }
{EQUAL} { return EQUAL; }
<<EOF>> {
	yyterminate();
	yy_delete_buffer(YY_CURRENT_BUFFER);
	yyrestart(yyin);
}
.		{ printf("Error\n"); }

%%

int yywrap(void) {
	BEGIN(INITIAL);
	yyrestart(yyin);
	return 1;
}

