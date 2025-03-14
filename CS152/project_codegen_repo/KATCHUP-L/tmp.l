%{
    #include<stdio.h>
    #include<stdlib.h>
    #include "y.tab.h"
	#define yyterminate() return END
%}

DIGIT [0-9]
INTEGER int
UNSIGNED_INTEGER whole
FLOATING_POINT_NUMBER dec
STRING str
FUNCTION fun
ENDFUN endfun
OF of
IF if
TAIL tail
IFOTHER if\ other
WHILE while
EXEC exec
CONTINUE continue
SCRATCH scratch
POUNCE pounce
MEOW meow
NOT not
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
L_SQUARE_BRACKET \{
R_SQUARE_BRACKET \}
L_PAREN \(
R_PAREN \)
MULTI_LINE_COMMENT \`\`\`([^\`]|\`[^\`]|\`\`[^\`])*\`\`\`
INLINE_COMMENT \`(.*)\`?

%%

[ \t\n\r]+ {}
{NUMBER} {printf("NUMBER %s\n", yytext);}
{ADD} {printf("PLUS\n");}
{SUB} {printf("MINUS\n");}
{MULT} {printf("MULT\n");}
{DIV} {printf("DIV\n");}
{MOD} {printf("MOD\n");}
{EQUAL} {printf("EQ\n");}
{NEQ} {printf("NEQ\n");}
{LT} {printf("LT\n");}
{GT} {printf("GT\n");}
{LTE} {printf("LTE\n");}
{GTE} {printf("GTE\n");}
{L_PAREN} {printf("L_PAREN\n");}
{R_PAREN} {printf("R_PAREN\n");}
{INTEGER} {printf("INTEGER\n");}
{UNSIGNED_INTEGER} {printf("UNSIGNED_INTEGER\n");}
{FLOATING_POINT_NUMBER} {printf("FLOATING_POINT_NUMBER\n");}
{STRING} {printf("STRING\n");}
{FUNCTION} {printf("FUNCTION\n");}
{ENDFUN} {printf("ENDFUN\n");}
{OF} {printf("OF\n");}
{IF} {printf("IF\n");}
{TAIL} {printf("TAIL\n");}
{IFOTHER} {printf("IFOTHER\n");}
{WHILE} {printf("WHILE\n");}
{EXEC} {printf("EXEC\n");}
{CONTINUE} {printf("CONTINUE\n");}
{SCRATCH} {printf("SCRATCH\n");}
{POUNCE} {printf("POUNCE\n");}
{MEOW} {printf("MEOW\n");}
{NOT} {printf("NOT\n");}
{TRUE} {printf("TRUE\n");}
{FALSE} {printf("FALSE\n");}
{SWAT} {printf("SWAT\n");}
{IDENT} {printf("IDENT %s\n", yytext);}
{SEMICOLON} {printf("SEMICOLON\n");}
{COLON} {printf("COLON\n");}
{COMMA} {printf("COMMA\n");}
{L_SQUARE_BRACKET} {printf("L_SQUARE_BRACKET\n");}
{R_SQUARE_BRACKET} {printf("R_SQUARE_BRACKET\n");}
{MULTI_LINE_COMMENT} {printf("MULTI_LINE_COMMENT\n");}
{INLINE_COMMENT} {printf("INLINE_COMMENT\n");}
. {printf("Error\n");}

%%

int yywrap(void) {return 1;}

void readFromFile(char*);

int main( int argc, char **argv)
{
    ++argv, --argc;  /* skip over program name */
    char* fileName = argv[0];

    printf("Reading from file: \"%s\"\n\n", fileName);

    // call defined function
    readFromFile(fileName);

    yyin = stdin;
    yylex();
}

void readFromFile(char* inputFile) {

        FILE *fp; // File object
        fp = fopen(inputFile, "r+");

        yy_switch_to_buffer(
        yy_create_buffer(fp, 255)
    );
}