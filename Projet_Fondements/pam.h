struct objet {
	char *nom;
	int courage;
	int loyauté;
	int sagesse;
	int malice;
	char *maison;
};

typedef struct objet OBJET;


int dataset_to_seed(int k, OBJET *dataset, OBJET *seed);