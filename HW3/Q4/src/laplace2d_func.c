#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "laplace2d_func.h"
#define ABS(x) (((x)>0)?(x):-(x))

void get_input(grid *grid2d, int argc, char **argv){
 if (argc < 3){
  printf("Array format: cmd Nx Ny\n");
  return 0;
 }
int t, tk0, tk1, x, y, Nx, Ny, counter = 0;
sscanf(argv[1], "%d", grid2d->Nx);
sscanf(argv[2], "%d", grid2d->Ny);
sscanf(argv[3], "%lf", grid2d->tol);

printf("Nx=%d,Ny=%d,tol=%lf\n", grid2d->Nx, grid2d->Ny, grid2d->tol);
  // use grid2d->Nx to replace Nx and other 5 
}


// dynamically allocate the 3D buffer, grid2d->field
// see how this is done in Unit 2-3’s notebook
void init_domain(grid *grid2d){
for(t = 0; t < 2; t++) {
    grid2d->field[t] = (double **)malloc(grid2d->Nx*sizeof(double *));

    for(x = 0; x < grid2d->Nx; x++) {
      grid2d->field[t][x] = (double *)calloc(grid2d->Ny, sizeof(double)); 
    }
    for(y = 0; y< grid2d->Ny; y++) {
      grid2d->field[t][0][y]=1.0;
    }
  }
}

// perform the time stepping, i.e. the while-loop in the notebook
void update_domain(grid *grid2d){
counter = 0;
while(delta > tol){
  delta = 0.0;
  tk0 = (counter % 2);
  tk1 =! (counter % 2);

  for(x = 1; x < grid2d->Nx - 1; x++){
    for(y = 1; y < grid2d->Ny - 1; y++){
      grid2d->field[tk1][x][y] = (grid2d->field[tk0][x - 1][y] + grid2d->field[tk0][x + 1][y] + grid2d->field[tk0][x][y - 1] + grid2d->field[tk0][x][y + 1])*0.25;
      delta += ABS(grid2d->field[tk1][x][y] - grid2d->field[tk0][x][y]);
    }
  }
  if(!((counter++) % 2)){
    printf("iteration = %d delta = %lf\n", counter, delta);
  }
}

printf("Simulation Complete\n");

}

// deallocate the buffer at the end
void free_domain(grid *grid2d){
  for(t = 0; t < 2; t++) {
    for(x = 0; x< grid2d->Nx; x++) {
      free(grid2d->field[t][x]);
    }
    free(grid2d->field[t]);
  }

}

