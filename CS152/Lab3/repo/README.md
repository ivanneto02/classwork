

## Compile and run parser

    cd Parser-Using-Bison/; bison -v -d --file-prefix=y calculator.parser.y; flex calculator.tokenizer.l; gcc -o parser y.tab.c lex.yy.c -lfl; ./parser

## Observations (as of soon after ef8c54bb8f50fffc)

works:

    1+1

    1*1

    1*1
    *1

    1%1
    %1

    1+1+
    1

    1*1*
    1*
    1
    *1
    *1
    *1*
    1*1
    *1*1

    1*(1*1)
    *1
    *(1)
    *(1+1)
    *(1/1)
    *(1%1)
    %(1+1)
    +(1*1)
    +(1+1)+(1+1)

    1+(1+1)

    (1*1)*1

    1*(1*1)


errors:

    1+1+1

    ...
    1+1

    ...
    1*1

    ...
    1%1

    1+1
    +1

    (1+1)-(1+1+1)

    (1+1)+1


after 1st line, prints extra newline for each line
