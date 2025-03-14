/* 
	Credit for symbol table:
		https://book.huihoo.com/compiler-construction-using-flex-and-bison/Context.html
*/
%{
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#include "ST.h"
	#include "test.h"
	#include "various_checks.h"
	#define YYDEBUG 1

	char* mycont(char* a, char* b);
	int yylex(void);
	
	typedef struct yy_buffer_state *YY_BUFFER_STATE;
	void yy_switch_to_buffer(struct yy_buffer_state *new_buffer);
	struct yy_buffer_state* yy_create_buffer( FILE *file, int size );
	#define yyterminate() return END
	
	// void context_check( char* );
%}

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

%union {
	
	int ival;
	float fval;
	char* str;

	struct {
		int ival;
		float fval;
		char *dtype; 
		char *str; 
		char *name; 
    	struct CodeNode *next; 
	} CodeNode; 

}

%type<str> FUNCTION ENDFUN OF IF TAIL IFOTHER OTHER WHILE EXEC WHEN CONTINUE SCRATCH
%type<str> POUNCE MEOW NOT TRUE FALSE SWAT MULTI_LINE_COMMENT INLINE_COMMENT ARR
%type<CodeNode> data-type IDENT INTEGER UNSIGNED_INTEGER FLOATING_POINT_NUMBER STRING literal addit-op
%type<CodeNode> expression DIGIT mulexp term bool NUMBER mulop comp array-args
%%

program:
| statement program 
| function program
;

statement: if-statement
| while-statement
| exec-when-statement
| expression SEMICOLON {
	// printf("exp");
}
| declaration SEMICOLON
| IDENT COLON literal SEMICOLON {
	// printf("%s: -%s-, -%s-\n", $1.str, $1.dtype, $3.dtype);
	context_check($1.str, $3.dtype); /*printf("\tstmt init %s, %s\n", $1.str, $1.dtype);*/
}
| array-call COLON literal SEMICOLON
| comment
| array-dec SEMICOLON
| SCRATCH SEMICOLON
| SWAT literal SEMICOLON
;

literal: expression { $$.dtype = $1.dtype; } 
| STRING_LITERAL { $$.dtype = "str"; }
;

if-statement: IF L_PAREN expression R_PAREN COLON program if-other-statements TAIL SEMICOLON
;

if-other-statements: OTHER L_PAREN expression R_PAREN COLON program if-other-statements
| OTHER COLON program
|
;

while-statement: WHILE L_PAREN expression R_PAREN COLON program TAIL SEMICOLON
;

exec-when-statement: EXEC COLON program WHEN L_PAREN expression R_PAREN  SEMICOLON
;

array-dec: ARR L_CURLY_BRACKET literal R_CURLY_BRACKET IDENT COLON L_CURLY_BRACKET array-args R_CURLY_BRACKET {
	// printf("array-dec123\n");
	// printf("%s, %s", $5.dtype, $8.dtype);
	check_array_size($3.ival, $8.ival);
	$5.dtype = $8.dtype;
	install($5.str, $5.dtype);
}
| ARR L_CURLY_BRACKET literal R_CURLY_BRACKET IDENT {
	install($5.str, $5.dtype);
}
;

array-args: literal COMMA array-args {
	$$.dtype = $1.dtype;
	$$.ival = 1 + $3.ival;
}
| literal {
	$$.ival = 1;
}
;

array-call: IDENT L_CURLY_BRACKET literal R_CURLY_BRACKET {
	context_check($1.str, $1.dtype);
}
;

expression: mulexp addit-op expression {
	if ($2.str == "+") {
		// printf("%s\n", $2);
		$$.ival = $1.ival + $3.ival;
	}
	else if ($2.str == "-") {
		$$.ival = $1.ival - $3.ival;
	}
	else if ($2.str == "=") {
		$$.ival = ($1.ival == $3.ival); 
	}
	else if ($2.str == "<=") {
		$$.ival = ($1.ival <= $3.ival);
	}
	else if ($2.str == ">=") {
		$$.ival = ($1.ival >= $3.ival);
	}
	else if ($2.str == "<") {
		$$.ival = ($1.ival < $3.ival);
	}
	else if ($2.str == ">") {
		$$.ival = ($1.ival > $3.ival);
	}
	else if ($2.str == "!=") {
		$$.ival = ($1.ival != $3.ival);
	}
	else {
		// printf("expression here");
		$$.ival = 0;
	}

	$$.dtype = "int";
}
| mulexp { $$.dtype = "int"; $$.ival = $1.ival; }
| not L_PAREN expression R_PAREN { $$.ival = -(1) * $3.ival; }
;

mulexp: term mulop mulexp {
	if ($2.str == "*") {
		$$.ival = $1.ival * $3.ival;
	}
	else if ($2.str == "/") {
		$$.ival = $1.ival / $3.ival;
	}
	else if ($2.str == "%") {
		$$.ival = $1.ival % $3.ival;
	}
	else {
		// printf("mulexp here");
		$$.ival = 0;
	}
}
| term { $$.ival = $1.ival; }
;

addit-op: ADD { $$.str = "+"; }
| SUB { $$.str = "-"; }
| comp { $$.str = $1.str; }
;

mulop: MULT { $$.str = "*"; }
| DIV { $$.str = "/"; }
| MOD { $$.str = "%"; }
;

term: IDENT {
	// printf("\t ident %s: %s\n", $1.str, $1.dtype);
	// printf("context check\n");
	// printf("> %s\n", $1.str);
	// testPassObject($1);
	context_check($1.str, getdtype($1.str));
}
| NUMBER {
	$$.ival = $1.ival;
}
| bool
| L_PAREN expression R_PAREN { $$.ival = $2.ival; }
| func-call { $$.ival = 0; }
| array-call { $$.ival = 0; }
;

comp: EQUAL { $$.str = "="; }
| LTE { $$.str = "<="; }
| GTE { $$.str = ">="; }
| LT  { $$.str = "<";  }
| GT  { $$.str = ">";  }
| NEQ { $$.str = "!="; }
;

bool: TRUE { $$.ival = 1; }
| FALSE { $$.ival = 0; }
;

not: NOT
| NOT_SYMBOL
;

function: FUNCTION IDENT L_PAREN func-params R_PAREN COLON program ENDFUN SEMICOLON
{
	$2.dtype = "function";
	install($2.str, $2.dtype);
}
;

func-call: IDENT L_PAREN func-args R_PAREN {
	context_check($1.str, getdtype($1.str));
}
| MEOW L_PAREN func-args R_PAREN
| POUNCE L_PAREN IDENT R_PAREN {
	context_check($3.str, getdtype($3.str));
}
| POUNCE L_PAREN array-call R_PAREN
;

func-args: literal COMMA func-args
| literal
;

data-type: INTEGER  		{/*printf("integer\n");*/ $$.dtype = $1.dtype; }
| UNSIGNED_INTEGER  		{/*printf("unsigned integer\n");*/ $$.dtype = $1.dtype;}
| FLOATING_POINT_NUMBER  	{/*printf("float\n");*/ $$.dtype = $1.dtype;}
| STRING 					{/*printf("string\n");*/ $$.dtype = $1.dtype;}
;

func-params: declaration COMMA func-params
| declaration
;

declaration: data-type IDENT {
	$2.dtype = $1.dtype;
	install($2.str, $2.dtype);
	// printf("decl: %s %s\n", $2.str, $2.dtype);
}
| data-type IDENT COLON literal {
	$2.dtype = $1.dtype;
	check_dtypes($1.dtype, $4.dtype);
	install($2.str, $2.dtype);
	// printf("decl/init: %s %s\n", $2.str, $2.dtype);
}
;

comment: INLINE_COMMENT
| MULTI_LINE_COMMENT
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