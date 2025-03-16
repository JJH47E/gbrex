#ifndef TEXT_C
#define TEXT_C

// Writes text using sequential memory in OAM
void write_text(char* text, uint8_t str_len, uint8_t oam_start_nb, uint8_t x, uint8_t y) {
  for (uint8_t i = 0; i < str_len; i++) {
    set_sprite_tile(oam_start_nb + i, 40 + char_to_alphabet_index(text[i]));
    move_sprite(oam_start_nb + i, x + (8 * i), y);
  }
}

#endif