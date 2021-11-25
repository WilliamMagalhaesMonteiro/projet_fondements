#include "lecture_fichier.h"
#include <stdio.h>
#define PATH "/home/user/Bureau/Projet_Fondements/choixpeauMagique.csv"





int main(){

FILE *f;
f = fopen(PATH,"r");

/*
char carac;
for (int i = 0; i < 1000; i++){
	fscanf(f,"%c", &carac);
	printf("%c", carac);
}
*/

read_line(f);

return 0;
}
