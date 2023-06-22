#ifndef _SRC_TAGIR_E_INTEGER_H_
#define _SRC_TAGIR_E_INTEGER_H_

#define TRUE 1
#define FALSE 0

// TYPES AND STUCTURES

// MAIN FUNCTIONS
int e_add(int value_1, int value_2, int* result);

// INTERNAL FUNCTIONS
int e_get_bit(int value, int bit_pos);
void e_set_bit(int* value, int bit_pos, int bit_value);

int e_shift_to_right(int value, int offset);
int e_shift_to_left(int value, int offset);

int* e_int_to_bin(int number);

#endif  // _SRC_TAGIR_E_INTEGER_H_
