#include <stdio.h>
#include "sm83.h"
#include "bus.h"

struct sm83_cpu cpu = {
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  {
    &nop, &not_impl, &ld_ind_bc_a, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl,
    &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl,
    &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl,
    &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl,
    &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl,
    &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl,
    &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl,
    &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl,
    &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl,
    &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl,
    &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl,
    &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl,
    &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl,
    &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl,
    &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl,
    &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl, &not_impl
  }
};

struct sm83_cpu* cpu_init()  {
  cpu.A = 0x11;
  cpu.F = 0x80;
  cpu.B = 0x00;
  cpu.C = 0x00;
  cpu.D = 0x00;
  cpu.E = 0x08;
  cpu.H = 0x00;
  cpu.L = 0x7C;
  cpu.SP = 0xFFFE;
  cpu.PC = 0x0100;

  return &cpu;
}

int nop() {
  printf("No Operation\n");

  return 0;
}

int not_impl() {
  printf("Instruction not implemented yet...");

  exit(0);
}

//************* Load Instructions *****************
int ld_ind_bc_a() {
  /**
   * 2 - machine cycles
   * 1 - Byte
  */
  uint16_t address = (cpu.B << 8) & cpu.C;
  write(address, cpu.A);
  return 2;
}