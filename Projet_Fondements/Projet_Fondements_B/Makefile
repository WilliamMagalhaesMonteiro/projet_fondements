run: compil
	./a.out 4


test:
	./a.out 4
	sleep 1s
	./a.out 4
	sleep 1s
	./a.out 4
	sleep 1s
	./a.out 4
	sleep 1s
	./a.out 4
	sleep 1s
	./a.out 4
	sleep 1s
	./a.out 4
	sleep 1s
	./a.out 4
	sleep 1s
	./a.out 4
	sleep 1s
	
compil: main.c lecture_fichier.c pam.c

	gcc -Wall -c -g lecture_fichier.c pam.c
	gcc  -g lecture_fichier.o pam.o main.c


clean:
	rm *.o a.out
