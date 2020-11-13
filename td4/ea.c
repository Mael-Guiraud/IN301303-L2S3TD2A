#include "ea.h"
#include <stdlib.h>
#include <stdio.h>
EA ea_creer_valeur(float val)
{

	EA new = malloc(sizeof(struct noeud));
	if(!new){ exit(1);}

	new->op_ou_val = EST_VAL;
	new->op = 0;
	new->val = val;
	new->opg = NULL;
	new->opd = NULL;

	return new;
}

EA ea_creer_operation(char op, EA opg, EA opd)
{
	EA new = malloc(sizeof(struct noeud));
	if(!new){ exit(1);}

	new->op_ou_val = EST_OP;
	new->op = op;
	new->val = 0;
	new->opg = opg;
	new->opd = opd;

	return new;

}

float ea_evaluer(EA e)
{
	float resg, resd;

	if(e == NULL){
		printf("Attention, e vaut NULL\n");
		exit(3);
	}
	if(e->op_ou_val == EST_OP)
	{
		resg = ea_evaluer(e->opg);
		resd = ea_evaluer(e->opd);
		if(e->op == '+')
			return resg + resd;
		if(e->op == '-')
			return resg - resd;
		if(e->op == '*')
			return resg * resd;
		if(e->op == '/')
		{
			if(resd == 0)
			 {
			 	printf("Attention, on ne peux pas diviser par 0\n");
			 	exit(2);
			 }
			return resg / resd;
		}

		printf("L'opérateur suivant n'est pas reconnu : %c \n",e->op);
		exit(4);
	}

	if(e->op_ou_val== EST_VAL)
	{
		return e->val;
	}
	return 0.0;
}

