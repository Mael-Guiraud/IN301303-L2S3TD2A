
all: compilgenere compilalgo run diff

compilgenere: genere.c constantes.h
	gcc genere.c -o genere

compilalgo: algo.c constantes.h
	gcc algo.c -o algo

run: algo genere
	./genere
	./algo

diff:
	diff nombres.data nombres-verif.data