all:matrix.o main.o
	gcc -std=c99 -fopenmp matrix.o main.o -o out
matrix.o:
	gcc -std=c99 -fopenmp matrix.c -c
main.o:
	gcc -std=c99 -fopenmp main.c -c

