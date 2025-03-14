# project_lexical-khamm012-amiya017-ineto001
project_lexical-khamm012-amiya017-ineto001 created by GitHub Classroom

# command to run everything from `Min L Examples`
> flex -o output.c --header-file=header.h ../instructions/example.tokenizer.l && gcc output.c -o output.out && ./output.out

## Task 1 
Modified `example.tokenizer.l` to identify tokens.

Tokens:
- digit
- number 
- plus
- minus
- multiplication
- division
- left parenthesis
- right parenthesis
- equal sign

## Task 2 
Modified `example.tokenizer.l` to read from an input file (specified as an argument to `./output.out`) instead of from the command line.

## Task 3
Modified `example.tokenizer.l` to count tokens.

Token counts: 
- integers
- operators
- parentheses
- equal signs
