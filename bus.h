#include <stdint.h>

/** 
 * the bus has a 16-bit address space that returns an 8-bit value
*/

uint8_t read(uint16_t address); // returns value stored at given address

void write(uint16_t address, uint8_t value); // stores value in the given address