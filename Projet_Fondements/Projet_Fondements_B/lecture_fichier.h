#include <stdio.h>
#include "pam.h"



void affiche_objet(OBJET obj);
void affiche_dataset(OBJET *dataset);
OBJET ln_to_objet(char *ligne);
int file_to_objet(char *path, OBJET *dataset);
void affiche_clusters_noms(int **M, OBJET *seed, int k, OBJET *T);
void affiche_clusters_all(int **M, OBJET *seed, int k, OBJET *T);
