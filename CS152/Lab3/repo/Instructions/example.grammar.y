/* simplest version of calculator */
%{
#include <stdio.h>
#include <string.h>
char* mycont(char* a, char* b);
%}

%union {
    char *str;
}
/* declare tokens */
%token NUMBER
%token STRING
%token EOL
%token END
%type<str> exp term NUMBER STRING

%%


calclist: /* nothing */                       
 | calclist exp EOL { printf("= %s\n", $2);} 
 ;

exp: term     
 | exp term  { $$ = mycont($1,$2); }
 ;
 
term: NUMBER 
 | STRING
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
