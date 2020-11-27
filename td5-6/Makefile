

all: compil run

run: token
	./token

compil: token.o principal.o
	gcc -g -o token token.o principal.o

token.o: token.c token.h
	gcc -g -c token.c 

principal.o: principal.c token.h
	gcc -g -c principal.c

debug: compil token
	valgrind ./token

clean:
	rm -f *.o
	rm -f token