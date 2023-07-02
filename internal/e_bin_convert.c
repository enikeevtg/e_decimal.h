/**
 * @author T. Enikeev
 * @brief convertion from "Signed magnitude representation" to
 * "Two's complement representation"
 * @param value is e_decimal number
 */

#include "../e_decimal.h"

void e_bin_convert(e_decimal* value) {
  for (int i = 0; i < 3; i++) value->bits[i] = ~value->bits[i];
#ifdef DEBUG
  printf("inversion result: %s\n", e_dec_to_str(value));  // DEBUG
#endif  // DEBUG
  e_decimal big_1U = {{1, 0, 0, 0}};
  e_add(*value, big_1U, value);
#ifdef DEBUG
  printf("     + 1U result: %s\n", e_dec_to_str(value));  // DEBUG
#endif  // DEBUG
}
