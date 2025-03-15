#include "globals.c"
#include "cactus_sprite.c"

uint8_t cactus_y = GROUND_Y;
uint8_t cactus_x = 160;

void move_cactus(uint8_t cactus_index, uint8_t target_x, uint8_t target_y) {
  cactus_x = target_x;
  cactus_y = target_y;

  move_sprite(4, cactus_x, cactus_y);
  move_sprite(5, cactus_x + 8, cactus_y);
  move_sprite(6, cactus_x, cactus_y + 8);
  move_sprite(7, cactus_x + 8, cactus_y + 8);
}

void scroll_cactus(int8_t delta_x, int8_t delta_y) {
  scroll_sprite(4, delta_x, delta_y);
  scroll_sprite(5, delta_x, delta_y);
  scroll_sprite(6, delta_x, delta_y);
  scroll_sprite(7, delta_x, delta_y);
}

void tick_cactus() {
  scroll_cactus(-2, 0);
}

void init_cacti() {
  set_sprite_data(4, 4, cactus_sprite_tiles);

  set_sprite_tile(4, 4);
  set_sprite_tile(5, 5);
  set_sprite_tile(6, 6);
  set_sprite_tile(7, 7);

  move_cactus(0, 160, GROUND_Y);
}