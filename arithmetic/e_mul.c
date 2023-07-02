/**
 * @author T. Enikeev
 * enikeev.tg@gmail.com
 * @brief two e_decimal numbers multiplication
 *
 * @param value_1 is the first multiplier
 * @param value_2 is the second multiplier
 * @param result is the pointer to result variable
 *
 * @return error codes:
 *         0 - OK
 *         1 - the number is too large or equal to infinity
 *         2 - the number is too small or equal to negative infinity
 */ 

#include "../e_decimal.h"

int e_mul(e_decimal value_1, e_decimal value_2, e_decimal *result) {
  int error_code = OK;
  e_set_result(value_1, value_2, result);  // result preset: scale and sign
  int bit_value_2 = 0;
  int max_offset_1 = e_boundary_nills(value_1, LEFT_SIDE);
  int scale_1 = e_get_scale(value_1);
  e_decimal ten = E_DEC_TEN;  // for scale reduction
  int offset_buf = 0;
  
  for (int i = 0; !error_code && i < MANTISSA_LEN; i++) {
    bit_value_2 = e_get_bit(value_2, i);
    if (bit_value_2) {
      // Shift possibility checking 
      while (i - offset_buf > max_offset_1 && scale_1 > 0) {
        e_div(value_1, ten, &value_1);
        e_div(*result, ten, result);
        scale_1--;
        max_offset_1++;
      }
      // Main algorithm
      if (i - offset_buf <= max_offset_1) {
        value_1 = e_shift_to_left(value_1, i - offset_buf);
        error_code = e_add(value_1, *result, result);
        offset_buf = i;
      } else {
        error_code = e_get_sign(*result) ? TOO_SMALL : TOO_LARGE;
        e_dec_reset(result);
      }
    }  // if (bit_value_2)
  }    // for

  return error_code;
}

void e_set_result(e_decimal val_1, e_decimal val_2, e_decimal* result) {
  e_dec_reset(result);
  result->bits[3] = val_1.bits[3];  // so scales will be equal
  int sign_1 = e_get_sign(val_1);
  int sign_2 = e_get_sign(val_2);
  int sign_res = (sign_1 + sign_2) % 2;
  e_set_sign(result, sign_res);
}
