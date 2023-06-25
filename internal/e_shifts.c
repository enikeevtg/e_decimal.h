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
  int max_offset = boundary_nills(value, RIGHT_SIDE);
  offset = offset % 96;
  if (offset && (offset <= max_offset)) {
    int i = 0;
    for (; i + offset <= MANTISSA_MAX_BIT; i++) {
      int bit = e_get_bit(value, i + offset);
      e_set_bit(&value, i, bit);
    }
    for (; i <= MANTISSA_MAX_BIT; i++) e_set_bit(&value, i, 0);
  }
  return value;
}

/// @brief shift to left side function
/// @param value is decimal
/// @param offset is shift offset
/// @return 
e_decimal e_shift_to_left(e_decimal value, int offset) {
  int max_offset = boundary_nills(value, LEFT_SIDE);
  offset = offset % 96;
  if (offset && (offset <= max_offset)) {
    int i = MANTISSA_MAX_BIT;
    for (; i - offset >= 0; i--) {
      int bit = e_get_bit(value, i - offset);
      e_set_bit(&value, i, bit);
    }
    for (; i >= 0; i--) e_set_bit(&value, i, 0);
  }
  return value;
}

int boundary_nills(e_decimal value, int side) {
  int check_bit = (side == RIGHT_SIDE) ? 0 : MANTISSA_MAX_BIT;
  while (!e_get_bit(value, check_bit)) check_bit += side;
  check_bit = (side == RIGHT_SIDE) ? check_bit : (MANTISSA_MAX_BIT - check_bit);
  return check_bit;
}
