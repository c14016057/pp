C99 = -std=c99
mp = -fopenmp
all:	hello_id_for-omp
%-omp: %.c
	gcc $(mp) $(C99) $< -o $@
%-uni: %.c
	gcc $(C99) $< -o $@
clean:
	rm *-uni *-omp
