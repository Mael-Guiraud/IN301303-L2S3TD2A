#include "constantes.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void ecrire(){
	//ouverture fichier
	FILE * fichier;
	fichier = fopen(NOMFIC,"w");
	//Ecriture N entiers entre 0 et MAX
	for(int i=0;i<N;i++)
	{
		fprintf(fichier,"%2ld\n",random()%MAX);
	}
	//fermeture fichier
	fclose(fichier);

}

int main(){
	srandom(getpid());
	ecrire();
}