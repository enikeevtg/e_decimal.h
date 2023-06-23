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

int e_add(e_decimal val_1, e_decimal val_2, e_decimal* result) {
  if (!val_1.bits[_low] && !val_1.bits[_mid] && !val_1.bits[_high])
    *result = val_2;
  else if (!val_2.bits[_low] && !val_2.bits[_mid] && !val_2.bits[_high])
    *result = val_1;
  else {
    int bit_val_1 = 0;     // val_1 current bit
    int bit_val_2 = 0;     // val_2 current bit
    int result_bit = 0;    // bit value that has to be set to the result bit
    int bit_overflow = 0;  // current result bit overflow buffer
    for (int i = 0; i < 96; i++) {
      bit_val_1 = e_get_bit(val_1, i);
      bit_val_2 = e_get_bit(val_2, i);
      result_bit = (bit_val_1 + bit_val_2 + bit_overflow) % 2;
      bit_overflow = (bit_val_1 + bit_val_2 + bit_overflow) / 2;
      e_set_bit(result, i, result_bit);
    }
  }
  return 0;
}
