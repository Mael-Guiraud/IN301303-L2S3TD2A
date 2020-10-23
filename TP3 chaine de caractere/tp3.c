#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


//Teste si une chaine de caracteres est un nombre
int test_nbr(char *s){
	int i=0;
	int cmptpoint = 0;
	int a;
	while(*(s+i) != '\0')
	{
		//transforme le caractère en entier (son code ASCII)
		a = *(s+i);
		//Si le code ASCII n'est pas entre 48 (0) et 57 (9) on test :
		if(!isdigit(a) )
		{
			// Si c'est un point
			if(*(s+i) == '.')
			{

				cmptpoint ++;
				//Si c'est plus que le premier ., on quitte
				if(cmptpoint > 1)
				{
					return 0;
				}

				//sinon, on passe au prochain tour de boucle
				i++;
				continue;
			}
		
			// Si c'est un moins du debut, on passe au prochain tour de boucle
			if( (*(s+i) == '-') && (i==0))
			{
				i++;
				continue;
			}
			//Si on est ici, c'est que le caractère n'est ni un point, ni un - au debut on quitte
			return 0;
			
		}
		i++;

	}

	return 1;
}

int mystrlen_iter(char * s)
{
	int nb_char = 0;
	while(*(s+nb_char) != '\0')
	{
		nb_char++;
	}
	return nb_char;
}

int mystrlen_recursif(char * s)
{
	if(*s == '\0')
		return 0;
	else
		return mystrlen_recursif(s+1)  +1;
}

int mystrcmp_iter(char * s1,char* s2)
{
	int i=0;
	while( (s1[i] != '\0') && (s2[i] != '\0') )
	{
		if(s1[i] != s2[i])
			return s1[i] - s2[i];
		i++;
	}
	return s1[i] - s2[i];
}

int mystrcmp_rec(char * s1,char* s2)
{
	if( (*s1 == '\0') || (*s2 == '\0') ||  (*s1 != *s2)  )
	{
		return *s1 - *s2;
	}
	
	return mystrcmp_rec(s1+1,s2+1);
	


}

int main( int argc, char** argv){
  int i;
  /*
  double somme = 0.0;
  for(i=1 ; i<argc ; i++)
  {
  		//Test si la chaine de caractère est un nombre (negatif ou non, flotant ou non)
		if(test_nbr(argv[i]))
		{
			//Si c'est le cas, on l'ajoute a la somme
			somme += atof(argv[i]);	
		}
  }
 printf("La somme vaut %f \n",somme);
	*/


// printf("La longueur de la chaine est %d (iteratif)\n ",mystrlen_iter(argv[1]));
// printf("La longueur de la chaine est %d (recursif)\n ",mystrlen_recursif(argv[1]));


printf("La valeur de mystrcmp est %d (iter)\n",mystrcmp_iter(argv[1],argv[2]));
printf("La valeur de mystrcmp est %d (rec)\n",mystrcmp_rec(argv[1],argv[2]));
  return 0;
}