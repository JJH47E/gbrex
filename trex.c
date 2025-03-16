#include <gb/gb.h>
#include <gb/drawing.h>
#include <stdio.h>
#include <string.h>
#include "game/game.c"

enum State {
  MENU,
  INGAME,
  GAMEOVER
};

enum State game_state;

void main(void)
{
  game_state = INGAME;

  init_game();
  
  SHOW_SPRITES;
  
  while(1) {
    vsync();

    if (game_state == INGAME) {
      tick_game();
    }

    delay(15);
  }
}
