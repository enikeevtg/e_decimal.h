#ifndef _SRC_TAGIR_E_DECIMAL_H_
#define _SRC_TAGIR_E_DECIMAL_H_

#include <stdio.h>

#define TRUE 1
#define FALSE 0

#define RIGHT_SHIFT 1
#define LEFT_SHIFT -1

// TYPES AND STUCTURES
typedef struct {
  unsigned int bits[4];
} e_decimal;

enum { _low, _mid, _high, _form };

// typedef struct {
//   unsigned int bits[8];
// } e_big_decimal;

// MAIN FUNCTIONS
int e_add(e_decimal val_1, e_decimal val_2, e_decimal* result);
int e_sub(e_decimal value_1, e_decimal value_2, e_decimal* result);

// INTERNAL FUNCTIONS
int e_get_bit(e_decimal value, int bit_pos);
void e_set_bit(e_decimal* value, int bit_pos, int bit_value);
char* e_dec_to_str(e_decimal* value);

int boundary_nills(e_decimal value, int direction);
e_decimal e_shift_to_right(e_decimal value, int offset);
e_decimal e_shift_to_left(e_decimal value, int offset);

void e_bin_convert(e_decimal* value);


#endif  // _SRC_TAGIR_E_DECIMAL_H_
