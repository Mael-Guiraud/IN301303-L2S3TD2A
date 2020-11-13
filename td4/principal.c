#include <stdio.h>
#include "ea.h"
int main()
{
	EA e,e1,e2,e3,e4;
	e1 = ea_creer_valeur(12.3);
	e2 = ea_creer_valeur(4.56);
	e = ea_creer_operation('+',e1,e2);
	printf("%f\n",ea_evaluer(e));


	e1 = ea_creer_valeur(1);
	e2 = ea_creer_valeur(2);
	e3 = ea_creer_valeur(3);
	e4 = ea_creer_operation('*',e2,e3);
	e = ea_creer_operation('+',e1,e4);
	printf("%f\n",ea_evaluer(e));


	e1 = ea_creer_valeur(6);
	e2 = ea_creer_valeur(7);
	e = ea_creer_operation('+',e1,e2);
	e1 = ea_creer_valeur(5);
	e2 = ea_creer_operation('+',e1,e);

	e1 = ea_creer_valeur(3);
	e3 = ea_creer_valeur(4);
	e = ea_creer_operation('-',e1,e3);

	e1 = ea_creer_operation('*',e,e2);

	e = ea_creer_valeur(8);
	e3 = ea_creer_valeur(9);
	e2 = ea_creer_operation('-',e,e3);

	e = ea_creer_operation('+',e2,e1);

	e1 = ea_creer_valeur(1);
	e3 = ea_creer_valeur(2);
	e2 = ea_creer_operation('+',e1,e3);

	e1 = ea_creer_operation('*',e,e2);

	printf("%f\n",ea_evaluer(e1));
	return 0;
}