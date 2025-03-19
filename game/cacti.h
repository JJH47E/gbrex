#ifndef CACTI_H
#define CACTI_H

#include <stdint.h>
#include "../globals.h"

extern uint8_t cactus_y[MAX_CACTI];
extern uint8_t cactus_x[MAX_CACTI];
extern bool is_present[MAX_CACTI];

void init_cacti(void);
void tick_cacti(void);

#endif