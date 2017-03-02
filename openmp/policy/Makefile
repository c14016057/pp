all: static_policy\
dynamic_policy\
guided_policy\
runtime_policy\
parallel_section_wtime\
bigpara_join_test\
bigpara_for_test\
nowait\
cs
%: %.c
	gcc -std=c99 -fopenmp $< -o $@
