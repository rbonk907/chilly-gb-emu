#include "cartridge.h"

void LoadCartridge(struct HEADER *cart_header, uint8_t *buffer) {
  memcpy(cart_header->entry, &buffer[0x0100], 4);
  memcpy(cart_header->logo, &buffer[0x0104], 48);
  memcpy(cart_header->title, &buffer[0x0134], 16);
  cart_header->title[17] = '\0';
  memcpy(cart_header->manufacturer, &buffer[0x013F], 4);
  cart_header->cgb_flag = buffer[0x0143];
  memcpy(cart_header->new_license, &buffer[0x0144], 2);
  cart_header->sgb = buffer[0x0146];
  cart_header->cart_type = buffer[0x0147];
  cart_header->rom_size = buffer[0x0148];
  cart_header->ram_size = buffer[0x0149];
  cart_header->dest_code = buffer[0x014A];
  cart_header->old_license = buffer[0x014B];
  cart_header->rom_version = buffer[0x014C];
  cart_header->header_checksum = buffer[0x014D];
  
  return;
}