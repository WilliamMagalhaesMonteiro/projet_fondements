#include "lecture_fichier.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void affiche_objet(OBJET obj){	// Affiche tous les champs d'un objet

	printf("obj.nom : %s\n", obj.nom);
	printf("obj.courage : %d\n", obj.courage);
	printf("obj.loyaute : %d\n", obj.loyaute);
	printf("obj.sagesse : %d\n", obj.sagesse);
	printf("obj.malice : %d\n", obj.malice);
	printf("obj.maison : %s\n", obj.maison);
	
	//printf ("strlen(obj.maison) : %ld\n", strlen(obj.maison));
	printf("\n");
}

void affiche_dataset(OBJET *dataset){

	for (int i = 0; i < 50; i++){
		printf("Candidat n°%d\n", i+1);
		affiche_objet(dataset[i]);
	}
}


OBJET ln_to_objet(char *ligne) // Prend une ligne de caractères et renvoie un objet avec les valeurs inscrites dans la ligne
{
	OBJET obj;
	char *value = strtok(ligne, ";");
	int i = 1;
	int strsize = 0;
	while (value)
	{
		switch(i){

			case 1 :
				
				obj.nom = malloc(sizeof(char) * 32);
				strcpy(obj.nom, value);
			break;

			case 2 :
				obj.courage = atoi(value);
			break;

			case 3 :
				obj.loyaute = atoi(value);
			break;

			case 4 :
				obj.sagesse = atoi(value);
			break;

			case 5 :
				obj.malice = atoi(value);
			break;

			case 6 :	// Maison
				strsize = strlen(value);
				obj.maison = malloc(sizeof(char) * 32);
				strncpy(obj.maison, value, strsize-2);
				//obj.maison[strsize] = '\0';

				/*printf("obj.nom : %s\n", obj.nom);

				for (int i = 0; i < 32; i++){
					printf("obj.maison[%d] : (%c)(%d)\n", i, obj.maison[i], obj.maison[i]);
				}
				printf("strlen(objet.maison) : %ld\n", strlen(obj.maison));
				*/
			break;
		}
		value = strtok(NULL, ";");
		i++;
	}
	return obj;
}

int file_to_objet(char *path, OBJET *dataset) // Prend le PATH du .csv et renvoie le tableau d'objets
{ 
	FILE *f;
	f = fopen(path, "r");
	
	if (!f)
	{
		printf("Erreur dans l'ouverture du fichier");
		exit(1);
	}
	

	char buff[1024];
	fgets(buff, 1024, f); // On fait un fgets dans le vide pour enlever l'en-tête des colonnes
	

	for (int i = 0; i < 50; i++){
		fgets(buff, 1024, f);
		dataset[i] = ln_to_objet(buff);
	}
	
	/*
	int i = 0;
	while (fgets(buff, 1024, f)){
		dataset[i] = ln_to_objet(buff);
		i++;
	}*/

	fclose(f);
	return 0;
}

void affiche_clusters_noms(int **M, OBJET *seed, int k, OBJET *T)
{

    for (int i = 0; i < k; i++)
    {
        printf("----- DEBUT DU CLUSTER %d -----\n", i);
        for (int j = 0; j < 50 - k; j++)
        {
            if (M[j][k+1] == i)
            {
                printf("%s\n",T[j].nom);
            }
        }
        printf("----- FIN DU CLUSTER %d -----\n\n", i);
    }
}

void affiche_clusters_all(int **M, OBJET *seed, int k, OBJET *T)
{

    for (int i = 0; i < k; i++)
    {
        printf("----- DEBUT DU CLUSTER %d -----\n", i);
        for (int j = 0; j < 50 - k; j++)
        {
            if (M[j][k+1] == i)
            {
                affiche_objet(T[j]);
            }
        }
        printf("----- FIN DU CLUSTER %d -----\n\n", i);
    }
}
