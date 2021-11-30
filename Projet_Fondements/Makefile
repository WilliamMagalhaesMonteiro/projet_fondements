run: compil
	./a.out

compil: main.c lecture_fichier.c pam.c

	gcc -Wall -c -g lecture_fichier.c pam.c
	gcc  -g lecture_fichier.o pam.o main.c


make clean:
	rm *.o a.out
