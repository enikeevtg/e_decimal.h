/**
 * @author T. Enikeev
 * enikeev.tg@gmail.com
 * @brief Set the bit_value (0 or 1) to the bit_pos bit of the value.
 *
 * @param 'value' is pointer to number that should be changed.
 * @param 'bit_pos' is the bit position of the 'value' that should be set.
 * @param 'bit_value' is value of the 'value' bit in position 'bit_pos'
 * that should be in the result.
 *
 * @warning If the bit_pos > 95 (31 for int), function doesn't make changes.
 */

#include "../e_decimal.h"

// version for e_decimal type of value:
// void e_set_bit(e_decimal* value, int bit_pos, int bit_value) {
//   if (bit_pos < 96) {
//     int bit_mask = 1U << (bit_pos % 32);
//     if (bit_value)
//       value->bits[bit_pos / 32] |= bit_mask;
//     else
//       value->bits[bit_pos / 32] &= ~bit_mask;
//   }
// }

// version for int type of value:
void e_set_bit(int* value, int bit_pos, int bit_value) {
  if (bit_pos < 32) {
    int bit_mask = 1U << bit_pos;
    if (bit_value)
      *value |= bit_mask;
    else
      *value &= ~bit_mask;
  }
}
