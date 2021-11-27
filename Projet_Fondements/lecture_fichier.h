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
void affiche_dataset(OBJET *dataset);
OBJET ln_to_objet(char *ligne);
void file_to_objet(char *path, OBJET *dataset);
