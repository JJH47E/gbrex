#include <stdbool.h>
#include <gb/gb.h>
#include "trex_init.h"
#include "cacti.h"
#include "../globals.h"
#include "scoreboard.h"
#include "../text.h"
#include "../bkg/bkg.h"

bool is_paused = false;
bool is_pause_toggled = false;

void init_game() {
  init_trex();
  init_cacti();
  init_score();

  write_text("Paused", 6, 30, 56, 68);
  hide_paused_text();
}

void show_paused_text() {
  for (uint8_t i = 0; i < 6; i++) {
    move_sprite(30 + i, 64 + (i * 8), 68);
  }
}

void hide_paused_text() {
  for (uint8_t i = 0; i < 6; i++) {
    move_sprite(30 + i, 0, 0);
  }
}

void tick_game() {
  if (joypad() & J_START) {
    is_paused = !is_paused;

    is_pause_toggled = true;

    waitpadup();
  }

  if (!is_paused) {
    if (is_pause_toggled) {
      hide_paused_text();
    }

    tick_bkg(2);
    tick_trex();
    tick_cactus();
    tick_score();

    if (y > GROUND_Y - 16) {
      for (uint8_t i = 0; i < MAX_CACTI; i++) {
        if (!is_present[i]) {
          continue;
        }

        uint8_t trex_center = x + 8;
        uint8_t cactus_center = cactus_x[i] + 8;
        uint8_t diff = 0;
        if (trex_center > cactus_center) {
          diff = trex_center - cactus_center;
        } else {
          diff = cactus_center - trex_center;
        }

        // 8 feels best when playing. Increase for difficulty
        if (diff <= 8) {
          transition_scene(GAMEOVER);
          return;
        }
      }
    }

    if (joypad() & J_A) {
      try_jump_trex();
    }
  } else {
    if (is_pause_toggled) {
      show_paused_text();
    }
  }

  is_pause_toggled = false;
}

void dispose_game() {
  // Move all sprites off-screen
  for (uint8_t i = 0; i < 40; i++) {
    move_sprite(i, 0, 0);
  }
}
