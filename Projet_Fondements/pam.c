#include "pam.h"
#include <stdlib.h>
#include <stdio.h>

int abs(int a)
{ //renvoie la valeur absolue
    if (a <= 0)
    {
        return -a;
    }
    else
    {
        return a;
    }
}

int tab_contains_int(int *tab, int n, int a)
{
    for (int i = 0; i < n; i++)
    {
        if (a == tab[i])
        {
            return 1;
        }
    }
    return 0;
}

int dataset_to_seed(int k, OBJET *dataset, OBJET *seed, OBJET *T)
{
    //srandom(time(NULL));
    srandom(2);
    int *randoms = malloc(sizeof(int) * k); // Pour se rappeler des indices de seed pour les ignorer quand on contruit T
    int r;
    for (int i = 0; i < k; i++)
    {
        r = random() % 50;
        randoms[i] = r;
        seed[i] = dataset[r];
    }

    int t = 0;

    for (int i = 0; t < 50 - k; i++)
    {
        if (tab_contains_int(randoms, k, i))
        {
            continue;
        }
        else
        {
            T[t] = dataset[i];
            t++;
        }
    }

    free(randoms);
    return 0;
}

int d(OBJET a, OBJET b)
{ // Renvoie la somme des distances de chaque champs des objets

    int rep = 0;
    rep += abs(a.courage - b.courage);
    rep += abs(a.loyauté - b.loyauté);
    rep += abs(a.sagesse - b.sagesse);
    rep += abs(a.malice - b.malice);

    return rep;
}



int initialise_M(int **M, OBJET *seed,int k, OBJET *T){

    int distance = -1;
    int min = 41;   // (la distance max entre deux objets est de 40)
    //int indice = -1;

    for (int i = 0; i < 50 - k; i++)
    {
        for (int j = 0; j < k; j++)
        {

            distance = d(seed[j], T[i]);
            M[i][j] = distance;

            if (distance < min)
            {
                min = distance;
                M[i][k] = min;
                M[i][k+1] = j;
            }
        }
        min = 41;
    }
return 0;
}


int calcule_partition(int *M,int c){} // Calcule le coût global du cluster indice c
