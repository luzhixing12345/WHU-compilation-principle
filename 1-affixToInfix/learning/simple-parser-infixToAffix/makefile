
CC=gcc

all:retsuff affix

retsuff:name.o retsuff.o lex.o main.o
	$(CC) name.o retsuff.o lex.o main.o -o retsuff

affix:affix.o lex.o main.o name.o
	$(CC) affix.o lex.o main.o name.o -o affix


*.o:*.c
	$(CC) -c $^.c -o $@.o



.PHONY:
clean:
	rm -rf *.o affix retsuff
