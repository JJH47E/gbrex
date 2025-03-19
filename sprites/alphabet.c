#include <gb/gb.h>

#ifndef ALPHABET_C
#define ALPHABET_C

const uint8_t alphabet_sprites[27][16] = {
  // Whitespace
  {
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00},
  // A
  {
    0x3c,0x00,0x42,0x00,
    0x42,0x00,0x42,0x00,
    0x7e,0x00,0x42,0x00,
    0x42,0x00,0x42,0x00,
  },
  // B
  {
    0x7c,0x00,0x42,0x00,
    0x42,0x00,0x7c,0x00,
    0x42,0x00,0x42,0x00,
    0x42,0x00,0x7c,0x00,
  },
  // C
  {
    0x1e,0x00,0x20,0x00,
    0x40,0x00,0x40,0x00,
    0x40,0x00,0x40,0x00,
    0x20,0x00,0x1e,0x00,
  },
  // D
  {
    0x78,0x00,0x44,0x00,
    0x42,0x00,0x42,0x00,
    0x42,0x00,0x42,0x00,
    0x44,0x00,0x78,0x00,
  },
  // E
  {
    0x7c,0x00,0x40,0x00,
    0x40,0x00,0x78,0x00,
    0x40,0x00,0x40,0x00,
    0x40,0x00,0x7c,0x00,
  },
  // F
  {
    0x7c,0x00,0x40,0x00,
    0x40,0x00,0x70,0x00,
    0x40,0x00,0x40,0x00,
    0x40,0x00,0x40,0x00,
  },
  // G
  {
    0x3c,0x00,0x40,0x00,
    0x40,0x00,0x40,0x00,
    0x4e,0x00,0x42,0x00,
    0x42,0x00,0x3c,0x00,
  },
  // H
  {
    0x42,0x00,0x42,0x00,
    0x42,0x00,0x7e,0x00,
    0x42,0x00,0x42,0x00,
    0x42,0x00,0x42,0x00,
  },
  // I
  {
    0x38,0x00,0x10,0x00,
    0x10,0x00,0x10,0x00,
    0x10,0x00,0x10,0x00,
    0x10,0x00,0x38,0x00,
  },
  // J
  {
    0x7e,0x00,0x08,0x00,
    0x08,0x00,0x08,0x00,
    0x08,0x00,0x08,0x00,
    0x48,0x00,0x30,0x00,
  },
  // K
  {
    0x44,0x00,0x48,0x00,
    0x50,0x00,0x60,0x00,
    0x50,0x00,0x48,0x00,
    0x44,0x00,0x44,0x00,
  },
  // L
  {
    0x40,0x00,0x40,0x00,
    0x40,0x00,0x40,0x00,
    0x40,0x00,0x40,0x00,
    0x40,0x00,0x7c,0x00,
  },
  // M
  {
    0x42,0x00,0x66,0x00,
    0x5a,0x00,0x42,0x00,
    0x42,0x00,0x42,0x00,
    0x42,0x00,0x42,0x00,
  },
  // N
  {
    0x42,0x00,0x62,0x00,
    0x52,0x00,0x52,0x00,
    0x4a,0x00,0x4a,0x00,
    0x46,0x00,0x42,0x00,
  },
  // O
  {
    0x3c,0x00,0x42,0x00,
    0x42,0x00,0x42,0x00,
    0x42,0x00,0x42,0x00,
    0x42,0x00,0x3c,0x00,
  },
  // P
  {
    0x78,0x00,0x44,0x00,
    0x44,0x00,0x44,0x00,
    0x78,0x00,0x40,0x00,
    0x40,0x00,0x40,0x00,
  },
  // Q
  {
    0x38,0x00,0x44,0x00,
    0x44,0x00,0x44,0x00,
    0x44,0x00,0x54,0x00,
    0x7c,0x00,0x10,0x00,
  },
  // R
  {
    0x78,0x00,0x44,0x00,
    0x44,0x00,0x44,0x00,
    0x78,0x00,0x50,0x00,
    0x48,0x00,0x44,0x00,
  },
  // S
  {
    0x3e,0x00,0x40,0x00,
    0x40,0x00,0x3c,0x00,
    0x02,0x00,0x02,0x00,
    0x02,0x00,0x7c,0x00,
  },
  // T
  {
    0x7c,0x00,0x10,0x00,
    0x10,0x00,0x10,0x00,
    0x10,0x00,0x10,0x00,
    0x10,0x00,0x10,0x00,
  },
  // U
  {
    0x42,0x00,0x42,0x00,
    0x42,0x00,0x42,0x00,
    0x42,0x00,0x42,0x00,
    0x42,0x00,0x3c,0x00,
  },
  // V
  {
    0x42,0x00,0x42,0x00,
    0x42,0x00,0x42,0x00,
    0x42,0x00,0x24,0x00,
    0x24,0x00,0x18,0x00,
  },
  // W
  {
    0x42,0x00,0x42,0x00,
    0x24,0x00,0x18,0x00,
    0x18,0x00,0x24,0x00,
    0x42,0x00,0x42,0x00,
  },
  // X -  This is not right, but it's not used so will ignore
  {
    0x44,0x00,0x44,0x00,
    0x44,0x00,0x28,0x00,
    0x28,0x00,0x10,0x00,
    0x10,0x00,0x10,0x00,
  },
  // Y
  {
    0x44,0x00,0x44,0x00,
    0x44,0x00,0x28,0x00,
    0x28,0x00,0x10,0x00,
    0x10,0x00,0x10,0x00,
  },
  // Z
  {
    0x7e,0x00,0x02,0x00,
    0x04,0x00,0x08,0x00,
    0x10,0x00,0x20,0x00,
    0x40,0x00,0x7e,0x00
  },
};

#endif