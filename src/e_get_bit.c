/**
 * @author T. Enikeev
 * enikeev.tg@gmail.com
 * @brief get bit value in registr of integer
 * @return value of bit in integer registr
 */

#include "../e_decimal.h"

int e_get_bit(int number, int registr) {
  int mask = 1 << registr;
  int result = mask & number;
  return result ? 1 : 0;
}
