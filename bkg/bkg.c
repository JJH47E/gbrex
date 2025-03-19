#include "floor_map.c"

#ifndef BKG_C
#define BKG_C

void init_floor() {
  set_bkg_tiles(0, 0, 32, 18, floor_map);
}

void tick_bkg(uint8_t scroll_speed) {
  scroll_bkg(scroll_speed, 0);
}

#endif