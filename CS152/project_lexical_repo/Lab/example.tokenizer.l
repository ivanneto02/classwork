%{
	#include<stdio.h>
	#include<stdlib.h>
	int num = 0;
    int oper = 0;
    int paren = 0; 
    int equ = 0; 
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
{NUMBER} {printf("Number\n");  num++; }
{PLUS} { printf("Plus\n"); oper++;}
{MINUS} { printf("Minus\n"); oper++;}
{MULT} {printf("Multiplication\n"); oper++;}
{DIV} {printf("Division\n"); oper++;}
{L_PAREN} {printf("Left parenthesis\n"); paren++;}
{R_PAREN} {printf("Right parenthesis\n"); paren++;}
{EQUAL} {printf("Equal sign\n"); equ++; }

.		{printf("Error\n");}

%%

int yywrap(void) {return 1;}

void readFromFile(char*);

int main( int argc, char **argv)
{
    ++argv, --argc;  /* skip over program name */
    char* fileName = argv[0];

    printf("%s\n", fileName);

    // call defined function
    readFromFile(fileName);

    yyin = stdin;
    yylex();

    printf("Integers: %d", num);
    printf("Operators: %d", oper);
    printf("Parentheses: %d", paren);
    printf("Equal signs: %d", equ);
}

void readFromFile(char* inputFile) {
	FILE *fp; // File buffer
	char buff[255]; // Character buffer
	
	fp = fopen(inputFile, "r+");
	yy_switch_to_buffer(
		yy_create_buffer(fp, 255)
	);
}
