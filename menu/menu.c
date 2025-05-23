#include <stdbool.h>
#include <gb/gb.h>
#include "../globals.h"
#include "../text.h"

#define TICK_TOGGLE 45

void init_menu(void);
void show_text(void);
void hide_text(void);
void tick_menu(void);
void dispose_menu(void);

uint8_t toggle_tip_ticks = 0;
bool is_tip_shown = true;

void init_menu(void) {
  for (uint8_t i = 0; i < 24; i++) {
    set_sprite_tile(i, 100 + i);
    uint8_t x = 56 + (8 * (i%8));
    uint8_t y = 30 + (8 * (i/8));
    move_sprite(i, x, y);
  }

  // Setup "Press Start"
  write_text("Press", 5, 24, 44, 112);
  write_text("Start", 5, 29, 92, 112);

  toggle_tip_ticks = TICK_TOGGLE;
}

void show_text(void) {
  for (uint8_t i = 0; i < 5; i++) {
    move_sprite(24 + i, 44 + (i * 8), 112);
  }

  for (uint8_t i = 0; i < 5; i++) {
    move_sprite(29 + i, 92 + (i * 8), 112);
  }
}

void hide_text(void) {
  for (uint8_t i = 0; i < 10; i++) {
    move_sprite(24 + i, 0, 0);
  }
}

void tick_menu(void) {
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
    return;
  }
}

void dispose_menu(void) {
  // Move all sprites off-screen
  for (uint8_t i = 0; i < 40; i++) {
    move_sprite(i, 0, 0);
  }
}
