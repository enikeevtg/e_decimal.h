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

int e_add(e_decimal value_1, e_decimal value_2, e_decimal* result) {
  if (e_dec_is_nill(value_1))
    *result = value_2;
  else if (e_dec_is_nill(value_2))
    *result = value_1;
  else {
    // if (e_get_scale(value_1) != e_get_scale(value_2)) e_norm(&value_1, &value_2);
    int bit_value_1 = 0;   // value_1 current bit
    int bit_value_2 = 0;   // value_2 current bit
    int result_bit = 0;    // bit value that has to be set to the result bit
    int bit_overflow = 0;  // current result bit overflow buffer
    for (int i = 0; i < 96; i++) {
      bit_value_1 = e_get_bit(value_1, i);
      bit_value_2 = e_get_bit(value_2, i);
      result_bit = (bit_value_1 + bit_value_2 + bit_overflow) % 2;
      bit_overflow = (bit_value_1 + bit_value_2 + bit_overflow) / 2;
      e_set_bit(result, i, result_bit);
    }
  }
  return 0;
}
