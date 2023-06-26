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
