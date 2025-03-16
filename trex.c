#include <gb/gb.h>
#include <gb/drawing.h>
#include <stdio.h>
#include <string.h>
#include "game/game.c"
#include "menu/menu.c"
#include "sprites/alphabet.c"

enum State {
  MENU,
  INGAME,
  GAMEOVER
};

enum State game_state;

// Load tiles into RAM
void load_tiles() {
  // Load logo data
  set_sprite_data(100, 24, logo_sprite_tiles);
  // Load cactus data
  set_sprite_data(4, 4, cactus_sprite_tiles);
  // Load TREX data
  set_sprite_data(0, 4, trex_sprite_tiles);
  // Load scoreboard data
  for (uint8_t i = 0; i < 10; i++) {
    set_sprite_data(30 + i, 1, number_sprites[i]);
  }
  // Load alphabet & whitespace data
  for (uint8_t i = 0; i < 27; i++) {
    set_sprite_data(40 + i, 1, alphabet_sprites[i]);
  }
}

void main(void)
{
  game_state = MENU;

  load_tiles();
  init_menu();
  //init_game();
  
  SHOW_SPRITES;
  
  while(1) {
    vsync();

    if (game_state == INGAME) {
      tick_game();
    } else if (game_state == MENU) {
      tick_menu();
    }


    delay(15);
  }
}
