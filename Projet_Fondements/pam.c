#include "pam.h"
#include <stdlib.h>
#include <stdio.h>
int dataset_to_seed(int k,OBJET *dataset, OBJET *seed){


    //srandom(time(NULL));
    srandom(2);

    int r;
    //OBJET obj;

    for (int i = 0; i < k;  i++){
        r = random()%50;



        seed[i] = dataset[r];
    }

    return 0;

}