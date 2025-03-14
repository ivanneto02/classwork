#ifndef __ST_H__
#define __ST_H__

int yyerror(char* s);

struct CodeNode
{
    int ival;
    char *dtype; 
    char *str; 
    char *name; 
    struct CodeNode *next; 
};           

typedef struct CodeNode CodeNode;
CodeNode *sym_table = (CodeNode *)0;
CodeNode *putsym ();
CodeNode *getsym ();

CodeNode * putsym ( char* sym_name, char* dtype )
{
    CodeNode *ptr;
    ptr = (CodeNode *) malloc (sizeof(CodeNode));
    ptr->str = (char*) malloc (strlen(sym_name) + 1);
    ptr->dtype = (char*) malloc (strlen(dtype) + 1);

    strcpy (ptr->str, sym_name);
    strcpy (ptr->dtype, dtype);

    // printf("putting: %s, %s\n", ptr->str, ptr->dtype);

    ptr->next = (struct CodeNode *)sym_table;
    sym_table = ptr;
    return ptr;
}

CodeNode * getsym ( char *sym_name, char* dtype )
{
    CodeNode *ptr;
    for (ptr = sym_table; ptr != (CodeNode *) 0; ptr = (CodeNode *)ptr->next) {
        // printf("== %s, %s | %s, %s\n", ptr->str, ptr->dtype, sym_name, dtype);
        int same_name = strcmp (ptr->str, sym_name);
        int same_type = strcmp (ptr->dtype, dtype);
        if ((same_name == 0) && (same_type == 0)) {
        //     printf("%s, %s, %s", ptr->str, ptr->name, ptr->dtype);
        //     printf("-\n");
            return ptr;
        }
    }
    // printf("-\n");
    return 0;
}

// Unknown data type
CodeNode * getsymU ( char *sym_name )
{
    CodeNode *ptr;
    for (ptr = sym_table; ptr != (CodeNode *) 0; ptr = (CodeNode *)ptr->next) {
        // printf("== %s | %s\n", ptr->str, sym_name);
        int same_name = strcmp (ptr->str, sym_name);
        if (same_name == 0) {
        //     printf("%s, %s, %s", ptr->str, ptr->name, ptr->dtype);
        //     printf("-\n");
            return ptr;
        }
    }
    printf("-\n");
    return 0;
}

char* getdtype(char* sym_name) {
    CodeNode* ptr = getsymU(sym_name);
	if (ptr == 0) {
		yyerror("Semantic Error");
	}
    // printf("<<%s, %s>>\n", ptr->str, ptr->dtype);
    return ptr->dtype;
}

void install ( char *sym_name, char* dtype) {
		// printf("here\n");
		// printf("%s\n", sym_name);
        // printf("Installing...\n");

		CodeNode *s;
		s = getsym (sym_name, dtype);
		if (s == 0) {
            s = putsym (sym_name, dtype);
		}
		else {
			yyerror("Semantic Error");
			// printf( "%s is already defined\n", sym_name );
		}
	}

// Unknown data type
void context_checkU(char* sym_name) {
    if ( getsymU( sym_name ) == 0) {
        yyerror("Semantic Error");
    }
}

// Known data type
void context_check( char* sym_name, char* dtype ) {
    if ( getsym( sym_name, dtype ) == 0 ) {
        yyerror("Semantic Error");
    }
}

#endif