/**
 * @author T. Enikeev
 * enikeev.tg@gmail.com
 * @brief Set the bit_value (0 or 1) to the bit_pos bit of the value.
 *
 * @param 'value' is pointer to number that should be changed.
 * @param 'bit_pos' is the bit position of the 'value' that should be set.
 * @param 'bit_value' is value of the 'value' bit in position 'bit_pos'
 * that should be in the result.
 *
 * @warning If the bit_pos > 95 (31 for int), function doesn't make changes.
 */

#include "../e_decimal.h"

/* shift to right function */
e_decimal e_shift_to_right(e_decimal value, int offset) {
  offset = offset % 96;
  if (offset) {
    int j = 0;
    for (; j + offset <= 95; j++) {
      int bit = e_get_bit(value, j + offset);
      e_set_bit(&value, j, bit);
    }
    for (; j <= 95; j++) e_set_bit(&value, j, FALSE);
  }
  return value;
}

/* shift to left function */
e_decimal e_shift_to_left(e_decimal value, int offset) {
  offset = offset % 96;
  if (offset) {
    int j = 95;
    for (; j - offset >= 0; j--) {
      int bit = e_get_bit(value, j - offset);
      e_set_bit(&value, j, bit);
    }
    for (; j >= 0; j--) e_set_bit(&value, j, FALSE);
  }
  return value;
}
