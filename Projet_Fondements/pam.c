#include "pam.h"
#include <stdlib.h>
#include <stdio.h>


int abs(int a){ //renvoie la valeur absolue
    if (a <= 0){ 
        return -a;
    }
    else {
        return a;
    }
} 

int dataset_to_seed(int k,OBJET *dataset, OBJET *seed){
    //srandom(time(NULL));
    srandom(2);

    int r;

    for (int i = 0; i < k;  i++){
        r = random()%50;
        seed[i] = dataset[r];
    }

    return 0;

}



int d(OBJET a, OBJET b) {   // Renvoie la somme des distances de chaque champs des objets

    int rep = 0;
   rep += abs(a.courage - b.courage);
   rep += abs(a.loyauté - b.loyauté);
   rep += abs(a.sagesse - b.sagesse);
   rep += abs(a.malice - b.malice);

    return rep;
}