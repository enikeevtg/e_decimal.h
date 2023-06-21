/**
 * @author T. Enikeev
 * enikeev.tg@gmail.com
 * @brief converting from integer to binary form
 * @return array of values of the number bits
 */

#include "../e_decimal.h"

int* e_int_to_bin(int number) {
  static int _0b_number[32];
  int index = 31;
  int bit_pos = 0;
  while (index) {
    _0b_number[index] = e_get_bit(number, bit_pos);
    index--;
    bit_pos++;
  }
  return _0b_number;
}
