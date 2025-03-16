#include "logo_sprite.c"

#ifndef MENU_C
#define MENU_C

void init_menu() {
  for (uint8_t i = 0; i < 24; i++) {
    set_sprite_tile(i, 100 + i);
    uint8_t x = 50 + (8 * (i%8));
    uint8_t y = 50 + (8 * (i/8));
    move_sprite(i, x, y);
  }
}

void tick_menu() {

}

#endif