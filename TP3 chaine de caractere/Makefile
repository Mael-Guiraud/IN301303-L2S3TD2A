all: compil run

run: exe
	#test somme
	#./exe jnjnfq ?! 6.2 -8 -.5
	#test mystrlen
	#./exe 12caracteres
	#test mystrcmp
	./exe abcd abcd
	./exe abcd abdc
	./exe abdc abcd
	./exe abcd abcde
	./exe abcde abcd
	./exe bonjour toto
compil: tp3.c
	gcc -o exe tp3.c