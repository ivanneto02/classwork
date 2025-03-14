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
	#define yyterminate() return END
	
%}

%union {
    char *str;
	int val;
}

/* declare tokens */
%token END
%token DIGIT
%token INTEGER
%token UNSIGNED_INTEGER
%token FLOATING_POINT_NUMBER
%token STRING
%token STRING_LITERAL
%token FUNCTION
%token ENDFUN
%token OF
%token IF
%token TAIL
%token IFOTHER
%token OTHER
%token WHILE
%token EXEC
%token WHEN
%token CONTINUE
%token SCRATCH
%token POUNCE
%token MEOW
%token NOT
%token NOT_SYMBOL
%token TRUE
%token FALSE
%token SWAT
%token SUB
%token ADD
%token MULT
%token DIV
%token MOD
%token EQUAL
%token NEQ
%token LT
%token GT
%token LTE
%token GTE
%token IDENT
%token NUMBER
%token COLON
%token SEMICOLON
%token COMMA
%token L_SQUARE_BRACKET
%token R_SQUARE_BRACKET
%token L_PAREN
%token R_PAREN
%token MULTI_LINE_COMMENT
%token INLINE_COMMENT
%token L_CURLY_BRACKET
%token R_CURLY_BRACKET
%token ARR

%type<str> STRING FUNCTION ENDFUN OF IF TAIL IFOTHER OTHER WHILE EXEC WHEN CONTINUE SCRATCH
%type<str> POUNCE MEOW NOT TRUE FALSE SWAT IDENT MULTI_LINE_COMMENT INLINE_COMMENT ARR
%type<val> DIGIT NUMBER 

%%

program: {printf("program -> ε\n");}
| statement program { printf("program -> statement program\n"); }
| function program { printf("program -> function program\n"); }
;

statement: if-statement { printf("statement -> if-statement\n"); }
| while-statement { printf("statement -> while-statement\n"); }
| exec-when-statement { printf("statement -> exec-when-statement\n"); }
| expression SEMICOLON { printf("statement -> expression ;\n"); }
| data-type variable COLON literal SEMICOLON {printf("statement -> data-type var : exp;\n"); }
| data-type variable SEMICOLON {printf("statement -> data-type var ;\n"); }
| variable COLON literal {printf("statement -> variable : literal ;\n"); }
| comment { printf("statement -> comment\n"); }
| func-call SEMICOLON { printf("statement -> func-call ;\n"); }
| array-dec SEMICOLON { printf("statement -> array-dec;\n"); }
| data-type variable COLON array-call SEMICOLON { printf("common--statement -> data-type variable : array-call\n"); }
| SCRATCH SEMICOLON { printf("statement -> scratch ;\n"); }
| SWAT literal SEMICOLON { printf("statement -> swat literal;\n"); }
;

literal: expression
| STRING_LITERAL
;

if-statement: IF L_PAREN bool-exp R_PAREN COLON program if-other-statements TAIL SEMICOLON
  { printf("if-statement -> if ( bool-exp ): program if-other-statements tail ;\n"); }
;

if-other-statements: OTHER L_PAREN bool-exp R_PAREN COLON program if-other-statements
  { printf("if-other-statements -> other ( bool-exp ): program if-other-statements\n"); }
| OTHER COLON program
  { printf("if-other-statements -> other: program \n"); }
| 
  { printf("if-other-statements -> ε\n"); }
;


while-statement: WHILE L_PAREN bool-exp R_PAREN COLON program TAIL SEMICOLON
  { printf("while-statement -> while ( bool-exp ): program tail ;\n"); }
;

exec-when-statement: EXEC COLON program WHEN  L_PAREN bool-exp R_PAREN  SEMICOLON
  { printf("exec-when-statement -> exec: program when (bool-exp);\n"); }
;


array-dec: ARR L_CURLY_BRACKET literal R_CURLY_BRACKET IDENT COLON L_CURLY_BRACKET array-args R_CURLY_BRACKET
;

array-args: literal COMMA array-args
| literal
;

array-call: IDENT L_CURLY_BRACKET literal R_CURLY_BRACKET
;


expression: mulexp addit-op expression { printf("expression -> mulexp addit-op expression\n"); }
| mulexp { printf("expression -> mulexp\n"); }
;

addit-op: ADD { printf("addit-op -> +\n"); }
| SUB { printf("addit-op -> -\n"); }
;

mulexp: term mulop mulexp { printf("mulexp -> term mulop mulexp\n"); }
| term { printf("mulexp -> term\n"); }
;

mulop: MULT { printf("mulop -> *\n"); }
| DIV { printf("mulop -> \\\n"); }
| MOD { printf("mulop -> mod\n"); }
;

term: variable { printf("term -> variable\n"); }
| NUMBER { printf("term -> number\n"); }
| L_PAREN expression R_PAREN { printf("term -> ( expression )\n"); }
| bool-exp { printf("term -> bool-exp \n"); }
;

variable: IDENT { printf("variable -> IDENT \n"); }
| IDENT L_SQUARE_BRACKET expression R_SQUARE_BRACKET { printf("variable -> IDENT [ exp ] \n"); }
;

comp: EQUAL { printf("comp -> = \n"); }
| LTE { printf("comp -> <= \n"); }
| GTE { printf("comp -> >= \n"); }
| LT { printf("comp -> < \n"); }
| GT { printf("comp -> > \n"); }
| NEQ { printf("comp -> != \n"); }
;

bool-exp: TRUE { printf("bool-exp -> True \n"); }
| FALSE { printf("bool-exp -> False \n"); }
| not bool-exp { printf("bool-exp -> not bool-exp \n"); }
| not L_PAREN bool-exp R_PAREN { printf("bool-exp -> not ( bool-exp ) \n"); }
| expression comp expression { printf("bool-exp -> exp comp exp \n"); }
;

not: NOT { printf("not -> \"not\" \n"); }
| NOT_SYMBOL { printf("not -> \"!\" \n"); }
;


function: FUNCTION IDENT L_PAREN func-params R_PAREN COLON program ENDFUN SEMICOLON { printf("function -> fun identifier ( params ): program endfun ; \n"); }
;

func-call: IDENT L_PAREN func-args R_PAREN { printf("func-call -> IDENT ( func-args ) ;\n"); }
| MEOW L_PAREN literal R_PAREN { printf("func-call -> meow ( literal ) ;\n"); }
;

func-args: literal COMMA func-args { printf("func-args -> literal, func-args\n"); }
| literal { printf("func-args -> literal\n"); }
;

data-type: INTEGER { printf("data-type -> int\n"); }
| UNSIGNED_INTEGER { printf("data-type -> whole\n"); }
| FLOATING_POINT_NUMBER { printf("data-type -> dec\n"); }
| STRING { printf("data-type -> str\n"); }
;

func-params: declaration COMMA func-params { printf("func-params -> declarations , funct-params\n"); }
| declaration { printf("func-params -> declaration\n"); }
;

declaration: data-type IDENT { printf("declaration -> data-type IDENT\n"); }
| data-type IDENT COLON literal { printf("declaration -> data-type IDENT : literal ;\n"); }
;

comment: INLINE_COMMENT { printf("comment -> INLINE-COMMENT ;\n"); }
| MULTI_LINE_COMMENT { printf("comment -> MULTI_LINE_COMMENT ;\n"); }
;

%%

/*

// TODO: exec-while instead of exec-when
// not (1 < 3) versus not 1 < 3
// allow swat inside loop inside function definition

statement:
if-statement
| while-statement
| exec-when-statement
| other-statement
| expression
;

fun-statement:

;

other-statement:

;

comp: EQUAL
| LTE
| GTE
| LT
| GT
| NEQ
;

bool-exp: NOT bool-exp
| expression comp expression
;


*/

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

	printf("START OF PARSING\n");
	yyparse();
	printf("FINISHED!\n");
	

	return 0;
}     

void readFromFile(char* inputFile) {

	FILE *fp; // File object
	fp = fopen(inputFile, "r+");
	printf("\"%s\" opened\n", inputFile);
	
	yy_switch_to_buffer(
        yy_create_buffer(fp, 255)
    );
	
}