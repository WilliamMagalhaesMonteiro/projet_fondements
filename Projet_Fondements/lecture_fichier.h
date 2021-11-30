#include <stdio.h>
#include "pam.h"



void affiche_objet(OBJET obj);
void affiche_dataset(OBJET *dataset);
OBJET ln_to_objet(char *ligne);
int file_to_objet(char *path, OBJET *dataset);
