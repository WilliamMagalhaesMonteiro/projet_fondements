#include "lecture_fichier.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define PATH "choixpeauMagique.csv"





int main(){

OBJET *dataset = malloc(sizeof(OBJET) * 50);
file_to_objet(PATH, dataset);



int k = 5;
OBJET *seed = malloc(sizeof(OBJET) * k);
dataset_to_seed(k,dataset,seed);



for (int i = 0; i < 50; i++){
    free(dataset[i].nom);
    free(dataset[i].maison);
}


free(seed);



free(dataset);

return 0;
}






/*
OBJET test = dataset[0];

for (int i = 0; i < 50; i++){
    if (!strcmp(test.maison, dataset[i].maison)){
        
        printf("Candidat n°%d\n", i+1);
        affiche_objet(dataset[i]);
    }
}
*/