#include "constantes.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int T[N];
void lecture(){
	//ouverture fichier
	FILE * fichier;
	fichier = fopen(NOMFIC,"r");
	//Lecutre
	for(int i=0;i<N;i++)
	{
		fscanf(fichier,"%d",&T[i]);
	}
	//fermeture fichier
	fclose(fichier);

}
void ecrire(){
	//ouverture fichier
	FILE * fichier;
	fichier = fopen("nombres-verif.data","w");
	//Ecriture 
	for(int i=0;i<N;i++)
	{
		fprintf(fichier,"%2d\n",T[i]);
	}
	//fermeture fichier
	fclose(fichier);

}

// Recherche X dans T
//Renvoie 1 si x est dans T, 0 sinon
int recherche(int x){
	int cmpt = 0;
	for(int i=0;i<N;i++)
	{
		cmpt++;
		if(x == T[i])
		{
			printf("J'ai effectué %d comparaisons !!!! \n",cmpt);
			return 1;
		}
	}
	printf("J'ai effectué %d comparaisons !!!! \n",cmpt);
	return 0;
}

int stat_recherche(int x){
	int cmpt = 0;
	for(int i=0;i<N;i++)
	{
		cmpt++;
		if(x == T[i])
		{
			return cmpt;
		}
	}

	return cmpt ;
}



int main(){
	
	srandom(getpid());
	lecture();
	ecrire();

	long long int moyenne = 0;
	for(int i=0;i<10000;i++)
	{
		moyenne = moyenne + stat_recherche(random()%(5*MAX));
	}

	printf("J'ai effecuté en moyenne %lld comparaisons\n",moyenne/10000);


}