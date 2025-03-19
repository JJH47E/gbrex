#ifndef GLOBALS_HEADERS
#define GLOBALS_HEADERS

#include <stdint.h>
#include <stdbool.h>

#ifndef MAX_CACTI
#define MAX_CACTI 3
#endif

#ifndef GROUND_Y
#define GROUND_Y 112
#endif

#ifndef GRAVITY
#define GRAVITY 1
#endif

typedef enum
{
  MENU,
  INGAME,
  GAMEOVER
} State;

extern uint16_t score;
extern State game_state;
extern bool loading_new_scene;

void transition_scene(State new_scene);
uint8_t char_to_alphabet_index(uint8_t c);

#endif