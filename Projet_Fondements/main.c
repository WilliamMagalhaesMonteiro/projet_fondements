#include "lecture_fichier.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define PATH "choixpeauMagique.csv"





int main(int argc, char *argv[]){

    if (argc != 2) {
        printf ("Err,must run with {a./out k}\n");
        exit(1);
    }

    int k = atoi(argv[1]);

    if (k== 0){
        printf ("Err, argv[1] must be an integer\n");
        exit(1);
    }


OBJET *dataset = malloc(sizeof(OBJET) * 50);
file_to_objet(PATH, dataset);


printf("k : %d\n", k);

OBJET *seed = malloc(sizeof(OBJET) * k);
dataset_to_seed(k,dataset,seed);


// Le but de l'algo est le suviant:
// Prendre un objet au pif qui n'est pas l'objet représentatif
// On calcule toutes les distances à cet objet
// Si Cette configuration est meilleure que celle avec l'objet représentatif acutel on fait l'échange sinon non
// on fait ça pour touts les objest.




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