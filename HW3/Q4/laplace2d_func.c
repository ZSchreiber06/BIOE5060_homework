#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "laplace2d_func.h"
//#include "laplace2d_solver.c"

#define ABS(x) (((x)>0)?(x):-(x))

int main(int argc, char *argv[]){
  double **field[2] = {NULL, NULL};
  double delta = 1e10, tol = 1e-4;
  int t, tk0, tk1, x, y, Nx = 0, Ny = 0, counter = 0;
  FILE *foutput;


//Read Command Parameters
 if (argc < 3){
  printf("Array format: cmd Nx Ny\n");
  return 0;
 }
sscanf(argv[1], "%d", &Nx);
sscanf(argv[2], "%d", &Ny);
sscanf(argv[3], "%lf", &tol);

printf("Nx=%d,Ny=%d,tol=%lf\n", Nx, Ny,tol);

// Allocate 3D array
for(t = 0; t < 2; t++){
  field[t] = (double **)malloc(Nx*sizeof(double *));

  for(x = 0; x < Nx; x++){
    field[t][x] = (double *)calloc(Ny, sizeof(double));
  }

  for(y = 0; y < Ny; y ++){
    field[t][0][y] = 1.0;
  }
}

printf("Initialize\n");

// Run until delta is lower than tol
counter = 0;
while(delta > tol){
  delta = 0.0;
  tk0 = (counter % 2);
  tk1 =! (counter % 2);

  for(x = 1; x < Nx - 1; x++){
    for(y = 1; y < Ny - 1; y++){
      field[tk1][x][y] = (field[tk0][x - 1][y] + field[tk0][x + 1][y] + field[tk0][x][y - 1] + field[tk0][x][y + 1])*0.25;
      delta += ABS(field[tk1][x][y] - field[tk0][x][y]);
    }
  }
  if(!((counter++) % 2)){
    printf("iteration = %d delta = %lf\n", counter, delta);
  }
}

printf("Simulation Complete\n");

foutput = fopen("laplaceoutput.txt", "wt");
for(x = 0; x < Nx; x++){
  for(y = 0; y < Ny; y++){
    fprintf(foutput, "%e\t", field[tk1][x][y]);
  }
  fprintf(foutput, "\n");
}
fclose(foutput);

printf("File Saved\n");

for(t = 0; t < 2; t++){
  for(x = 0; x < Nx; x++){
    free(field[t][x]);
  }
  free(field[t]);
}
}

