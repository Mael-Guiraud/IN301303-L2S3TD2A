#ifndef _TABINT_H
#define _TABINT_H


struct tabint {
    int N;  // Taille du tableau
    int *val; // Pointeur vers le tableau
};
typedef struct tabint TABINT;


TABINT alloue_tabint (int N);
TABINT desalloue_tabint (TABINT T);
TABINT gen_alea_tabint (int N, int K);
void aff_tabint (TABINT T);

int verif_si_tableau_croissant (TABINT T); 

#endif
