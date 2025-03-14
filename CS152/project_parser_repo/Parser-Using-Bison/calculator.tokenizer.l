%{
	#include<stdio.h>
	#include<stdlib.h>
	#include "y.tab.h"
	#define yyterminate() return END
%}

DIGIT [0-9]
NUMBER (\-)?{DIGIT}+(\.{DIGIT}+)?(E[-+]?{DIGIT}+)?
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
{NUMBER} { yylval.str = strdup(yytext); return NUMBER; }
{STRING} { yylval.str = strdup(yytext); return STRING; }
{PLUS} { yylval.str = strdup(yytext); return PLUS; }
{MINUS} { yylval.str = strdup(yytext); return MINUS; }
{MULT} { yylval.str = strdup(yytext); return MULT; }
{MOD} { yylval.str = strdup(yytext); return MOD; }
{DIV} { yylval.str = strdup(yytext); return DIV; }
{L_PAREN} { yylval.str = strdup(yytext); return L_PAREN; }
{R_PAREN} { yylval.str = strdup(yytext); return R_PAREN; }
{EQUAL} { yylval.str = strdup(yytext); return EQUAL; }
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

