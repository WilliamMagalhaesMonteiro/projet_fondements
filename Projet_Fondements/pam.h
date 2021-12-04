struct objet {
	char *nom;
	int courage;
	int loyauté;
	int sagesse;
	int malice;
	char *maison;
};

typedef struct objet OBJET;


int dataset_to_seed(int k, OBJET *dataset, OBJET *seed,OBJET *T);
int tab_contains_int(int *tab, int n, int a);