#include "lecture_fichier.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void affiche_objet(OBJET obj){

	printf("obj.nom : %s\n", obj.nom);
	printf("obj.courage : %d\n", obj.courage);
	printf("obj.loyauté : %d\n", obj.loyauté);
	printf("obj.sagesse : %d\n", obj.sagesse);
	printf("obj.malice : %d\n", obj.malice);
	printf("obj.maison : %s\nstrlen(obj.maison) : %ld", obj.maison, strlen(obj.maison));
	printf("\n");
}


OBJET ln_to_objet(char *ligne) // Prend une ligne de caractères et renvoie un objet avec les valeurs inscrites dans la ligne
{
	OBJET obj;
	char *value = strtok(ligne, ";");
	int i = 1;
	while (value)
	{
		switch(i){

			case 1 :
				obj.nom = value;
			break;

			case 2 :
				obj.courage = atoi(value);
			break;

			case 3 :
				obj.loyauté = atoi(value);
			break;

			case 4 :
				obj.sagesse = atoi(value);
			break;

			case 5 :
				obj.malice = atoi(value);
			break;

			case 6 :
				obj.maison = value;
			break;
		}
		value = strtok(NULL, ";");
		i++;
	}
	affiche_objet(obj);
	return obj;
}

OBJET file_to_objet(char *path) // Prend le PATH du .csv et renvoie le tableau d'objets
{ 
	FILE *f;
	f = fopen(path, "r");

	char buff[1024];
	fgets(buff, 1024, f); // On fait un fgets dans le vide pour enlever l'en-tête des colonnes

	while (fgets(buff, 1024, f)){
		ln_to_objet(buff);
	}

	fclose(f);
}

