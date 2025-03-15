#include "trex_sprite.c"
#include "globals.c"

#define SPRITE_1 0
#define SPRITE_2 1
#define SPRITE_3 2
#define SPRITE_4 3

void move_trex(uint8_t x, uint8_t y) {
  move_sprite(SPRITE_1, x, y);
  move_sprite(SPRITE_2, x + 8, y);
  move_sprite(SPRITE_3, x, y + 8);
  move_sprite(SPRITE_4, x + 8, y + 8);
}

void init_trex() {
  set_sprite_data(0, 4, trex_sprite_tiles);

  set_sprite_tile(SPRITE_1, 0);
  set_sprite_tile(SPRITE_2, 1);
  set_sprite_tile(SPRITE_3, 2);
  set_sprite_tile(SPRITE_4, 3);

  move_trex(40, 80);
}
