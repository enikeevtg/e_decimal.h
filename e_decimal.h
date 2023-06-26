#ifndef _SRC_TAGIR_E_DECIMAL_H_
#define _SRC_TAGIR_E_DECIMAL_H_

#include <stdio.h>

#define TRUE 1
#define FALSE 0

#define RIGHT_SIDE 1
#define LEFT_SIDE -1

#define MINUS 1
#define PLUS 0

#define MANTISSA_MAX_BIT 95
#define SIGN_MASK 0x80000000   // 0b10000000 00000000 00000000 00000000
#define SCALE_MASK 0x00ff0000  // 0b00000000 11111111 00000000 00000000

// TYPES AND STUCTURES
typedef struct {
  unsigned int bits[4];
} e_decimal;

enum { _low, _mid, _high, _form };

// typedef struct {
//   unsigned int bits[8];
// } e_big_decimal;

// MAIN FUNCTIONS
int e_add(e_decimal value_1, e_decimal value_2, e_decimal* result);
int e_sub(e_decimal value_1, e_decimal value_2, e_decimal* result);

// INTERNAL FUNCTIONS
int e_get_bit(e_decimal value, int bit_pos);
int e_get_sign(e_decimal value);
int e_get_scale(e_decimal value);
void e_set_bit(e_decimal* value, int bit_pos, int bit_value);
void e_set_sign(e_decimal* value, int sign);
void e_change_sign(e_decimal* value);
void e_set_scale(e_decimal* value, int scale);

char* e_dec_to_str(e_decimal* value);
char* e_dec_to_split_str(e_decimal* value);
void e_bin_convert(e_decimal* value);
int e_dec_is_nill(e_decimal value);


int boundary_nills(e_decimal value, int side);
e_decimal e_shift_to_right(e_decimal value, int offset);
e_decimal e_shift_to_left(e_decimal value, int offset);


// int e_norm(e_decimal* value_1, e_decimal* value_2);
// void e_normalize(e_decimal* value, int scale_src, int scale_dest);
int e_mul_10(e_decimal value, e_decimal* result);

#endif  // _SRC_TAGIR_E_DECIMAL_H_
