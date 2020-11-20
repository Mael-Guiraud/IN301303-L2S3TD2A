#include <stdlib.h>
#include <stdio.h>
#include "token.h"



TOKEN token_ajouter_fin_liste (TOKEN t,float val)
{
	TOKEN new = malloc(sizeof(struct token));
	new->val = val;
	new->suiv = NULL;

	if(t == NULL)
	{
		new->prec = NULL;
		return new;
	}

	TOKEN t2 = t;
	while(t2->suiv) // while(t2->suiv != NULL)
	{
		t2 = t2->suiv;
	}
	t2->suiv = new;
	new->prec = t2;

	return t;

}
void token_afficher (TOKEN t){
	if(t == NULL) printf("Ya rien ici");

	while(t){
		printf("%f\n", t->val);
		t = t->suiv;
	}

}