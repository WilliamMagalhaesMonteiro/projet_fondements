#include "lecture_fichier.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define PATH "choixpeauMagique.csv"


int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        printf("Err,must run with {a./out k}\n");
        exit(1);
    }

    int k = atoi(argv[1]);

    if (k == 0)
    {
        printf("Err, argv[1] must be an integer\n");
        exit(1);
    }

    OBJET *dataset = malloc(sizeof(OBJET) * 50); // Dataset de toutes les données (les 50 élèves)
    file_to_objet(PATH, dataset);

    OBJET *seed = malloc(sizeof(OBJET) * k); // Graine de k clusters

    OBJET *T = malloc(sizeof(OBJET) * (50 - k)); // Vecteur colonne contenant exclusivement les éléments non-représentatifs
    dataset_to_seed(k, dataset, seed, T);



    int **M = (int **)malloc((50 - k) * sizeof(int *));
    for (int i = 0; i < 50 - k; i++)
    {
        M[i] = (int *)malloc((k + 2) * sizeof(int));
    }

    initialise_M(M, seed, k, T);
   
    /*for (int i = 0; i < 50 - k; i++)
    {
        for (int j = 0; j < k + 2; j++)
        {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }*/



	printf("Debut PAM\n");
	//for( int i = 0; i <= k; i++){
	//change_2(M,T,k,seed,2);
    //swappings(M,T,k,seed,0);
   
    int changement = 1;

    while(changement){
        for (int i = 0 ; i < k; i++) {
            //printf("Calcul du meilleur centre pour le cluster %d ----------\n\n",i);
            changement = swappings(M,T,k,seed,i);
            //printf("CHANGEMENT : %d\n", changement);
        }
        initialise_M(M, seed, k, T);
    }

    printf("RESULTATS : \n");
    for (int i = 0; i < k; i ++){
        //affiche_clusters_all(M,seed,k,T);
        //affiche_objet(seed[i]);
    }

    int sum = 0;
    for(int i = 0 ; i < 50-k; i++){
        sum += M[i][k];
    }
    printf("COUT TOTAL : %d\n",sum);


    for(int i = 0; i < k; i++){
        for (int j = 0; j < 50; j++){
            //printf("seed[k] : %s\n", seed[k].nom);
            
            if(!strcmp(seed[i].nom,dataset[j].nom)){
                printf("cluster N°%d, élève indice : %d\n",i,j);
            }
        }
    }


    // /!\ SURTOUT NE PAS SUPPRIMER CI-DESSOUS /!\ -----------------------------------------------------------------------
    for (int i = 0; i < 50; i++)
    {
        free(dataset[i].nom);
        free(dataset[i].maison);
    }


    for (int i = 0; i < 50-k; i++){
        free(M[i]);
    }
 
   free(M);

    free(seed);
    free(T);
    free(dataset);

    return 0;
}

/*  Affiche tous les gens de Serpentard
OBJET test = dataset[0];

for (int i = 0; i < 50; i++){
    if (!strcmp(test.maison, dataset[i].maison)){
        
        printf("Candidat n°%d\n", i+1);
        affiche_objet(dataset[i]);
    }
}
*/
