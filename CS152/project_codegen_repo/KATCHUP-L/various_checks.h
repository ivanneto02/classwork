#ifndef __DEC_TYPECHECK__
#define __DEC_TYPECHECK__

int yyerror(char* s);

void check_identifier(char* id) {
    // 
}

void check_array_size(int size, int args) {
    // printf("%d, %d\n", size, args);
    if (size < 0) {
        yyerror("Semantic Error"); // TODO add error messages...
    }
    else if (size != args) {
        yyerror("Semantic Error"); // TODO add error messages...
    }
}

void check_dtypes(char* type1, char* type2) {
    if (strcmp(type1, type2)) {
        yyerror("Semantic Error"); // TODO add error messages...
    }
}

#endif