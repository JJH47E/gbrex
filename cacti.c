#include <stdbool.h>
#include "globals.c"
#include "cactus_sprite.c"

#define MAX_CACTI 3

uint8_t cactus_y[MAX_CACTI];
uint8_t cactus_x[MAX_CACTI];
uint8_t respawn_ticks[MAX_CACTI];
bool is_present[MAX_CACTI];
uint8_t cactus_sprite_indices[MAX_CACTI][4] = {
    {4, 5, 6, 7},
    {8, 9, 10, 11},
    {12, 13, 14, 15}
};

void move_cactus(uint8_t cactus_index, uint8_t target_x, uint8_t target_y) {
  cactus_x[cactus_index] = target_x;
  cactus_y[cactus_index] = target_y;

  move_sprite(cactus_sprite_indices[cactus_index][0], target_x, target_y);
  move_sprite(cactus_sprite_indices[cactus_index][1], target_x + 8, target_y);
  move_sprite(cactus_sprite_indices[cactus_index][2], target_x, target_y + 8);
  move_sprite(cactus_sprite_indices[cactus_index][3], target_x + 8, target_y + 8);
}

// Check for wrap?
void scroll_cactus(uint8_t cactus_index, int8_t delta_x, int8_t delta_y) {
  scroll_sprite(cactus_sprite_indices[cactus_index][0], delta_x, delta_y);
  scroll_sprite(cactus_sprite_indices[cactus_index][1], delta_x, delta_y);
  scroll_sprite(cactus_sprite_indices[cactus_index][2], delta_x, delta_y);
  scroll_sprite(cactus_sprite_indices[cactus_index][3], delta_x, delta_y);
}

void hide_cactus(int8_t cactus_index) {
  for (uint8_t i = 0; i < 4; i++) {
    hide_sprite(cactus_sprite_indices[cactus_index][i]);
  }
}

void tick_cactus() {
  for (uint8_t i = 0; i < MAX_CACTI; ++i) {
    scroll_cactus(i, -2, 0);

    if (is_present[i] == false) {
      if (respawn_ticks[i] <= 0) {
        // Spawn
        move_cactus(i, 160, GROUND_Y);
        is_present[i] = true;
      }
    }

    if (respawn_ticks[i] > 0) {
      respawn_ticks[i]--;
    }

    // Despawn if off screen
    if (cactus_x[i] < -16) {
        hide_cactus(i);

        // Generate number of ticks until it should respawn
        is_present[i] = false;
        respawn_ticks[i] = 140;
    }
  }
}

void init_cacti() {
  set_sprite_data(4, 4, cactus_sprite_tiles);

  set_sprite_tile(4, 4);
  set_sprite_tile(5, 5);
  set_sprite_tile(6, 6);
  set_sprite_tile(7, 7);

  move_cactus(0, 160, GROUND_Y);

  for (uint8_t i = 0; i < MAX_CACTI; ++i) {
    set_sprite_data((i + 1) * 4, 4, cactus_sprite_tiles);

    set_sprite_tile(cactus_sprite_indices[i][0], 4 + (i * 4));
    set_sprite_tile(cactus_sprite_indices[i][1], 5 + (i * 4));
    set_sprite_tile(cactus_sprite_indices[i][2], 6 + (i * 4));
    set_sprite_tile(cactus_sprite_indices[i][3], 7 + (i * 4));

    cactus_x[i] = 160 + (i * 60); // Space them out
    cactus_y[i] = GROUND_Y;
    respawn_ticks[i] = 0;
    is_present[i] = true;
    move_cactus(i, cactus_x[i], cactus_y[i]);
  }
}