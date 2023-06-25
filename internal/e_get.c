/**
 * @author T. Enikeev
 * @brief Get functions for e_decimal library
 */

#include "../e_decimal.h"

/// @brief Get bit from binary representation of number.
/// @param value is the number that function should determine 'bit_value'.
/// @param bit_pos is the bit position of the number bit
///        function should determine.
/// @return Value of the number bit in position bit_pos
int e_get_bit(e_decimal value, int bit_pos) {
  unsigned int bit_mask = 1U << (bit_pos % 32);
  int bit_value = bit_mask & value.bits[bit_pos / 32];
  return bit_value ? 1 : 0;
}

/// @brief Get sign of e_decimal number
/// @param value is e_decimal that function should determine sign.
/// @return Sign code:
///         0 - positive
///         1 - negative
int e_get_sign(e_decimal value) {
  return e_get_bit(value, 127);
}

/// @brief Get scale of e_decimal value. Scale is 16-23 bits of
///        bits[3] of e_decimal number.
/// @version v.2
/// @param value is e_decimal that function should determine scale value.
/// @return Scale of e_decimal value
int e_get_scale(e_decimal value) {
  int mask = 0b00000000111111110000000000000000;
  int scale = (value.bits[3] & mask) >> 16;
  return scale;
}

/// @brief Get scale of e_decimal value
/// @version v.1
/// @param value is e_decimal
/// @return Scale of e_decimal value
/// @bug It function doesn't work because shift function for mantissa only!
int e_get_scale_bug(e_decimal value) {
  e_set_sign(&value, 0);
  e_decimal scale = e_shift_to_right(value, 16);
  return scale.bits[3];
}
