/**
 * @author T. Enikeev
 * @brief Some internal functions for e_decimal library
 */

#include "../e_decimal.h"

/// @brief Checking if e_decimal value is nill
/// @param value is e_decimal
/// @return Boolean flag:
///         0 -> value != 0
///         1 -> value == 0
int e_dec_is_nill(e_decimal value) {
  return !value.bits[0] && !value.bits[1] && !value.bits[2];
}

/// @brief Filling string str by binary representation of e_decimal number
/// @param value is e_decimal number
/// @return String contains binary representation of e_decimal number
char* e_dec_to_str(e_decimal* value) {
  static char str[129] = {0};
  str[128] = '\0';
  int i = 128;
  while (i--) str[127 - i] = e_get_bit(*value, i) + 48;
  return str;
}
