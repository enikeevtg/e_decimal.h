/**
 * @author T. Enikeev
 * enikeev.tg@gmail.com
 * @brief e_decimal numbers compare function
 * @param value_1 
 * @param value_2 
 * @return match code:
 *         1:  value_1 is greater than value_2
 *         0:  value_1 and value_2 are equal
 *        -1:  value_1 is less than value_2
 */

#include "../e_decimal.h"

int e_dec_comparison(e_decimal value_1, e_decimal value_2) {
  int match = 0;

  int sign_1 = e_get_sign(value_1);
  int sign_2 = e_get_sign(value_2);
  if (sign_1 == PLUS && sign_2 == MINUS) match = 1;
  if (sign_1 == MINUS && sign_2 == PLUS) match = -1;
  
  if (!match) {
    // e_norm(&value_1, &value_2);
    for (int i = 2; !match && i >= 0; i--) {
      if (value_1.bits[i] > value_2.bits[i]) match = 1;
      if (value_1.bits[i] < value_2.bits[i]) match = -1;
    }
  }

  if (sign_1 == MINUS && sign_2 == MINUS) match *= -1;

  return match;
}
