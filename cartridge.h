#include <stdint.h>

struct HEADER {
  uint8_t entry[4];
  uint8_t logo[48];
  char title[17]; // add extra space for '\0'
  uint8_t manufacturer[4];
  uint8_t cgb_flag;
  uint8_t new_license[2];
  uint8_t sgb;
  uint8_t cart_type;
  uint8_t rom_size;
  uint8_t ram_size;
  uint8_t dest_code;
  uint8_t old_license;
  uint8_t rom_version;
  uint8_t header_checksum;
};

uint8_t *rom_buffer;

void LoadCartridge(struct HEADER *cart_header, uint8_t *buffer);