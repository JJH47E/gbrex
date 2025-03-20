#include <stdio.h>
#include <gb/gb.h>
#include "../globals.h"
#include "../text.h"

#define NB_DIGITS 39
#define NB_TENS 38
#define NB_HUNDREDS 37

void render_score(void);
void increment_score(void);
void reset_score(void);
void init_score(void);

uint8_t unit_sprite_nb = 16;

void increment_score(void) {
    score++;
    render_score();
}

void reset_score(void) {
    score = 0;
}

void render_score(void) {
  char score_buffer[3];
  sprintf(score_buffer, "%02d", score);
  write_text(score_buffer, 3, 37, 134, 30);
}

void init_score(void) {
  render_score();
}
