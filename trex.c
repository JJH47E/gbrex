#include <gb/gb.h>
#include <gb/drawing.h>
#include <stdio.h>
#include <string.h>
#include "trex_init.c"

void main(void)
{
  init_trex();
  
  SHOW_SPRITES;
  
  while(1) {
      scroll_sprite(0, 1, 0);
      scroll_sprite(1, 1, 0);
      scroll_sprite(2, 1, 0);
      scroll_sprite(3, 1, 0);
      delay(100);
  }
}
