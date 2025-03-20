#include <stdio.h>
#include <gb/gb.h>
#include "../globals.h"

#define NB_DIGITS 39
#define NB_TENS 38
#define NB_HUNDREDS 37

void increment_score(void);
void reset_score(void);
void render_score(void);
void tick_score(void);
void init_score(void);

uint8_t unit_sprite_nb = 16;

void increment_score(void) {
    score++;
}

void reset_score(void) {
    score = 0;
}

void render_score(void) {
  uint8_t units = score % 10;
  set_sprite_tile(NB_DIGITS, 30 + units);

  uint8_t tens = score / 10;
  set_sprite_tile(NB_TENS, 30 + tens);

  uint8_t hundreds = score / 100;
  set_sprite_tile(NB_HUNDREDS, 30 + hundreds);
}

void tick_score(void) {
    render_score();
}

void init_score(void) {
  move_sprite(NB_DIGITS, 150, 30);
  move_sprite(NB_TENS, 142, 30);
  move_sprite(NB_HUNDREDS, 134, 30);
}
