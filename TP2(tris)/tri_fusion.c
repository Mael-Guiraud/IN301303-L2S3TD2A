#include "stat.h"
#include "tabint.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
// fusionne les tableaux [deb..mil] et [mil+1..fin]
void fusion (int *t, int deb, int mil, int fin) {
	int *temp;
	temp = malloc((fin-deb+1)*sizeof(int));
	if (temp==NULL) exit(4);
	int i,i1,i2;
	i = 0;
	i1 = deb;
	i2 = mil+1;
	// A chaque tour de boucle on recopie dans tmp
	// la plus petite valeur du premier ou du deuxième tableau
	while ((i1<=mil) && (i2<=fin)) {
		if (t[i1]<t[i2]) {temp[i] = t[i1]; i1++;}
				else	 {temp[i] = t[i2]; i2++;}
		i++;
	}
	while (i1<=mil) { // Pour finir de recopier le tableau 1
		temp[i] = t[i1];
		i1++;
		i++;
	}
	while (i2<=fin) { // Pour finir de recopier le tableau 2
		temp[i] = t[i2];
		i2++;
		i++;
	}
	// Recopie de temp dans t
	for (i=deb ; i<=fin ; i++) {
		t[i] = temp[i-deb];
	}
	// On libère le tableau temp
	free(temp);
}


// tri fusion pour la portion du tableau [deb..fin]
void tri_fusion(int *t, int deb, int fin) {
	if (fin<deb) exit(5); // Ne doit jamais arriver
	if (fin==deb) return ; // Un tableau de 1 case est trié
	int mil = (deb+fin)/2;
	// Découpage de [deb..fin] en deux sous-tableaux :
	// [deb..mil] et [mil+1..fin]
	tri_fusion(t,deb,mil);
	tri_fusion(t,mil+1,fin);
	fusion(t,deb,mil,fin);
}


int main(int argc,char*argv[]) {
	
	srandom(getpid());
	//VRAI CODE
	TABINT T;
	T = gen_alea_tabint(atoi(argv[1]),600);

	tri_fusion(T.val,0,T.N-1);

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
