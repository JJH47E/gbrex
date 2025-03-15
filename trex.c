#include <gb/gb.h>
#include <gb/drawing.h>
#include <stdio.h>
#include <string.h>
#include "trex_init.c"
#include "cacti.c"
#include "globals.c"
#include "scoreboard.c"

void main(void)
{
  set_increment_score_callback(increment_score);

  init_trex();
  init_cacti();
  
  SHOW_SPRITES;
  
  while(1) {
    vsync();

    tick_trex();
    tick_cactus();

    if (joypad() & J_A) {
      try_jump_trex();
    }

    delay(20);
  }
}
