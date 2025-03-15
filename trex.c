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

    if (joypad() & J_A) {
      try_jump_trex();
    }
    tick_trex();
    tick_cactus();
    delay(20);
  }
}
