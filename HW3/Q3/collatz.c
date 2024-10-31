#include <stdio.h>

int main(int argc, char *argv[]){
  int num;
  if (argc == 1){
    printf("Format: user MUST input an integer larger than 1.\n ");
    return 1;
  }
  sscanf(argv[1], "%d", &num);

  while(num > 1){
    if(num % 2 == 0){
      num = num/2;
      printf("%d\n", num);
    }
    else{
      num = num * 3 + 1;
      printf("%d\n", num);
    }
  }

  printf("1\n");
  return 0;

}
