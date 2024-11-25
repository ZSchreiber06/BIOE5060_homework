
laplace:
	gcc laplace2d_func.c laplace2d_func.h laplace2d_solver.c -o laplace2d_func
run: laplace
	./laplace2d_func 100 100 0.01 1.0
	echo -e "100 100 0.01 1.0" | valgrind --tool=cachegrind ./laplace2d_func
