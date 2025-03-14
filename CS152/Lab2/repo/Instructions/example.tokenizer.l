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
{NUMBER}\n {printf("Number\n");  num++; }
{PLUS}\n { printf("Plus\n"); oper++;}
{MINUS}\n { printf("Minus\n"); oper++;}
{MULT}\n {printf("Multiplication\n"); oper++;}
{DIV}\n {printf("Division\n"); oper++;}
{L_PAREN}\n {printf("Left parenthesis\n"); paren++;}
{R_PAREN}\n {printf("Right parenthesis\n"); paren++;}
{EQUAL}\n {printf("Equal sign\n"); equ++; }

.		{printf("Error\n");}

%%

/*


{EXPRESSION}{EQUAL}\n {printf("number\n, yytext); }
{DIGIT} {printf("digit\n");}
{DIGIT}*	{printf("=> %s\n", yytext);}
*/

int yywrap(void) {return 1;}

int main( int argc, char **argv)
{
    ++argv, --argc;  /* skip over program name */
    yyin = stdin;
    yylex();

    printf("Integers: %d", num);
    printf("Operators: %d", oper);
    printf("Parentheses: %d", paren);
    printf("Equal signs: %d", equ);
}