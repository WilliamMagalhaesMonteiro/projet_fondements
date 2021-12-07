#include "lecture_fichier.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define PATH "choixpeauMagique.csv"

// Le but de l'algo est le suviant:

// Calcul de la matrice de déprart:
// On a K éléments représentatifs
// On Calcule la distance d'un élément par ex Adrian à chacun des K éléments représentatif
// On associe Adrian à l'élément dont il est le plus proche

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

    /*
        printf("OBJETS DANS SEED \n\n");

        for (int i = 0; i < k; i++)
        {
            affiche_objet(seed[i]);
        }

        printf("OBJETS DANS T \n\n");

        for (int i = 0; i < 50 - k; i++)
        {
            affiche_objet(T[i]);
        }

        for (int i = 0; i < k; i++)
        {
            printf("Distance entre %s et %s : %d\n", dataset[0].nom, seed[i].nom, d(dataset[0],seed[i]));
        }*/

    int **M = (int **)malloc((50 - k) * sizeof(int *));
    for (int i = 0; i < 50 - k; i++)
    {
        M[i] = (int *)malloc((k + 2) * sizeof(int));
    }

    initialise_M(M, seed, k, T);

    for (int i = 0; i < 50 - k; i++)
    {
        for (int j = 0; j < k + 2; j++)
        {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }





    //affiche_clusters_all(M, seed, k, T);
    affiche_clusters_noms(M,seed,k,T);











    for (int i = 0; i < 50; i++)
    {
        free(dataset[i].nom);
        free(dataset[i].maison);
    }

    for (int i = 0; i < 50 - k; i++)
    {
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