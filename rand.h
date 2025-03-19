#ifndef RAND_H
#define RAND_H

#include <stdint.h>

void init_rand(void);
uint8_t get_random(uint8_t min, uint8_t max);
uint8_t fast_random(uint8_t seed);
uint8_t get_diff(uint8_t rhs, uint8_t lhs);

#endif