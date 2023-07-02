#ifndef _SRC_TAGIR_E_DECIMAL_H_
#define _SRC_TAGIR_E_DECIMAL_H_

#include <stdio.h>

// PREPROC DEFINES
// e_decimal properties:
#define MANTISSA_LEN 96
#define MAX_SCALE 28
#define SIGN_MASK 0x80000000   // 0b10000000 00000000 00000000 00000000
#define SCALE_MASK 0x00ff0000  // 0b00000000 11111111 00000000 00000000
#define MINUS 1
#define PLUS 0

// error_codes:
#define OK 0
#define TOO_LARGE 1
#define TOO_SMALL 2

// for shift possibility checking:
#define RIGHT_SIDE 1
#define LEFT_SIDE -1
#define E_DEC_TEN {{10U, 0, 0, 0}}

// for comparison functions:
#define TRUE 1
#define FALSE 0

// TYPES AND STUCTURES
typedef struct {
  unsigned int bits[4];
} e_decimal;

enum { _low, _mid, _high, _form };

// typedef struct {
//   unsigned int bits[8];
// } e_big_decimal;

// MAIN FUNCTIONS
// arithmetic operators
int e_add(e_decimal value_1, e_decimal value_2, e_decimal* result);
int e_sub(e_decimal value_1, e_decimal value_2, e_decimal* result);
int e_mul(e_decimal value_1, e_decimal value_2, e_decimal *result);

// comparison operators
int e_is_less(e_decimal value_1, e_decimal value_2);
int e_is_less_or_equal(e_decimal value_1, e_decimal value_2);
int e_is_greater(e_decimal value_1, e_decimal value_2);
int e_is_greater_or_equal(e_decimal value_1, e_decimal value_2);
int e_is_equal(e_decimal value_1, e_decimal value_2);
int e_is_not_equal(e_decimal value_1, e_decimal value_2);


// another functions
int e_negate(e_decimal value, e_decimal* result);

// INTERNAL FUNCTIONS
// algorithms of main functions
int e_add_alg(e_decimal value_1, e_decimal value_2, e_decimal* result);
int e_sub_alg(e_decimal value_1, e_decimal value_2, e_decimal* result);
int e_dec_comparison(e_decimal value_1, e_decimal value_2);

// get/set
int e_get_bit(e_decimal value, int bit_pos);
int e_get_sign(e_decimal value);
int e_get_scale(e_decimal value);
void e_set_bit(e_decimal* value, int bit_pos, int bit_value);
void e_set_sign(e_decimal* value, int sign);
void e_set_scale(e_decimal* value, int scale);

char* e_dec_to_str(e_decimal* value);
char* e_dec_to_split_str(e_decimal* value);
void e_bin_convert(e_decimal* value);
int e_dec_is_nill(e_decimal value);
void e_dec_reset(e_decimal* value);
void e_set_result(e_decimal val_1, e_decimal val_2, e_decimal* result);

int e_boundary_nills(e_decimal value, int side);
e_decimal e_shift_to_right(e_decimal value, int offset);
e_decimal e_shift_to_left(e_decimal value, int offset);


// int e_norm(e_decimal* value_1, e_decimal* value_2);
// void e_normalize(e_decimal* value, int scale_src, int scale_dest);
int e_mul_10(e_decimal value, e_decimal* result);

#endif  // _SRC_TAGIR_E_DECIMAL_H_
