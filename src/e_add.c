/**
 * @author T. Enikeev
 * enikeev.tg@gmail.com
 * @brief binary sum
 *
 * @param 'value' is the number function should get 'bit_value'.
 * @param 'bit_pos' is the bit position of the number bit function should get.
 *
 * @return error codes:
 * 0 - OK
 * 1 - the number is too large or equal to infinity
 * 2 - the number is too small or equal to negative infinity
 */

#include "../e_decimal.h"

// version for int type of value by each bit processing:
int e_add(int value_1, int value_2, int* result) {
  *result = 0;
  if (!value_1) *result = value_2;
  if (!value_2) *result = value_1;
  if (!*result) {
    int bit_value_1 = 0;
    int bit_value_2 = 0;
    int bit_buffer = 0;
    int result_bit = 0;
    for (int i = 0; i < 32; i++) {
      bit_value_1 = e_get_bit(value_1, i);
      bit_value_2 = e_get_bit(value_2, i);
      result_bit = bit_value_1 ^ bit_value_2;
      result_bit ^= bit_buffer;
      bit_buffer = (bit_value_1 & bit_value_2) |
                   ((bit_value_1 ^ bit_value_2) & bit_buffer);
      e_set_bit(result, i, result_bit);
    }
  }
  return 0;
}

// version for int type of value by recursion:
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
