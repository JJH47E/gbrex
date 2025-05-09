#include <stdio.h>
#include <gb/gb.h>
#include "game_over.h"
#include "../text.h"
#include "../globals.h"

void init_game_over(void);
void tick_game_over(void);

void init_game_over(void) {
  write_text("Game", 4, 0, 44, 30);
  write_text("Over", 4, 4, 92, 30);

  delay(400);

  write_text("Score", 5, 8, 44, 46);

  char score_buffer[3];
  sprintf(score_buffer, "%02d", score);
  write_text(score_buffer, 3, 13, 100, 46);

  delay(400);

  write_text("Press", 5, 16, 44, 96);
  write_text("A", 1, 21, 92, 96);
  write_text("to", 2, 22, 108, 96);
  write_text("play", 4, 26, 44, 112);
  write_text("again", 5, 30, 84, 112);
}

void tick_game_over(void) {
  if (joypad() & J_A) {
    // Being lazy, this should point to game/menu scene
    reset();
  }
}
