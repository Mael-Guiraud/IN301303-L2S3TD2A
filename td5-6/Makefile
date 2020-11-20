

all: compil run

run: token
	./token

compil: token.o principal.o
	gcc -o token token.o principal.o

token.o: token.c token.h
	gcc -c token.c 

principal.o: principal.c token.h
	gcc -c principal.c