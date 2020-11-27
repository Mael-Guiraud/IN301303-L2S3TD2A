#ifndef	_TOKEN_H
#define _TOKEN_H


#define EST_VAL 0
#define EST_OP 1
#define EST_OUVRANTE 2
#define EST_FERMANTE 3
struct token{
	float val;
	struct token * suiv;
	struct token * prec;
	int type_token;
	char op;
};


typedef struct token* TOKEN;
TOKEN token_creer_liste(char * s);
TOKEN token_ajouter_fin_liste (TOKEN t,float val, char c);
void token_afficher (TOKEN t);

void free_token_list(TOKEN t);
#endif