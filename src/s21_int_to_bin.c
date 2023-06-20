/**
 * @author T. Enikeev
 * enikeev.tg@gmail.com
 * @brief converting from integer to binary form
 * @return array of values of the number bits
 */

#include "../s21_decimal.h"

int* s21_int_to_bin(int number) {
  static int _0b_number[32];
  int index = 31;
  int bit_pos = 0;
  while (index) {
    _0b_number[index] = s21_get_bit(number, bit_pos);
    index--;
    bit_pos++;
  }
  return _0b_number;
}
