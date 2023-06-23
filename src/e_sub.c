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

int e_sub(e_decimal value_1, e_decimal value_2, e_decimal* result) {
  printf("         value_1: %s\n", e_dec_to_str(&value_1));
  printf("         value_2: %s\n", e_dec_to_str(&value_2));
  e_bin_convert(&value_2);
  e_add(value_1, value_2, result);
  printf("summation result: %s\n", e_dec_to_str(result));
  if (!e_get_bit(*result, 95)) e_bin_convert(result);
  return 0;
}
