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




char *read_line(FILE *f);
OBJET ln_to_objet(char *ligne);
