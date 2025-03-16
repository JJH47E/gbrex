#include "logo_sprite.c"
#include "../globals.c"
#include "../text.c"

#ifndef MENU_C
#define MENU_C

void init_menu() {
  for (uint8_t i = 0; i < 24; i++) {
    set_sprite_tile(i, 100 + i);
    uint8_t x = 50 + (8 * (i%8));
    uint8_t y = 50 + (8 * (i/8));
    move_sprite(i, x, y);
  }

  // Setup "Press Start"
  write_text("Press StartZZ", 13, 24, 50, 120);
}

void tick_menu() {

}

#endif