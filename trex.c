#include <gb/gb.h>
#include <gb/drawing.h>
#include <stdio.h>
#include <string.h>
#include "trex_init.c"
#include "cacti.c"
#include "globals.c"
#include "scoreboard.c"
#include <stdbool.h>

bool isPaused = false;

enum State {
  MENU,
  INGAME,
  GAMEOVER
};

enum State game_state;

void main(void)
{
  game_state = INGAME;
  set_increment_score_callback(increment_score);

  init_trex();
  init_cacti();
  init_score();
  
  SHOW_SPRITES;
  
  while(1) {
    vsync();

    if (game_state == INGAME) {
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

    delay(15);
  }
}
