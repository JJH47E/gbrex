#include <ctype.h>

#ifndef GLOBALS_C
#define GLOBALS_C

#define GROUND_Y 120
#define GRAVITY 1
#define MAX_CACTI 3

enum State {
  MENU,
  INGAME,
  GAMEOVER
};

uint16_t score = 0;
enum State game_state = MENU;
bool loading_new_scene = false;

void transition_scene(enum State new_scene) {
  switch (game_state) {
    case MENU:
      dispose_menu();
      break;
    case INGAME:
      dispose_game();
      break;
    default:
      break;
  }

  waitpadup();

  loading_new_scene = true;
  game_state = new_scene;
}

uint8_t char_to_alphabet_index(uint8_t c) {
  if (isspace(c)) {
    return 0;
  } else if (isalpha(c)) {
    c = tolower(c);
    return c - 'a' + 1;
  } else {
    // Consider raising an error?
    return -1;
  }
}

#endif