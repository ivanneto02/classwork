/* simplest version of calculator */
%{
#include <stdio.h>
#include <string.h>
char* mycont(char* a, char* b);
int yylex(void);
int yyerror(char* s);
typedef struct yy_buffer_state *YY_BUFFER_STATE;
void yy_switch_to_buffer(struct yy_buffer_state *new_buffer);
struct yy_buffer_state* yy_create_buffer( FILE *file, int size );
%}

%union {
    char *str;
}

/* declare tokens */
%token STRING
%token END
%token DIGIT
%token LETTER
%token NUMBER
%token PLUS
%token MINUS
%token MULT
%token DIV
%token L_PAREN
%token R_PAREN
%token EQUAL
%token MOD
%type<str> exp mulexp term NUMBER STRING DIGIT LETTER PLUS MINUS MULT DIV L_PAREN R_PAREN EQUAL MOD

%%

calclist: /* nothing */                       
 | calclist exp EQUAL {
    printf("= %s\n", $2); // only prints first token of exp
        
} 
 ;
 
mulop: MULT
| DIV
| MOD
;

exp: exp addop mulexp
 | mulexp
 ;

mulexp: mulexp mulop term
 | term
 ;
 
term: L_PAREN exp R_PAREN
| NUMBER
;
 
addop: PLUS
| MINUS
;

%%

char* mycont(char* a, char* b){
	strcat(a,b);
	return a;
}

void readFromFile(char*);

int main(int argc, char **argv)
{
	if (argc > 1) {
		char* fileName = argv[1];

		printf("Reading from file: \"%s\"\n\n", fileName);

		// call defined function
		readFromFile(fileName);
		
	} 
	yyparse();
	
	return 0;
}

int yyerror(char *s)
{
  fprintf(stderr, "error: %s\n", s);
}

void readFromFile(char* inputFile) {

	FILE *fp; // File object
	fp = fopen(inputFile, "r+");

	yy_switch_to_buffer(
        yy_create_buffer(fp, 255)
    );

}