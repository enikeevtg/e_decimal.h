/**
 * @author T. Enikeev
 * @brief Some internal functions for e_decimal library
 */

#include "../e_decimal.h"

/// @brief Making e_decimal value equal to nill
/// @param value is e_decimal number
/// @warning there may be memory freeing problem
void e_dec_reset_v1(e_decimal* value) {
  e_decimal tmp = {0};
  value = &tmp;
}
