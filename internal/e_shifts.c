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
    for (; i + offset <= MANTISSA_LEN; i++) {
      int bit = e_get_bit(value, i + offset);
      e_set_bit(&value, i, bit);
    }
    for (; i <= MANTISSA_LEN; i++) e_set_bit(&value, i, 0);
  }
  return value;
}

/// @brief shift to left side function
/// @param value is decimal
/// @param offset is shift offset
/// @return 
e_decimal e_shift_to_left(e_decimal value, int offset) {
  int max_offset = boundary_nills(value, LEFT_SIDE);
  offset = offset % (MANTISSA_LEN - 1);
  if (offset && (offset <= max_offset)) {
    int i = MANTISSA_LEN - 1;
    for (; i - offset >= 0; i--) {
      int bit = e_get_bit(value, i - offset);
      e_set_bit(&value, i, bit);
    }
    for (; i >= 0; i--) e_set_bit(&value, i, 0);
  }
  return value;
}

/// @brief Boundary nills in binary representation quantity calculation
/// @param value e_decimal number
/// @param side left or right side of number
/// @return Quantity of boundary nills in number
int boundary_nills(e_decimal value, int side) {
  int check_bit = (side == RIGHT_SIDE) ? 0 : MANTISSA_LEN - 1;
  while (!e_get_bit(value, check_bit)) check_bit += side;
  check_bit = (side == RIGHT_SIDE) ? check_bit : (MANTISSA_LEN - 1 - check_bit);
  return check_bit;
}
