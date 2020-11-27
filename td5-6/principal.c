#include <stdio.h>
#include <stdlib.h>
#include "token.h"
#include <ctype.h>



int main(int argc, char const *argv[])
{
	
	TOKEN t = token_creer_liste("17.4648 + 247.1 *124 ");
	token_afficher(t);
	free_token_list( t);
	return 0;
}