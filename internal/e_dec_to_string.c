/**
 * @author T. Enikeev
 */

#include "../e_decimal.h"

/// @brief Filling string str by binary representation of e_decimal number
/// @param value is pointer to e_decimal number
/// @return String contains binary representation of e_decimal number
char* e_dec_to_str(e_decimal* value) {
  static char str[129] = {0};
  str[128] = '\0';
  int i = 128;
  while (i--) str[127 - i] = e_get_bit(*value, i) + 48;
  return str;
}

/// @brief Filling string str by binary representation of e_decimal number
///        with splited bytes
/// @param value is pointer to e_decimal number
/// @return String contains binary representation of e_decimal number
///         with splited bytes
char* e_dec_to_split_str(e_decimal* value) {
  static char str[132] = {0};
  int i = 128;
  int j = 0;
  while (i--) {
    str[j] = e_get_bit(*value, i) + 48;
    if (i % 32 == 0) {
      j++;
      str[j] = ' ';
    }
    j++;
  }
  str[131] = '\0';
  return str;
}
