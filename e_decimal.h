#ifndef _SRC_TAGIR_E_DECIMAL_H_
#define _SRC_TAGIR_E_DECIMAL_H_

// TYPES AND STUCTURES
typedef struct {
  unsigned int bits[4];
} e_decimal;

enum { _low, _mid, _high, _form };

// MAIN FUNCTIONS
int e_add(int value_1, int value_2, int* result);

// INTERNAL FUNCTIONS
// int e_get_bit(e_decimal value, int bit_pos);
int e_get_bit(int value, int bit_pos);

// void e_set_bit(e_decimal* value, int bit_pos, int bit_value);
void e_set_bit(int* value, int bit_pos, int bit_value);

int* e_int_to_bin(int number);

#endif  // _SRC_TAGIR_E_DECIMAL_H_
