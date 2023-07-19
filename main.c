#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
  if (argc < 2) {
    printf("Need to provide a rom file\n");

    return EXIT_FAILURE;
  }

  printf("You have selected: %s\n", argv[1]);

  return EXIT_SUCCESS;  
}
