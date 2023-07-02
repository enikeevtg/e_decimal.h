/**
 * @author T. Enikeev
 * enikeev.tg@gmail.com
 * 
 * @brief two e_decimal numbers summation by using direct approach
 *
 * @param value_1 is the first member of sum
 * @param value_2 is the second member of sum
 * @param result is the pointer to result variable
 *
 * @return error codes:
 *         0 - OK
 *         1 - the number is too large or equal to infinity
 *         2 - the number is too small or equal to negative infinity
 */

#include <stdio.h>

#include "../e_decimal.h"

int e_add(e_decimal value_1, e_decimal value_2, e_decimal* result) {
  int error_code = OK;
  e_dec_reset(result);
  int sign_1 = e_get_sign(value_1);
  int sign_2 = e_get_sign(value_2);

  if (sign_1 == PLUS && sign_2 == PLUS) {
    error_code = e_add_alg(value_1, value_2, result);
  }
  if (sign_1 == MINUS && sign_2 == MINUS) {
    e_negate(value_1, &value_1);
    e_negate(value_2, &value_2);
    error_code = e_add_alg(value_1, value_2, result);
    if (!error_code) e_negate(*result, result);
  }

  if (sign_1 == PLUS && sign_2 == MINUS) {
    e_negate(value_2, &value_2);
    error_code = e_sub(value_1, value_2, result);
  }

  if (sign_1 == MINUS && sign_2 == PLUS) {
    e_negate(value_1, &value_1);
    error_code = e_sub(value_2, value_1, result);
  }

  return error_code;
}

int e_add_alg(e_decimal value_1, e_decimal value_2, e_decimal* result) {
  int error_code = OK;

  if (e_dec_is_nill(value_1))
    *result = value_2;
  else if (e_dec_is_nill(value_2))
    *result = value_1;
  else {
    // int error_code = e_norm(&value_1, &value_2);  // error = 0 if norm success
    int bit_value_1 = 0;   // value_1 current bit
    int bit_value_2 = 0;   // value_2 current bit
    int result_bit = 0;    // bit value that has to be set to the result bit
    int bit_overflow = 0;  // current result bit overflow buffer
    for (int i = 0; i < MANTISSA_LEN; i++) {
      bit_value_1 = e_get_bit(value_1, i);
      bit_value_2 = e_get_bit(value_2, i);
      result_bit = (bit_value_1 + bit_value_2 + bit_overflow) % 2;
      bit_overflow = (bit_value_1 + bit_value_2 + bit_overflow) / 2;
      e_set_bit(result, i, result_bit);
    }
  }
  return error_code;
}
