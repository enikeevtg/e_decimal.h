/**
 * @author T. Enikeev
 * @brief Multiplying the specified e_decimal value by negative one
 * @param value 
 * @param result 
 * @return error_code:
 *         0 - OK
 *         1 - calculation error
 */

#include "../e_decimal.h"

int e_negate(e_decimal value, e_decimal* result) {
  int error_code = 0;
  *result = value;
  result->bits[3] = value.bits[3] ^ SIGN_MASK;
  return error_code;
}

//   [10000000 10101010...]    |      [00000000 10101010...]
// ^ [10000000 00000000...]    |    ^ [10000000 00000000...] 
// = [00000000 10101010...]    |    = [10000000 10101010...]
