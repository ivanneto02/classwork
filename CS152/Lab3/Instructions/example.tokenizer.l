%{
	#include<stdio.h>
	#include<stdlib.h>
	#include"example.grammar.tab.h"
	#define yyterminate() return END
	int num = 0;
%}


DIGIT [0-9]
LETTER [a-zA-Z]




%%



[ \t]+	{}
\n {BEGIN(INITIAL); return EOL;}
{DIGIT}*	{printf("=> %s\n", yytext); yylval.str =yytext; return NUMBER;}
{LETTER}*	{printf("string: %s\n", yytext); yylval.str=yytext; return STRING;}
<<EOF>> {yyterminate(); yy_delete_buffer(YY_CURRENT_BUFFER); yyrestart(yyin);}
.		{printf("Error\n");}

%%
int yywrap(void) {BEGIN(INITIAL); yyrestart(yyin); return 1;}

