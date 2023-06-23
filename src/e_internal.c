/**
 * @author T. Enikeev
 *
 * @brief Some internal functions for e_decimal library
 */

#include "../e_decimal.h"
// #include "e_internal.h"

int e_get_bit(e_decimal value, int bit_pos) {
  unsigned int bit_mask = 1U << (bit_pos % 32);
  int bit_value = bit_mask & value.bits[bit_pos / 32];
  return bit_value ? 1 : 0;
}

void e_set_bit(e_decimal* value, int bit_pos, int bit_value) {
    int bit_mask = 1U << (bit_pos % 32);
    if (bit_value)
      value->bits[bit_pos / 32] |= bit_mask;
    else
      value->bits[bit_pos / 32] &= ~bit_mask;
}

char* e_dec_to_str(e_decimal* value) {
  static char str[129] = {0};
  str[128] = '\0';
  int i = 128;
  while (i--) str[127 - i] = e_get_bit(*value, i) + 48;
  return str;
}

int boundary_nills(e_decimal value, int direction) {
  int check_bit = 0;
  while (!e_get_bit(value, check_bit)) check_bit += direction;
  return check_bit;
}

/* shift to right function */
e_decimal e_shift_to_right(e_decimal value, int offset) {
  int max_offset = boundary_nills(value, RIGHT_SHIFT);
  offset = offset % 96;
  if (offset && (offset <= max_offset)) {
    int i = 0;
    for (; i + offset <= 95; i++) {
      int bit = e_get_bit(value, i + offset);
      e_set_bit(&value, i, bit);
    }
    for (; i <= 95; i++) e_set_bit(&value, i, 0);
  }
  return value;
}

/* shift to left function */
e_decimal e_shift_to_left(e_decimal value, int offset) {
  int max_offset = boundary_nills(value, LEFT_SHIFT);
  offset = offset % 96;
  if (offset && (offset <= max_offset)) {
    int i = 95;
    for (; i - offset >= 0; i--) {
      int bit = e_get_bit(value, i - offset);
      e_set_bit(&value, i, bit);
    }
    for (; i >= 0; i--) e_set_bit(&value, i, 0);
  }
  return value;
}

void e_bin_convert(e_decimal* value) {
  for (int i = 0; i < 3; i++) value->bits[i] = ~value->bits[i];
  printf("inversion result: %s\n", e_dec_to_str(value));
  e_decimal big_1U = {{1, 0, 0, 0}};
  e_add(*value, big_1U, value);
  printf("     + 1U result: %s\n", e_dec_to_str(value));
}
