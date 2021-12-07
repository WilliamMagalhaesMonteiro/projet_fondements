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
int calcule_partition(int **M, int k_num,int c);

int d_min(int **M, int k_num, int k);

int d_new(int **M, int k, int c);



int change(int **M, OBJET *T, int k_num, OBJET *seed, int k);
int change_2(int **M, OBJET *T, int k_num, OBJET *seed,int k);



int calcule_colonne(int **M, OBJET *seed, int k, OBJET *T,int c);
int swappings(int **M, OBJET *T, int k, OBJET *seed, int c);