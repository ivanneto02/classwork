%{
	#include<stdio.h>
	#include<stdlib.h>
	int num = 0;
%}



DIGIT [0-9]
PLUS \+
MINUS \-
MULT \*
DIV \/
L_PAREN \(
R_PAREN \)
EQUAL \=
NUMBER {DIGIT}+

%%

[ \t]+	{}
{NUMBER}+  {printf("number %s\n", yytext);}
{PLUS}  {printf("plus %s\n", yytext);}
{MINUS} {printf("minus %s\n", yytext);}
{MULT} {printf("mult %s\n", yytext);}
{DIV} {printf("div %s\n", yytext);}
{L_PAREN} {printf("l_paren %s\n", yytext);}
{R_PAREN} {printf("r_paren %s\n", yytext);}
{EQUAL} {printf("equal %s\n", yytext);}
.		{printf("Error\n");}

%%

/*
{DIGIT} {printf("digit\n");}
{DIGIT}*	{printf("=> %s\n", yytext);}
*/

int yywrap(void) {return 1;}

void readFromFile(char*);

int main( int argc, char** argv )
{
    ++argv, --argc;  /* skip over program name */
	char* fileName = argv[0];
	
	printf("%s\n", fileName);
	
	// call defined function
	readFromFile(fileName);
	
    yyin = stdin;
    yylex();
}

void readFromFile(char* inputFile) {
	FILE *fp; // File buffer
	char buff[255]; // Character buffer
	
	fp = fopen(inputFile, "r+");
	yy_switch_to_buffer(
		yy_create_buffer(fp, 255)
	);
}