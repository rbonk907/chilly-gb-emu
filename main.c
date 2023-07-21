#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "cartridge.h"


int main(int argc, char** argv){
  if (argc < 2) {
    printf("Need to provide a rom file\n");

    exit(EXIT_FAILURE);
  }

  printf("Opening rom: %s\n", argv[1]);

  FILE *rom = fopen(argv[1], "r");

  if (rom == NULL) {
    perror(argv[1]);
    exit(EXIT_FAILURE);
  }

  /**
   * Need to allocate space for the rom in memory. First
   * determine the size of the rom
  */
  fseek(rom, 0, SEEK_END); 
  long rom_size = ftell(rom); // the number of bytes in the rom
  rewind(rom); // move pointer back to beginning of file;

  /**
   * Allocate buffer for rom
  */
  uint8_t *buffer = malloc(rom_size);

  /**
   * Load rom into buffer
  */
  fread(buffer, 1, rom_size, rom);

  if ( fclose(rom) != 0) {
    perror("fclose");
    exit(EXIT_FAILURE);
  }

  struct HEADER cart_header;
  LoadCartridge(&cart_header, buffer);

  printf("selected game is: %s\n", cart_header.title);

  free(buffer);
  return EXIT_SUCCESS;  
}
