#include "bkg.h"
#include <gb/gb.h>
#include "floor_map.h"

void init_floor() {
  set_bkg_tiles(0, 0, 32, 18, floor_map);
}

void tick_bkg(uint8_t scroll_speed) {
  scroll_bkg(scroll_speed, 0);
}
