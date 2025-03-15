#include "trex_sprite.c"
#include "globals.c"

#ifndef TREX_C
#define TREX_C

#define SPRITE_1 0
#define SPRITE_2 1
#define SPRITE_3 2
#define SPRITE_4 3
#define JUMP_STRENGTH -8

int velocity = 0;
int y = GROUND_Y;
int x = 40;

void move_trex(uint8_t target_x, uint8_t target_y) {
  x = target_x;
  y = target_y;

  move_sprite(SPRITE_1, x, y);
  move_sprite(SPRITE_2, x + 8, y);
  move_sprite(SPRITE_3, x, y + 8);
  move_sprite(SPRITE_4, x + 8, y + 8);
}

void tick_trex() {
  uint8_t temp_y = y;
  temp_y += velocity;
  if (temp_y >= GROUND_Y) {
      temp_y = GROUND_Y;
      velocity = 0;
  } else {
      velocity += GRAVITY;
  }

  if (y != temp_y) {
    move_trex(x, temp_y);
  }
}

void try_jump_trex() {
  if (y == GROUND_Y) {
    velocity = JUMP_STRENGTH;
  }
}

void init_trex() {
  set_sprite_data(0, 4, trex_sprite_tiles);

  set_sprite_tile(SPRITE_1, 0);
  set_sprite_tile(SPRITE_2, 1);
  set_sprite_tile(SPRITE_3, 2);
  set_sprite_tile(SPRITE_4, 3);

  move_trex(20, y);
}

#endif