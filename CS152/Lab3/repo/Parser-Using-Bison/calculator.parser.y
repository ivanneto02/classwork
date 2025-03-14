/* simplest version of calculator */
%{
#include <stdio.h>
#include <string.h>
char* mycont(char* a, char* b);
int yylex(void);
int yyerror(char* s);
%}

%union {
    char *str;
	int integer;
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
%type<integer> mulexp exp term NUMBER STRING DIGIT LETTER PLUS MINUS MULT DIV L_PAREN R_PAREN EQUAL MOD

%%

calclist: /* nothing */                       
 | calclist exp EQUAL {} 
 ;
 
mulop: MULT
| DIV
| MOD
;

exp: exp addop mulexp {$$ = $1 + $3; }
 | mulexp {$$ = $1; }
 ;

mulexp: mulexp mulop term { $$ = $1 * $3; }
 | term { $$ = $1; }
 ;
 
term: L_PAREN exp R_PAREN
| NUMBER { $$ = $1; }
;
 
addop: PLUS
| MINUS
;

%%

char* mycont(char* a, char* b){
	strcat(a,b);
	return a;
}

int main(int argc, char **argv)
{
	yyparse();
	return 0;
}

int yyerror(char *s)
{
  fprintf(stderr, "error: %s\n", s);
}
