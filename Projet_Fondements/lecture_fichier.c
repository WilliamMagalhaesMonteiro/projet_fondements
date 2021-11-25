#include "lecture_fichier.h"
#include <stdio.h>
#include <stdlib.h>




char *read_line(FILE *f){
	
	
	printf("...\n");
	char current ='a';
	
		while ( current != '\n'){
			fscanf(f,"%c", &current);
			printf("%c", current);
		}
}



OBJET ln_to_objet(char *ligne){		// Prend une ligne (chaîne de caractères) du .csv et renvoie l'objet correspondant
	
	
	
}
