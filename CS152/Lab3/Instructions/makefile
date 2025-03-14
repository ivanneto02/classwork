# part of the makefile
example: example.tokenizer.l example.grammar.y
	bison -d example.grammar.y
	flex example.tokenizer.l
	cc -o $@ example.grammar.tab.c lex.yy.c -lfl
