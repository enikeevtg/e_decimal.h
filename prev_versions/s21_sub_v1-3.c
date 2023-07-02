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

/// @version v.3: Ahmad approach
/// @param value_1 is the decreasing number
/// @param value_2 is the subtrahend
/// @param result is the pointer to result variable
///
/// @return error codes:
///         0 - OK
///         1 - the number is too large or equal to infinity
///         2 - the number is too small or equal to negative infinity
int e_sub(e_decimal value_1, e_decimal value_2, e_decimal* result) {
  if (e_dec_is_nill(value_1)) {
    e_set_sign(&value_2, !e_get_sign(value_2));
    *result = value_2;
  } else if (e_dec_is_nill(value_2)) {
    *result = value_1;
  } else {
    int bit_value_1 = 0;  // value_1 current bit
    int bit_value_2 = 0;  // value_2 current bit
    int bit_borrow = 0;   // current bit borrow status
    for (int i = 0; i <= MANTISSA_LEN; i++) {
      bit_value_1 = e_get_bit(value_1, i);
      bit_value_2 = e_get_bit(value_2, i);
      bit_value_1 += bit_borrow;
      if (bit_value_1 == 2) {
        bit_value_1 = 0;
        bit_borrow = 0;
      }
      if (bit_value_1 < bit_value_2) {
        bit_value_1 = 2;
        bit_borrow = 1;
      }
      e_set_bit(result, i, bit_value_1 - bit_value_2);
    }
    if (bit_borrow) {
      e_bin_convert(result);
      e_set_sign(result, 1);
    }
    if (e_get_sign(value_1) && !e_get_sign(value_2))
      e_set_sign(result, !e_get_sign(*result));
  }
  return 0;
}

/// @version v.2: direct approach
///               Doesn't work if (-5 - 1)
/// @param value_1 is the decreasing number
/// @param value_2 is the subtrahend
/// @param result is the pointer to result variable
///
/// @return error codes:
///         0 - OK
///         1 - the number is too large or equal to infinity
///         2 - the number is too small or equal to negative infinity
int e_sub_v2(e_decimal value_1, e_decimal value_2, e_decimal* result) {
  if (e_dec_is_nill(value_1)) {
    e_set_sign(&value_2, !e_get_sign(value_2));
    *result = value_2;
  } else if (e_dec_is_nill(value_2)) {
    *result = value_1;
  } else {
    int bit_value_1 = 0;  // value_1 current bit
    int bit_value_2 = 0;  // value_2 current bit
    int result_bit = 0;   // bit value that has to be set to the result bit
    int bit_borrow = 0;   // current bit borrow status
    for (int i = 0; i <= MANTISSA_LEN; i++) {
      bit_value_1 = e_get_bit(value_1, i);
      bit_value_2 = e_get_bit(value_2, i);
      bit_value_1 += bit_borrow;
      if (bit_value_1 == -1) {
        result_bit = 1 - bit_value_2;
      } else if (bit_value_1 == 0) {
        bit_borrow = -bit_value_2;
        result_bit = -2 * bit_borrow - bit_value_2;
      } else if (bit_value_1 == 1) {
        result_bit = bit_value_1 - bit_value_2;
        bit_borrow = 0;
      }
      e_set_bit(result, i, result_bit);
    }
    if (bit_borrow) {
      e_bin_convert(result);
      e_set_sign(result, 1);
    }
    if (e_get_sign(value_1) && !e_get_sign(value_2))
      e_set_sign(result, !e_get_sign(*result));
  }
  return 0;
}


/// @bug Result sign can be checked by 96-bit if e_add() makes summarize
///      including bit 96 
/// @version v.1: with two's complement representation using
/// @param value_1 is the decreasing number
/// @param value_2 is the subtrahend
/// @param result is the pointer to result variable
///
/// @return error codes:
///         0 - OK
///         1 - the number is too large or equal to infinity
///         2 - the number is too small or equal to negative infinity
int e_sub_v1(e_decimal value_1, e_decimal value_2, e_decimal* result) {
#ifdef DEBUG
  printf("         value_1: %s\n", e_dec_to_str(&value_1));
  printf("         value_2: %s\n", e_dec_to_str(&value_2));
#endif  // DEBUG
  if (e_dec_is_nill(value_1)) {
    e_set_sign(&value_2, e_get_sign(value_2));
    *result = value_2;
  } else if (e_dec_is_nill(value_2)) {
    *result = value_1;
  } else {
    e_bin_convert(&value_2);
    e_add(value_1, value_2, result);
#ifdef DEBUG
  // printf("summation result: %s\n", e_dec_to_str(result));  // DEBUG
#endif  // DEBUG
    if (!e_get_bit(*result, 96)) {  // CHECK E_ADD() FOR(...;condition;...)!
      e_bin_convert(result);
      e_set_sign(result, 1);
    }
    if (e_get_sign(value_1) && !e_get_sign(value_2))
      e_set_sign(result, !e_get_sign(*result));
  }
  return 0;
}
