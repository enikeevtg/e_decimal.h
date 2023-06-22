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

#include "../e_integer.h"

/* shift to right function */
int e_shift_to_right(int value, int offset) {
  offset = offset % 32;
  if (offset) {
    int j = 0;
    for (; j + offset <= 31; j++) {
      int bit = e_get_bit(value, j + offset);
      e_set_bit(&value, j, bit);
    }
    for (; j <= 31; j++) e_set_bit(&value, j, FALSE);
  }
  return value;
}

/* shift to left function */
int e_shift_to_left(int value, int offset) {
  offset = offset % 32;
  if (offset) {
    int j = 31;
    for (; j - offset >= 0; j--) {
      int bit = e_get_bit(value, j - offset);
      e_set_bit(&value, j, bit);
    }
    for (; j >= 0; j--) e_set_bit(&value, j, FALSE);
  }
  return value;
}
