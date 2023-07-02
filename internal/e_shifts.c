/**
 * @author T. Enikeev
 * @brief Shift functions for e_decimal number 
 */

#include "../e_decimal.h"

/// @brief shift to right side function
/// @param value is decimal
/// @param offset is shift offset
/// @return 
e_decimal e_shift_to_right(e_decimal value, int offset) {
  if (offset) {
    int i = 0;
    for (; i + offset < MANTISSA_LEN; i++) {
      int bit = e_get_bit(value, i + offset);
      e_set_bit(&value, i, bit);
    }
    for (; i < MANTISSA_LEN; i++) e_set_bit(&value, i, 0);
  }

  return value;
}

/// @brief shift to left side function
/// @param value is decimal
/// @param offset is shift offset
/// @return 
e_decimal e_shift_to_left(e_decimal value, int offset) {
  if (offset) {
    int i = MANTISSA_LEN - 1;
    for (; i - offset >= 0; i--) {
      int bit = e_get_bit(value, i - offset);
      e_set_bit(&value, i, bit);
    }
    for (; i >= 0; i--) e_set_bit(&value, i, 0);
  }

  return value;
}

