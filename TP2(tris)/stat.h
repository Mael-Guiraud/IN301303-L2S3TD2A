#ifndef _STAT_H
#define _STAT_H


struct stat {
	int N;
	double nb_moy_comp;
	double nb_moy_ech;
};

typedef struct stat * STAT;

// Variables globales pour les stats
unsigned long long int NBCOMP;
unsigned long long int NBECH;

#endif
