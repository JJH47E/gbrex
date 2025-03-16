#include <stdbool.h>
#include "../globals.c"
#include "../rand.c"
#include "scoreboard.c"

#ifndef CACTI_C
#define CACTI_C

#define SPAWN_POSITION 190

uint8_t cactus_y[MAX_CACTI] = {0, 0, 0};
uint8_t cactus_x[MAX_CACTI] = {0, 0, 0};
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

void scroll_cactus(uint8_t cactus_index, int8_t delta_x, int8_t delta_y) {
  uint8_t target_x = cactus_x[cactus_index] + delta_x;
  uint8_t target_y = cactus_y[cactus_index] + delta_y;
  
  move_cactus(cactus_index, target_x, target_y);
}

void despawn_cactus(uint8_t cactus_index) {
  move_cactus(cactus_index, 0, 0);
  is_present[cactus_index] = false;

  uint8_t max_ticks = 0;
  uint8_t max_ticks_index = 0;

  for (uint8_t i = 0; i < MAX_CACTI; i++) {
    if (respawn_ticks[i] > max_ticks) {
      max_ticks = respawn_ticks[i];
      max_ticks_index = i;
    }
  }

  // This could be better
  if (max_ticks < 30) {
    max_ticks = 30;
  }

  uint8_t respawn_delta = get_random(30, 256 - max_ticks);
  respawn_ticks[cactus_index] = max_ticks + respawn_delta;
}

void respawn_cactus(uint8_t cactus_index) {
  move_cactus(cactus_index, SPAWN_POSITION, GROUND_Y);
  is_present[cactus_index] = true;
}

void tick_cactus() {
  for (uint8_t i = 0; i < MAX_CACTI; ++i) {
    if (is_present[i]) {
      scroll_cactus(i, -2, 0);

      // Integer under-flow is a feature. If off screen, despawn & increment score
      if (cactus_x[i] > 200) {
        if (cactus_x[i] < 235) {
          increment_score();
          despawn_cactus(i);
        }
      }
    } else {
      if (respawn_ticks[i] <= 0) {
        respawn_cactus(i);
      }
    }

    if (respawn_ticks[i] > 0) {
      respawn_ticks[i]--;
    }
  }
}

void init_cacti() {
  init_rand();

  set_sprite_tile(4, 4);
  set_sprite_tile(5, 5);
  set_sprite_tile(6, 6);
  set_sprite_tile(7, 7);

  move_cactus(0, 160, GROUND_Y);

  for (uint8_t i = 0; i < MAX_CACTI; ++i) {
    set_sprite_tile(cactus_sprite_indices[i][0], 4);
    set_sprite_tile(cactus_sprite_indices[i][1], 5);
    set_sprite_tile(cactus_sprite_indices[i][2], 6);
    set_sprite_tile(cactus_sprite_indices[i][3], 7);

    despawn_cactus(i);
  }
}

#endif