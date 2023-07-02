/**
 * @author T. Enikeev
 * @brief Some internal functions for e_decimal library
 */

#include "../e_decimal.h"

/// @brief Checking if e_decimal value is nill
/// @param value is e_decimal number
/// @return Boolean flag:
///         0 -> value != 0
///         1 -> value == 0
int e_dec_is_nill(e_decimal value) {
  return !value.bits[0] && !value.bits[1] && !value.bits[2];
}

/// @brief Making e_decimal value equal to nill
/// @param value is e_decimal number
void e_dec_reset(e_decimal* value) {
  for (int i = 0; i < 4; i++) value->bits[i] = 0;
}

/// @brief Boundary nills in binary representation quantity calculation
/// @param value e_decimal number
/// @param side left or right side of e_decimal number
/// @return Quantity of boundary nills in number
int e_boundary_nills(e_decimal value, int side) {
  int check_bit = (side == LEFT_SIDE) ? MANTISSA_LEN - 1 : 0;
  while (!e_get_bit(value, check_bit)) check_bit += side;
  check_bit = (side == RIGHT_SIDE) ? check_bit : (MANTISSA_LEN - 1 - check_bit);
  return check_bit;
}
