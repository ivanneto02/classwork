%{
	#include<stdio.h>
	#include<stdlib.h>
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
INIDENT ([0-9\_]+{IDENT}*\_?|({IDENT}[0-9\_]?)+{IDENT}*_)
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
STRING_LITERAL \"([^\\"]|\\.)*\"

%%

[ \t\r]+ {
    col += strlen(yytext);
}
[\n] {
    line++; col = 1;
}
{NUMBER} {
    printf("NUMBER %s\n", yytext);
    col += strlen(yytext);
}
{ADD} {
    printf("PLUS\n");
    col += strlen(yytext);
}
{SUB} {
    printf("MINUS\n");
    col += strlen(yytext);
}
{MULT} {
    printf("MULT\n");
    col += strlen(yytext);
}
{DIV} {
    printf("DIV\n");
    col += strlen(yytext);
}
{MOD} {
    printf("MOD\n");
    col += strlen(yytext);
}
{EQUAL} {
    printf("EQ\n");
    col += strlen(yytext);
}
{NEQ} {
    printf("NEQ\n");
    col += strlen(yytext);
}
{LT} {
    printf("LT\n");
    col += strlen(yytext);
}
{GT} {
    printf("GT\n");
    col += strlen(yytext);
}
{LTE} {
    printf("LTE\n");
    col += strlen(yytext);
}
{GTE} {
    printf("GTE\n");
    col += strlen(yytext);
}
{L_PAREN} {
    printf("L_PAREN\n");
    col += strlen(yytext);
}
{R_PAREN} {
    printf("R_PAREN\n");
    col += strlen(yytext);
}
{INTEGER} {
    printf("INTEGER\n");
    col += strlen(yytext);
}
{UNSIGNED_INTEGER} {
    printf("UNSIGNED_INTEGER\n");
    col += strlen(yytext);
}
{FLOATING_POINT_NUMBER} {
    printf("FLOATING_POINT_NUMBER\n");
    col += strlen(yytext);
}
{STRING} {
    printf("STRING\n");
    col += strlen(yytext);
}
{FUNCTION} {
    printf("FUNCTION\n");
    col += strlen(yytext);
}
{ENDFUN} {
    printf("ENDFUN\n");
    col += strlen(yytext);
}
{OF} {
    printf("OF\n");
    col += strlen(yytext);
}
{IF} {
    printf("IF\n");
    col += strlen(yytext);
}
{TAIL} {
    printf("TAIL\n");
    col += strlen(yytext);
}
{IFOTHER} {
    printf("IFOTHER\n");
    col += strlen(yytext);
}
{WHILE} {
    printf("WHILE\n");
    col += strlen(yytext);
}
{EXEC} {
    printf("EXEC\n");
    col += strlen(yytext);
}
{CONTINUE} {
    printf("CONTINUE\n");
    col += strlen(yytext);
}
{SCRATCH} {
    printf("SCRATCH\n");
    col += strlen(yytext);
}
{POUNCE} {
    printf("POUNCE\n");
    col += strlen(yytext);
}
{MEOW} {
    printf("MEOW\n");
    col += strlen(yytext);
}
{NOT} {
    printf("NOT\n");
    col += strlen(yytext);
}
{TRUE} {
    printf("TRUE\n");
    col += strlen(yytext);
}
{FALSE} {
    printf("FALSE\n");
    col += strlen(yytext);
}
{SWAT} {
    printf("SWAT\n");
    col += strlen(yytext);
}
{IDENT} {
    printf("IDENT %s\n", yytext);
    col += strlen(yytext);
}
{INIDENT} {
    printf("Error at line %i, column %i: invalid token \"%s\"\n",
           line, col, yytext);
    exit(1);
}
{SEMICOLON} {
    printf("SEMICOLON\n");
    col += strlen(yytext);
}
{COLON} {
    printf("COLON\n");
    col += strlen(yytext);
}
{COMMA} {
    printf("COMMA\n");
    col += strlen(yytext);
}
{L_SQUARE_BRACKET} {
    printf("L_SQUARE_BRACKET\n");
    col += strlen(yytext);
}
{R_SQUARE_BRACKET} {
    printf("R_SQUARE_BRACKET\n");
    col += strlen(yytext);
}
{MULTI_LINE_COMMENT} {
    printf("MULTI_LINE_COMMENT\n");
    line += countNewlines(yytext);
    col += strlen(yytext);
}
{INLINE_COMMENT} {
    printf("INLINE_COMMENT\n");
    col += strlen(yytext);
}
{STRING_LITERAL} {
    printf("STRING_LITERAL\n");
    col += strlen(yytext);
}
. {
    printf("Error at line %i, column %i: unrecognized symbol \"%s\"\n",
           line, col, yytext);
    exit(1);
}

%%

int yywrap(void) {return 1;}

void readFromFile(char*);
int countNewlines(char*);

int validExt(char* fname) {
    const char ch = '.';
    char* ret; // pointer to place in string
    ret = strchr(fname, ch) + 1; // ret is not pointer to position
    if (strcmp(ret, "katc") == 0) {
        return 1;
    }
    return 0;
}

int main( int argc, char **argv)
{
    ++argv, --argc;  /* skip over program name */
    char* fileName = argv[0];

    printf("Reading from file: \"%s\"\n\n", fileName);

    // Find file extension and make sure it is katc
    if (validExt(fileName) == 0) {
        printf("Error: Incorrect file extension in \"%s\"\n\n", fileName);
        exit(-1);
    }
    
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
