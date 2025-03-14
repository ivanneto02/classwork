
## Compile and run project parser

    cd KATCHUP-L/
    bison -v -d --file-prefix=y katchup.parser.y; flex katchup.tokenizer.l; gcc -o parser y.tab.c lex.yy.c -lfl; ./parser input01.katc
