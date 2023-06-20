/**
 * @author T. Enikeev
 * enikeev.tg@gmail.com
 * @brief get the value of the number bit in position bit_pos
 * (in count from right side)
 * @return value of the number bit in position bit_pos
 */

#include "../s21_decimal.h"

int s21_get_bit(int number, int bit_pos) {
  int mask = 1U << bit_pos;
  int bit_value = mask & number;
  return bit_value ? 1 : 0;
}
