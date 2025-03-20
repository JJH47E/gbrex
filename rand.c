#include <stdio.h>
#include <gb/gb.h>
#include <rand.h>
#include "rand.h"

void init_rand(void);
uint8_t get_random(uint8_t min, uint8_t max);
uint8_t fast_random(uint8_t seed);
uint8_t get_diff(uint8_t rhs, uint8_t lhs);

void init_rand(void) {
  UBYTE seed = DIV_REG;
  seed |= (UWORD)DIV_REG << 4;

  initarand(seed);
}

// Generates a random number between 0 & 255 - check this
uint8_t get_random(uint8_t min, uint8_t max) {
  uint8_t r = arand();

  if (r < min) {
    return min;
  }

  if (r > max) {
    return max;
  }

  return r;
}

uint8_t fast_random(uint8_t seed) {
    seed = seed ^ (seed >> 4);
    seed = seed * 117;
    seed = seed ^ (seed >> 4);
    return seed;
}

uint8_t get_diff(uint8_t rhs, uint8_t lhs) {
  if (rhs > lhs) {
    return rhs - lhs;
  } else {
    return lhs - rhs;
  }
}
