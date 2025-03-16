#include <rand.h>

#ifndef RAND_C
#define RAND_C

void init_rand() {
  UBYTE seed = DIV_REG;
  seed |= (UWORD)DIV_REG << 8;

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

#endif