#ifndef GLOBALS_C
#define GLOBALS_C

#include <ctype.h>

#define GROUND_Y 120
#define GRAVITY 1

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