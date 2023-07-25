#include "cartridge.h"
#include "bus.h"

uint8_t read(uint16_t address) {
  if (address >= 0x0000 && address <= 0x7FFF) {
    return rom_buffer[address];
  }

  return 0x00; // return No Op by default
}

void write(uint16_t address, uint8_t value) {
  if (address >= 0x0000 && address <= 0x7FFF) {
    rom_buffer[address] = value;
  }

  return;
}
