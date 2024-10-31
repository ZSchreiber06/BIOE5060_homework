#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef MY_2D_LAPLACE_SOLVER_H_
#define MY_2D_LAPLACE_SOLVER_H_
struct Grid2D {
  int Nx;
  int Ny;
  double tol;
  double omega;
  double **field[2];
};
typedef struct Grid2D grid;
void get_input(grid *grid2d, int argc, char **argv);
void init_domain(grid *grid2d);
void update_domain(grid *grid2d);
void free_domain(grid *grid2d);
#endif
