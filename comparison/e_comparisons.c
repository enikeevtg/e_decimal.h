/**
 * @author T. Enikeev
 * enikeev.tg@gmail.com
 * @brief e_decimal numbers comparison operators
 * @param value_1 
 * @param value_2 
 * @return match code:
 *         TRUE
 *         FALSE
 */


#include "../e_decimal.h"

int e_is_less(e_decimal value_1, e_decimal value_2) {
  return e_dec_comparison(value_1, value_2) == -1 ? TRUE : FALSE;
}

int e_is_less_or_equal(e_decimal value_1, e_decimal value_2) {
  return e_dec_comparison(value_1, value_2) <= 0 ? TRUE : FALSE;
}

int e_is_greater(e_decimal value_1, e_decimal value_2) {
  return e_dec_comparison(value_1, value_2) == 1 ? TRUE : FALSE;
}

int e_is_greater_or_equal(e_decimal value_1, e_decimal value_2) {
  return e_dec_comparison(value_1, value_2) >= 0 ? TRUE : FALSE;
}

int e_is_equal(e_decimal value_1, e_decimal value_2) {
  return e_dec_comparison(value_1, value_2) == 0 ? TRUE : FALSE;
}

int e_is_not_equal(e_decimal value_1, e_decimal value_2) {
  return e_dec_comparison(value_1, value_2) != 0 ? TRUE : FALSE;
}
