


struct token{
	float val;
	struct token * suiv;
	struct token * prec;
	int type_token;
	char op;
};

typedef struct token* TOKEN;

TOKEN token_ajouter_fin_liste (TOKEN t,float val);
void token_afficher (TOKEN t);