#ifndef _SRC_TAGIR_E_DECIMAL_H_
#define _SRC_TAGIR_E_DECIMAL_H_

#define TRUE 1
#define FALSE 0

// TYPES AND STUCTURES
typedef struct {
  unsigned int bits[4];
} e_decimal;

enum { _low, _mid, _high, _form };

// MAIN FUNCTIONS
int e_add(e_decimal val_1, e_decimal val_2, e_decimal* result);

// INTERNAL FUNCTIONS
int e_get_bit(e_decimal value, int bit_pos);
void e_set_bit(e_decimal* value, int bit_pos, int bit_value);

e_decimal e_shift_to_right(e_decimal value, int offset);
e_decimal e_shift_to_left(e_decimal value, int offset);

#endif  // _SRC_TAGIR_E_DECIMAL_H_
