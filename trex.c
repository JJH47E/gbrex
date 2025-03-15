#include <gb/gb.h>
#include <gb/drawing.h>
#include <stdio.h>
#include <string.h>
#include "trex_init.c"
#include "cacti.c"

void main(void)
{
  init_trex();
  init_cacti();
  
  SHOW_SPRITES;
  
  while(1) {
    wait_vbl_done();

    tick_trex();
    tick_cactus();

    if (joypad() & J_A) {
      try_jump_trex();
    }

    delay(20);
  }
}
