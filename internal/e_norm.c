/**
 * @author T. Enikeev
 * @brief Cast two e_decimal values to common scale
 * @param value_1 
 * @param value_2 
 * @return Error code:
 *         0 -> no errors
 *         1 -> one or two scales are greater than 28;
 */

#include "../e_decimal.h"

// int e_norm(e_decimal* value_1, e_decimal* value_2) {
//   int error = 0;
//   int scale_1 = e_get_scale(*value_1);
//   int scale_2 = e_get_scale(*value_2);
//   if (scale_1 > scale_2)
//     e_normalize(value_2, scale_2, scale_1);
//   else if (scale_1 < scale_2)
//     e_normalize(value_1, scale_1, scale_2);
//   return error;
// }

// void e_normalize(e_decimal* value, int scale_src, int scale_dest) {
//   /*some code*/
// }

int e_mul_10(e_decimal value, e_decimal* result) {
  e_decimal value_1 = e_shift_to_left(value, 1);
  e_decimal value_2 = e_shift_to_left(value, 3);
  e_add(value_1, value_2, result);
  return 0;
}
