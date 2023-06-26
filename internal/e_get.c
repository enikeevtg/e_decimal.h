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
  int bit_mask = 1U << (bit_pos % 32);
  return (value.bits[bit_pos / 32] & bit_mask) ? 1 : 0;
}

/// @brief Get sign of e_decimal number
/// @version v.2
/// @param value is e_decimal that function should determine sign.
/// @return Sign code:
///         0 - positive
///         1 - negative
int e_get_sign(e_decimal value) {
  return (value.bits[3] & SIGN_MASK) >> 31;
}

/// @brief Get sign of e_decimal number
/// @version v.1
/// @param value is e_decimal that function should determine sign.
/// @return Sign code:
///         0 - positive
///         1 - negative
int e_get_sign_v1(e_decimal value) {
  return e_get_bit(value, 127);
}

/// @brief Get scale of e_decimal value. Scale is 16-23 bits of
///        bits[3] of e_decimal number.
/// @version v.3
/// @param value is e_decimal that function should determine scale value.
/// @return Scale of e_decimal value
int e_get_scale(e_decimal value) {
  return (value.bits[3] & SCALE_MASK) >> 16;
}

/// @warning [0-15] && [24-30] bits must equal 0!
/// @brief Get scale of e_decimal value. Scale is 16-23 bits of
///        bits[3] of e_decimal number.
/// @version v.2
/// @param value is e_decimal that function should determine scale value.
/// @return Scale of e_decimal value
int e_get_scale_v3(e_decimal value) {
  e_set_sign(&value, 0);
  return value.bits[3] >> 16;
}

/// @bug It function doesn't work because shift function for mantissa only!
/// @brief Get scale of e_decimal value
/// @version v.1
/// @param value is e_decimal
/// @return Scale of e_decimal value
int e_get_scale_v1(e_decimal value) {
  e_set_sign(&value, 0);
  e_decimal scale = e_shift_to_right(value, 16);
  return scale.bits[3];
}
