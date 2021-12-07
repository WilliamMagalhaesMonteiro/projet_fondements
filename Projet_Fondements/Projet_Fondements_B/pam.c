#include "pam.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int abs(int a)
{ // renvoie la valeur absolue
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
    srandom(time(NULL));
    //srandom(2);
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
    rep += abs(a.loyaute - b.loyaute);
    rep += abs(a.sagesse - b.sagesse);
    rep += abs(a.malice - b.malice);

    return rep;
}

int initialise_M(int **M, OBJET *seed, int k, OBJET *T)
{

    int distance = -1;
    int min = 41; // (la distance max entre deux objets est de 40)
    // int indice = -1;

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
                M[i][k + 1] = j;
            }
        }
        min = 41;
    }
    return 0;
}

int calcule_partition(int **M, int k_num, int c)
{ // Calcule le coût global du cluster indice c, k_num => nb clusters
    int d = 0;
    for (int j = 0; j < 50 - k_num; j++)
    { // Pour parcourir dans la matrice M
        if (c == M[j][k_num + 1])
        {
            d += *M[k_num];
        }
    }
    return d;
}

int d_min(int **M, int k_num, int k)
{ // k_num => nb de clusters, k => cluster dont on calcule la dist min
    int d = 0;
    for (int j = 0; j < 50 - k_num; j++)
    { // Pour parcourir dans la matrice M
        if (k == M[j][k_num + 1])
        {
            d += M[j][k_num];
        }
    }
    return d;
}

int d_new(int **M, int k, int c)
{ // k => nb de clusters, c => cluster dont on calcule la dist min
    int d = 0;
    for (int j = 0; j < 50 - k; j++)
    { // Pour parcourir dans la matrice M
        if (c == M[j][k + 1])
        {
            d += M[j][c];
        }
    }
    return d;
}

int change(int **M, OBJET *T, int k_num, OBJET *seed, int k)
{

    int final_distance = d_min(M, k_num, k);
    int final_index = 1;
    for (int i = 0; i < 50 - k_num; i++)
    {
        printf("%d\n", i);
        if (M[i][k_num + 1] == k)
        {
            printf("ON EST LA\n");
            OBJET n = T[i];
            T[i] = seed[k];
            seed[k] = n;
            for (int j = 0; j < k_num; j++)
            {
                int distance = d(seed[j], T[i]);
                printf("ici distance: %d \n", distance);
                M[i][j] = distance;
            };

            int distance = d_min(M, k_num, k);
            seed[k] = T[i];
            T[i] = n; // Remis à sa place pour ne pas déranger le tableau

            printf("distance : %d et final distaznce = %d\n", distance, final_distance);
            if (distance < final_distance)
            {
                final_distance = distance;
                final_index = i;
            }
        }
    }

    printf("%d final\n", final_index);

    seed[k] = T[final_index];
    initialise_M(M, seed, k_num, T);

    return 0;
}

int change_2(int **M, OBJET *T, int k_num, OBJET *seed, int k)
{
    int final_distance = d_min(M, k_num, k);
    int final_index = 2;

    for (int i = 0; i < 50 - k_num; i++)
    {
        if (M[i][k_num + 1] == k)
        {
            OBJET temp_seed = seed[k];
            seed[k] = T[i];
            T[i] = temp_seed;
            for (int j = 0; j < 50 - k_num; j++)
            {
                if (M[j][k_num + 1] == k)
                {
                    printf("zebi\n");
                    printf("%d\n", M[j][k]);
                    M[j][k] = d(seed[k], T[i]);
                    //	}
                    //}
                    int temp_dist = d_min(M, k_num, k);
                    printf("Distance temp = %d\n", temp_dist);

                    if (temp_dist < final_distance)
                    {
                        printf("Je suis la\n");
                        final_distance = temp_dist;
                        final_index = i;
                    }
                }
            }
            printf("Distance f et index f = %d %d \n", final_distance, final_index);
            T[i] = seed[k];
            seed[k] = temp_seed;
        }
    }
    seed[k] = T[final_index];
    return 0;
}

int calcule_colonne(int **M, OBJET *seed, int k, OBJET *T, int c)
{ // Calcule les distances individuelles au cluster c

    int distance;
    for (int i = 0; i < 50 - k; i++)
    {

        distance = d(seed[c], T[i]);
        M[i][c] = distance;
    }

    return 0;
}

int swappings(int **M, OBJET *T, int k, OBJET *seed, int c) // Calcule le meilleur centre du cluster c
{ // k est le NOMBRE TOTAL DE CLUSTERS et c celui considéré

    // c = 1
    // k = 4


    int old;
    int new;
    int changement = 0;

    old = d_new(M, k, c);

    OBJET swap;

    for (int i = 0; i < 50 - k; i++)
    {

       
       
     //printf("OLD : %d\n", old);

        swap = seed[c];
        seed[c] = T[i];
        T[i] = swap;

        //printf("%d dans seed : %s\n", c, seed[c].nom);
        //printf("%d dans T: %s\n", i, T[i].nom);

        calcule_colonne(M, seed, k, T, c);

        new = d_new(M, k, c);
        //printf("NEW : %d\n", new);

        if (new >= old)
        {

            swap = seed[c];
            seed[c] = T[i];
            T[i] = swap;
            //printf("moins bien\n");
        }

        else
        {
            //printf("MIEUX\n");
            old = new;
            changement = 1;
        }
        //printf("\n");
    }
    return changement;
}


