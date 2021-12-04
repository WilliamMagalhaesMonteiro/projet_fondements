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