run: compil
	./a.out

compil: main.c lecture_fichier.c

	gcc -Wall -c lecture_fichier.c
	gcc lecture_fichier.o main.c


make clean:
	rm *.o a.out
