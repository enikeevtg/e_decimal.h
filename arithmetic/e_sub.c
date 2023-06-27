/**
 * @author T. Enikeev
 * enikeev.tg@gmail.com
 * @brief three versions of two integer variables subtraction
 * by using differents approaches
 *
 * @param value_1 is the decreasing number
 * @param value_2 is the subtrahend
 * @param result is the pointer to result variable
 *
 * @return error codes:
 *         0 - OK
 *         1 - the number is too large or equal to infinity
 *         2 - the number is too small or equal to negative infinity
 */

#include "../e_decimal.h"

/// @version v.2: direct approach
/// @param value_1 is the decreasing number
/// @param value_2 is the subtrahend
/// @param result is the pointer to result variable
///
/// @return error codes:
///         0 - OK
///         1 - the number is too large or equal to infinity
///         2 - the number is too small or equal to negative infinity
int e_sub(e_decimal value_1, e_decimal value_2, e_decimal* result) {
  int error_code = 0;
  result->bits[0] = 0;
  result->bits[1] = 0;
  result->bits[2] = 0;
  result->bits[3] = 0;

  int sign_1 = e_get_sign(value_1);
  int sign_2 = e_get_sign(value_2);
  if (sign_1 == sign_2 == MINUS) {
    e_change_sign(&value_1);
    e_change_sign(&value_2);
    e_sub(value_2, value_1, result);
  }
  if (sign_1 == sign_2 == PLUS) {
    error_code = e_norm(&value_1, &value_2);  // error = 0 if norm success
    // if (e_)
  }
      int bit_value_1 = 0;  // value_1 current bit
      int bit_value_2 = 0;  // value_2 current bit
      int result_bit = 0;   // bit value that has to be set to the result bit
      int bit_borrow = 0;   // current bit borrow status
      for (int i = 0; i <= MANTISSA_MAX_BIT; i++) {
        bit_value_1 = e_get_bit(value_1, i);
        bit_value_2 = e_get_bit(value_2, i);
        bit_value_1 -= bit_borrow;
        if (bit_value_1 == -1) {
          result_bit = 1 - bit_value_2;
        } else if (bit_value_1 == 0) {
          bit_borrow = bit_value_2;
          result_bit = 2 * bit_borrow - bit_value_2;
        } else if (bit_value_1 == 1) {
          result_bit = bit_value_1 - bit_value_2;
          bit_borrow = 0;
        }
        e_set_bit(result, i, result_bit);
      }


  return error_code;
}


      // for (int i = 0; i <= MANTISSA_MAX_BIT; i++) {
      //   bit_value_1 = e_get_bit(value_1, i);
      //   bit_value_2 = e_get_bit(value_2, i);
      //   bit_value_1 += bit_borrow;
      //   if (bit_value_1 == -1) {
      //     result_bit = 1 - bit_value_2;
      //   } else if (bit_value_1 == 0) {
      //     bit_borrow = -bit_value_2;
      //     result_bit = -2 * bit_borrow - bit_value_2;
      //   } else if (bit_value_1 == 1) {
      //     result_bit = bit_value_1 - bit_value_2;
      //     bit_borrow = 0;
      //   }
