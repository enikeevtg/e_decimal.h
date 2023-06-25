/**
 * @author T. Enikeev
 * @brief Get functions for e_decimal library
 */

#include "../e_decimal.h"

/// @brief Set bit to binary representation of number
/// @param value is the number that function should set 'bit_value'.
/// @param bit_pos is the bit position of the number bit function should set.
/// @param bit_value is bit value
void e_set_bit(e_decimal* value, int bit_pos, int bit_value) {
    int bit_mask = 1U << (bit_pos % 32);
    if (bit_value)
      value->bits[bit_pos / 32] |= bit_mask;
    else
      value->bits[bit_pos / 32] &= ~bit_mask;
}

/// @brief Set sign to e_decimal number
/// @param value is e_decimal that function should set sign.
/// @param sign is sign code:
///             0 - positive
///             1 - negative
void e_set_sign(e_decimal* value, int sign) {
  return e_set_bit(value, 127, sign);
}

/// @brief Set scale to e_decimal value. Scale is 16-23 bits of
///        bits[3] of e_decimal number.
/// @param value is e_decimal that function should set scale value.
/// @param scale is scale factor
void e_set_scale(e_decimal* value, int scale) {
  int sign = e_get_sign(*value);
  value->bits[4] = (scale << 16);
  e_set_sign(value, sign);
}
