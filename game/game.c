#include "trex_init.c"
#include "cacti.c"
#include "../globals.c"
#include "scoreboard.c"
#include <stdbool.h>

#ifndef GAME_C
#define GAME_C

bool isPaused = false;

void init_game() {
  init_trex();
  init_cacti();
  init_score();
}

void tick_game() {
  if (!isPaused) {
    tick_trex();
    tick_cactus();
    tick_score();

    if (joypad() & J_A) {
      try_jump_trex();
    }
  } else {

  }

  if (joypad() & J_START) {
    isPaused = !isPaused;
    waitpadup();
  }
}

#endif