struct objet {
	char *nom;
	int courage;
	int loyaute;
	int sagesse;
	int malice;
	char *maison;
};

typedef struct objet OBJET;


int dataset_to_seed(int k, OBJET *dataset, OBJET *seed,OBJET *T);
int tab_contains_int(int *tab, int n, int a);
int d(OBJET a, OBJET b);
int initialise_M(int **M, OBJET *seed,int k, OBJET *T);
int calcule_partition(int *M,int c);