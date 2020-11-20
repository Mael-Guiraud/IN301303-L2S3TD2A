#include <stdio.h>
#include <stdlib.h>
#include "token.h"


int main(int argc, char const *argv[])
{
	TOKEN t = NULL;
	t = token_ajouter_fin_liste (t, 2.3);
	t = token_ajouter_fin_liste (t, 8);
	t = token_ajouter_fin_liste (t, 5.12);
	token_afficher(t);


	return 0;
}