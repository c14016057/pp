C99 = -std=c99
omp = -fopenmp
all:	nQueen-omp nQueen_privatevar-omp\
nQueen_privatevar_redu-omp nQueen_privatevar_cs-omp
%-omp:%.c
	gcc $(C99) $(omp) $< -o $@

