#include "lecture_fichier.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define PATH "/home/user/Bureau/Projet_Fondements/choixpeauMagique.csv"





int main(){

OBJET *dataset = malloc(sizeof(OBJET) * 50);
file_to_objet(PATH, dataset);
//affiche_dataset(dataset);


OBJET test = dataset[0];

for (int i = 0; i < 50; i++){
    if (!strcmp(test.maison, dataset[i].maison)){
        
        printf("Candidat n°%d\n", i+1);
        affiche_objet(dataset[i]);
    }
}

for (int i = 0; i < 50; i++){
    free(dataset[i].nom);
    free(dataset[i].maison);
}
free(dataset);


return 0;
}
