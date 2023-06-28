/**
 * @author T. Enikeev
 * @brief Set functions for e_decimal library
 */

#include "../e_decimal.h"

/// @brief Set sign to e_decimal number
/// @version v.1
/// @param value is e_decimal that function should set sign.
/// @param sign is sign code:
///             0 - positive
///             1 - negative
void e_set_sign_v1(e_decimal* value, int sign) {
  e_set_bit(value, 127, sign);
}

/// @brief Set scale to e_decimal value. Scale is 16-23 bits of
///        bits[3] of e_decimal number
/// @version v.1
/// @param value is e_decimal that function should set scale value
/// @param scale is scale factor
void e_set_scale_v1(e_decimal* value, int scale) {
  int sign = e_get_sign(*value);
  value->bits[3] = (scale << 16) & SCALE_MASK;  // & if scale is greater 8 bits
  e_set_sign(value, sign);
}
