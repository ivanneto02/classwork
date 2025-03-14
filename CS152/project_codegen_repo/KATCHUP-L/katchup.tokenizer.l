%{
	#include<stdio.h>
	#include<stdlib.h>
	#include "y.tab.h"

	#define RED   "\x1B[31m"
	#define RESET "\x1B[0m"

	int line = 1;
	int col = 1;

    int countNewlines(char* string) {
        int total = 0;
        char* curr = string;
        while (*curr != '\0') {
            if (*curr == '\n') {
                total++;
            }
            curr++;
        }
        return total;
    }

%}

DIGIT [0-9]
INTEGER int
UNSIGNED_INTEGER (whole|whole\ int)
FLOATING_POINT_NUMBER dec
STRING str
STRING_LITERAL \"([^\\"]|\\.)*\"
FUNCTION fun
ENDFUN endfun
ARR arr
OF of
IF if
TAIL tail
IFOTHER if\ other
OTHER other
WHILE while
EXEC exec
WHEN when
CONTINUE continue
SCRATCH scratch
POUNCE pounce
MEOW meow
NOT not
NOT_SYMBOL \!
TRUE True
FALSE False
SWAT swat
SUB \-
ADD \+
MULT \*
DIV \/
MOD %
EQUAL \=
NEQ \!\=
LT \<
GT \>
LTE \<\=
GTE \>\=
IDENT [A-Za-z_][A-Za-z0-9_]*
NUMBER [\-\+]?{DIGIT}+(\.{DIGIT}+)?
COLON \:
SEMICOLON \;
COMMA \,
L_SQUARE_BRACKET \]
R_SQUARE_BRACKET \[
L_CURLY_BRACKET \{
R_CURLY_BRACKET \}
L_PAREN \(
R_PAREN \)
MULTI_LINE_COMMENT \`\`\`([^\`]|\`[^\`]|\`\`[^\`])*\`\`\`
INLINE_COMMENT \`(.*)\`?

%%

[ \t\r]+ {
    col += strlen(yytext);
}
[\n] {
    line++; col = 1;
}
{NUMBER} {
	col += strlen(yytext);
	yylval.ival = atoi(yytext);
	// yylval.dtype = "int"; 
	return NUMBER;
}
{ADD} { col += strlen(yytext); return ADD; }
{SUB} { col += strlen(yytext); return SUB; }
{MULT} { col += strlen(yytext); return MULT;}
{DIV} { col += strlen(yytext); return DIV;}
{MOD} { col += strlen(yytext); return MOD;}
{EQUAL} { col += strlen(yytext); return EQUAL;}
{NEQ} { col += strlen(yytext); return NEQ;}
{LT} { col += strlen(yytext); return LT;}
{GT} { col += strlen(yytext); return GT;}
{LTE} { col += strlen(yytext); return LTE;}
{GTE} { col += strlen(yytext); return GTE;}
{L_PAREN} { col += strlen(yytext); return L_PAREN;}
{R_PAREN} { col += strlen(yytext); return R_PAREN;}
{INTEGER} { col += strlen(yytext); yylval.CodeNode.dtype = "int"; return INTEGER; }
{UNSIGNED_INTEGER} { col += strlen(yytext); yylval.CodeNode.dtype = "whole int"; return UNSIGNED_INTEGER;}
{FLOATING_POINT_NUMBER} { col += strlen(yytext); yylval.CodeNode.dtype = "dec"; return FLOATING_POINT_NUMBER;}
{STRING} { col += strlen(yytext); yylval.CodeNode.dtype = "str"; return STRING;}
{STRING_LITERAL} { col += strlen(yytext); return STRING_LITERAL;}
{FUNCTION} { col += strlen(yytext); return FUNCTION;}
{ENDFUN} {col += strlen(yytext); return ENDFUN;}
{OF} {col += strlen(yytext); return OF;}
{IF} {col += strlen(yytext); return IF;}
{TAIL} {col += strlen(yytext); return TAIL;}
{IFOTHER} {col += strlen(yytext); return IFOTHER;}
{OTHER} {col += strlen(yytext); return OTHER;}
{ARR} {col += strlen(yytext); return ARR;}
{WHILE} {col += strlen(yytext); return WHILE;}
{EXEC} {col += strlen(yytext); return EXEC;}
{WHEN} {col += strlen(yytext); return WHEN;}
{CONTINUE} {col += strlen(yytext); return CONTINUE;}
{SCRATCH} {col += strlen(yytext); return SCRATCH;}
{POUNCE} {col += strlen(yytext); return POUNCE;}
{MEOW} {col += strlen(yytext); return MEOW;}
{NOT} {col += strlen(yytext); return NOT;}
{NOT_SYMBOL} {col += strlen(yytext); return NOT_SYMBOL;}
{TRUE} {col += strlen(yytext); return TRUE;}
{FALSE} {col += strlen(yytext); return FALSE;}
{SWAT} {col += strlen(yytext); return SWAT;}
{IDENT} {col += strlen(yytext); yylval.CodeNode.str = strdup(yytext); return IDENT;}
{SEMICOLON} {col += strlen(yytext); return SEMICOLON;}
{COLON} {col += strlen(yytext); return COLON;}
{COMMA} {col += strlen(yytext); return COMMA;}
{L_SQUARE_BRACKET} {col += strlen(yytext); return L_SQUARE_BRACKET;}
{R_SQUARE_BRACKET} {col += strlen(yytext); return R_SQUARE_BRACKET;}
{L_CURLY_BRACKET} {col += strlen(yytext); return L_CURLY_BRACKET;}
{R_CURLY_BRACKET} {col += strlen(yytext); return R_CURLY_BRACKET;}
{MULTI_LINE_COMMENT} {
	col += strlen(yytext);
	line += countNewlines(yytext);
	return MULTI_LINE_COMMENT;
}
{INLINE_COMMENT} {col += strlen(yytext); return INLINE_COMMENT;}
. {
    exit(1);
}

%%

int yywrap(void) {
	BEGIN(INITIAL);
	yyrestart(yyin);
	return 1;
}

int yyerror(char *s)
{
	if (*s == EOF) { 
		printf("END OF PARSING\n"); 
	}
  	else {
		printf(RED "Error[%s] at line %d, col %d\n" RESET, s, line, col);
		exit(1);
	}
}