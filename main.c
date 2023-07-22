#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "cartridge.h"
#include "sm83.h"
#include "bus.h"

#define QUIT 0

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
  rom_buffer = malloc(rom_size);

  /**
   * Load rom into buffer
  */
  fread(rom_buffer, 1, rom_size, rom);

  if ( fclose(rom) != 0) {
    perror("fclose");
    exit(EXIT_FAILURE);
  }

  struct HEADER cart_header;
  LoadCartridge(&cart_header, rom_buffer);

  printf("selected game is: %s\n", cart_header.title);

  struct sm83_cpu* cpu = cpu_init();
  
  printf("Program Counter: %x\n", cpu->PC);

  uint8_t opcode = read(0x0100);
  int (*pinstruction)() = cpu->instructions[opcode];
  pinstruction();
  // while(!QUIT) {
    // fetch
    /**
     * read the address stored in the program counter
     * and then increment the program counter.
    */

    // decode
    /**
     * Index into the instruction set using the
     * returned opcode from above. This should return a function
     * that will execute our instruction.
    */

    // execute
    /**
     * Call the returned function
    */
  // }

  free(rom_buffer);
  return EXIT_SUCCESS;  
}
