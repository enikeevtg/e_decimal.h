/**
 * @author T. Enikeev
 * enikeev.tg@gmail.com
 * @brief three versions of two integer variables summation
 * by using differents approaches
 *
 * @param 'value_1' and 'value_2' is the numbers have to be summarized.
 * @param 'result' is the pointer to result variable.
 *
 * @return error codes:
 * 0 - OK
 * 1 - the number is too large or equal to infinity
 * 2 - the number is too small or equal to negative infinity
 */

#include "../e_decimal.h"

/*
 v.3 for int type of value with 'div' and 'mod' operaions using
*/
int e_add(int value_1, int value_2, int* result) {
  *result = 0;
  if (!value_1) *result = value_2;
  if (!value_2) *result = value_1;
  if (!*result) {
    int bit_value_1 = 0;   // value_1 current bit
    int bit_value_2 = 0;   // value_2 current bit
    int result_bit = 0;    // value that has to be set to the result bit
    int bit_overflow = 0;  // current result bit overflow buffer
    for (int i = 0; i < 32; i++) {
      bit_value_1 = e_get_bit(value_1, i);
      bit_value_2 = e_get_bit(value_2, i);
      result_bit = (bit_value_1 + bit_value_2 + bit_overflow) % 2;
      bit_overflow = (bit_value_1 + bit_value_2 + bit_overflow) / 2;
      e_set_bit(result, i, result_bit);
    }
  }
  return 0;
}

/*
v.2 for int type of value with Boolean logical operations using
*/
// int e_add(int value_1, int value_2, int* result) {
//   *result = 0;
//   if (!value_1) *result = value_2;
//   if (!value_2) *result = value_1;
//   if (!*result) {
//     int bit_value_1 = 0;   // value_1 current bit
//     int bit_value_2 = 0;   // value_2 current bit
//     int result_bit = 0;    // value that has to be set to the result bit
//     int bit_overflow = 0;  // current result bit overflow buffer
//     for (int i = 0; i < 32; i++) {
//       bit_value_1 = e_get_bit(value_1, i);
//       bit_value_2 = e_get_bit(value_2, i);
//       result_bit = bit_value_1 ^ bit_value_2;
//       result_bit ^= bit_overflow;
//       bit_overflow = (bit_value_1 & bit_value_2) | ((bit_value_1 ^
//       bit_value_2) & bit_overflow);  // if current bits: (1+1) or (1+0 and +1
//       // from previous bits)
//       e_set_bit(result, i, result_bit);
//     }
//   }
//   return 0;
// }

/*
v.1 for int type of value with Boolean logical operations and recursion
using
*/
// int e_add(int value_1, int value_2, int* result) {
//   *result = 0;
//   if (!value_1) *result = value_2;
//   if (!value_2) *result = value_1;
//   if (!*result) {
//     int and_result = (value_1 & value_2) << 1;
//     int xor_result = value_1 ^ value_2;
//     if (and_result) e_add(and_result, xor_result, result);
//     else *result = xor_result;
//   }
//   return 0;
// }
