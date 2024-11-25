#include <stdio.h>
#include "laplace2d_func.h"
void main(int argc, char **argv){
grid domain;
get_input(&domain, argc, argv);
init_domain(&domain);
update_domain(&domain);
free_domain(&domain);
}
gcc laplace2d_solver.c -o laplace2d_solver.c -g -Wall -pedantic