
laplace:
	gcc laplace2d_func.c laplace2d_func.h laplace2d_solver.c -o laplace2d
run: laplace
	./laplace2d 60 60 1e-5 1.6
	echo -e "60 60 1e-5 1.6" | valgrind --tool=cachegrind ./laplace2d_func
