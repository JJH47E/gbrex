#include "logo_sprite.c"
#include "../globals.c"
#include "../text.c"
#include <stdbool.h>

#ifndef MENU_C
#define MENU_C

#define TICK_TOGGLE 45

uint8_t toggle_tip_ticks = 0;
bool is_tip_shown = true;

void init_menu() {
  for (uint8_t i = 0; i < 24; i++) {
    set_sprite_tile(i, 100 + i);
    uint8_t x = 56 + (8 * (i%8));
    uint8_t y = 30 + (8 * (i/8));
    move_sprite(i, x, y);
  }

  // Setup "Press Start"
  write_text("Press", 5, 24, 44, 120);
  write_text("Start", 5, 29, 92, 120);

  toggle_tip_ticks = TICK_TOGGLE;
}

void show_text() {
  for (uint8_t i = 0; i < 5; i++) {
    move_sprite(24 + i, 44 + (i * 8), 120);
  }

  for (uint8_t i = 0; i < 5; i++) {
    move_sprite(29 + i, 92 + (i * 8), 120);
  }
}

void hide_text() {
  for (uint8_t i = 0; i < 10; i++) {
    move_sprite(24 + i, 0, 0);
  }
}

void tick_menu() {
  toggle_tip_ticks--;

  if (toggle_tip_ticks == 0) {
    if (is_tip_shown) {
      hide_text();
    } else {
      show_text();
    }

    is_tip_shown = !is_tip_shown;
    toggle_tip_ticks = TICK_TOGGLE;
  }

  if (joypad() & J_START) {
    transition_scene(INGAME);
  }
}

void dispose_menu() {
  // Move all sprites off-screen
  for (uint8_t i = 0; i < 40; i++) {
    move_sprite(i, 0, 0);
  }
}

#endif