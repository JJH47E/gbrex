#include <stdio.h>
#include <gb/gb.h>
#include "globals.c"
#include "game/game.c"
#include "menu/menu.c"
#include "game_over/game_over.c"
#include "sprites/alphabet.c"
#include "sprites/numbers.c"
#include "game/cactus_sprite.c"
#include "game/trex_sprite.c"
#include "menu/logo_sprite.c"

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
  
  SHOW_SPRITES;
  
  while(1) {
    vsync();

    if (loading_new_scene) {
      switch (game_state) {
        case MENU:
          init_menu();
          break;
        case INGAME:
          init_game();
          break;
        case GAMEOVER:
          init_game_over();
        default:
          break;
      }
      loading_new_scene = false;
    }

    switch (game_state) {
      case MENU:
        tick_menu();
        break;
      case INGAME:
        tick_game();
        break;
      case GAMEOVER:
        tick_game_over();
      default:
        break;
    }

    delay(15);
  }
}
