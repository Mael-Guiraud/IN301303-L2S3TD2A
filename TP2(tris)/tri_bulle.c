
#include "tabint.h"
#include "stat.h"
#include "tri_fusion.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void tri_bulle(TABINT T){
	int i,fin;
	int testnbcomparaisons;
	fin = T.N-1;
	while (fin>0) {
		testnbcomparaisons = 0;
		for (i=0 ; i<fin ; i++) {
			if (T.val[i]>T.val[i+1]) {
				int temp   = T.val[i];
				T.val[i]   = T.val[i+1];
				T.val[i+1] = temp;
				testnbcomparaisons++;
			}

		}
		if(!testnbcomparaisons)// testnbcomparaisons == 0
		{
			return;
		}
		fin--;
	}
}

int main(int argc, char*argv[]) {
	
	srandom(getpid());
	//VRAI CODE
	TABINT T;
	T = gen_alea_tabint(atoi(argv[1]),600);

	tri_bulle(T);

	desalloue_tabint(T);


	// Le code ci-dessous est provisoire, juste pour faire marche l'enchainement du Makefile
	FILE *F;
	F = fopen("test_tri_bulle.data","w");
	fprintf(F,"   10           45.00           21.97\n");
 	fprintf(F,"   12           66.00           33.08\n");
 	fprintf(F,"   14           91.00           46.35\n");
 	fprintf(F,"   16          120.00           61.08\n");
 	fprintf(F,"   19          171.00           85.71\n");
 	fprintf(F,"   22          231.00          115.62\n");
 	fprintf(F,"   26          327.00          162.21\n");
	fclose(F);
	// Fin du code provisoire
	exit(0);
}
