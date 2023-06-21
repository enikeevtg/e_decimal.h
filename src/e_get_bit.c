/**
 * @author T. Enikeev
 * enikeev.tg@gmail.com
 * @brief get the value of the number bit in position bit_pos
 * (in count from right side)
 *
 * @param 'value' is the number function should get 'bit_value'.
 * @param 'bit_pos' is the bit position of the number bit function should get.
 *
 * @return 'bit_value' is value of the number bit in position bit_pos
 */

#include "../e_decimal.h"

// version for e_decimal type of value:
// int e_get_bit(e_decimal value, int bit_pos) {
//   unsigned int bit_mask = 1U << (bit_pos % 32);
//   int bit_value = bit_mask & value.bits[bit_pos / 32];
//   return bit_value ? 1 : 0;
// }

// version for int type of value:
int e_get_bit(int value, int bit_pos) {
  int bit_mask = 1U << bit_pos;
  int bit_value = bit_mask & value;
  return bit_value ? 1 : 0;
}
