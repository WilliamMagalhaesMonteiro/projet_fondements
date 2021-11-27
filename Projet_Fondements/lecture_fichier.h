#include <stdio.h>


struct objet {
	char *nom;
	int courage;
	int loyauté;
	int sagesse;
	int malice;
	char *maison;
};

typedef struct objet OBJET;


void affiche_objet(OBJET obj);
OBJET ln_to_objet(char *ligne);
OBJET file_to_objet(char *path);
