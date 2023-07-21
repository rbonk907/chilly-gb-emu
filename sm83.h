#include <stdint.h>

struct sm83_cpu {
  // registers
  uint8_t A;
  uint8_t F;
  uint8_t B;
  uint8_t C;
  uint8_t D;
  uint8_t E;
  uint8_t H;
  uint8_t L;

  uint16_t SP;
  uint16_t PC;

  // instruction set
  int (*instructions[16 * 16])();
};


struct sm83_cpu* cpu_init();

int nop();