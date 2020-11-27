#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>



#include "token.h"




TOKEN token_ajouter_fin_liste (TOKEN t,float val,char c)
{
	TOKEN new = malloc(sizeof(struct token));

	if( ( c == '+') || ( c == '-') ||( c == '/') || ( c == '*') ){
		new->type_token = EST_OP;
	}
	else
	{
		if(c == '(')
		{
			new->type_token = EST_OUVRANTE;
		}
		else
		{
			if(c == ')')
			{
				new->type_token = EST_FERMANTE;
			}
			else
			{
				if(c == '^')
				{
					new->type_token = EST_VAL;
				}
				else
				{
					printf("Type token inconnu, erreur . (token.c ajouter token)\n");
					exit(4);
				}
			}
		}
	}

	new->op= c;
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
		switch(t->type_token)
		{
		    case EST_VAL:
		      	printf("%f", t->val);
		    	break;
		    case EST_OUVRANTE:
		      	printf("(");
		    	break;
		    case EST_FERMANTE:
		        	printf(")");
		     	break;
		    case EST_OP:
		        	printf("%c",t->op);
		        break;
		    default:
		     	printf("Je ne connais pas ce token \n");
		     	exit(5);
		     	break;
		}
				t = t->suiv;
	}
	printf("\n");
}

TOKEN token_creer_liste(char * s){
	int i=0;
	float f;
	TOKEN t = NULL;
	int compteur_points;
	while(s[i] != '\0')
	{
		if( ( s[i] == '+') || ( s[i] == '-') ||( s[i] == '/') || ( s[i] == '*')|| ( s[i] == '(')|| ( s[i] == ')') )
		{
			t = token_ajouter_fin_liste(t,0,s[i]);
			i++;
		}
		else
		{
			if( s[i] == ' ')
			{
				i++;
			}
			else
			{
				if(isdigit(s[i]))
				{
					f = atof(s+i);
					t = token_ajouter_fin_liste(t,f,'^');
					compteur_points = 0;
					while( ( s[i] ==  '.') || isdigit(s[i])) 
					{
						if( s[i] ==  '.')
						{
							compteur_points++;
							if(compteur_points > 1)
							{
								printf("Chaine non valide.\n");
								exit(5);
							}
						}
						i++;
					}
				}
				else
				{
					printf("Chaine non valide.\n");
					exit(6);
				}
			}
		}

	}
	return t;

}

void free_token_list(TOKEN t)
{
	TOKEN t2;
	while(t)
	{
		t2 = t;
		t=t->suiv;
		free(t2);
	}
}