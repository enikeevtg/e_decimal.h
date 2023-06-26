#include <check.h>
#include <stdio.h>

#include "../e_decimal.h"

START_TEST(right_0) {
  // Arrange
  e_decimal number = {0};
  //                 76543210765432107654321076543210
  number.bits[0] = 0b10110100101101001011010010110100;
  number.bits[1] = 0b10010110100101101001011010010110;
  number.bits[2] = 0b10101101010010101101010010101101;
  number.bits[3] = 0b10000000011010010000000000000000;
  char bin_str[132] = "10000000011010010000000000000000 10101101010010101101010010101101 10010110100101101001011010010110 10110100101101001011010010110100";
  int offset = 0;
  // Act
  number = e_shift_to_right(number, offset);
  char* res_str = e_dec_to_split_str(&number);
  
  // Assert
  ck_assert_str_eq(res_str, bin_str);
}
END_TEST

START_TEST(right_1) {
  // Arrange
  e_decimal number = {0};
  //                 76543210765432107654321076543210
  number.bits[0] = 0b10110100101101001011010010110100;
  number.bits[1] = 0b10010110100101101001011010010110;
  number.bits[2] = 0b10101101010010101101010010101101;
  number.bits[3] = 0b10000000011010010000000000000000;
  int offset = 1;
  char bin_str[132] = "10000000011010010000000000000000 01010110101001010110101001010110 11001011010010110100101101001011 01011010010110100101101001011010";

  // Act
  number = e_shift_to_right(number, offset);
  char* res_str = e_dec_to_split_str(&number);
  
  // Assert
  ck_assert_str_eq(res_str, bin_str);
}
END_TEST

START_TEST(right_32) {
  // Arrange
  e_decimal number = {0};
  //                 76543210765432107654321076543210
  number.bits[0] = 0b00000000000000000000000000000000;
  number.bits[1] = 0b10010110100101101001011010010110;
  number.bits[2] = 0b10101101010010101101010010101101;
  number.bits[3] = 0b10000000011010010000000000000000;
  int offset = 32;
  char bin_str[132] = "10000000011010010000000000000000 00000000000000000000000000000000 10101101010010101101010010101101 10010110100101101001011010010110";

  // Act
  number = e_shift_to_right(number, offset);
  char* res_str = e_dec_to_split_str(&number);
  
  // Assert
  ck_assert_str_eq(res_str, bin_str);
}
END_TEST

START_TEST(right_64) {
  // Arrange
  e_decimal number = {0};
  //                 76543210765432107654321076543210
  number.bits[0] = 0b00000000000000000000000000000000;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b10101101010010101101010010101101;
  number.bits[3] = 0b10000000011010010000000000000000;
  int offset = 64;
  char bin_str[132] = "10000000011010010000000000000000 00000000000000000000000000000000 00000000000000000000000000000000 10101101010010101101010010101101";

  // Act
  number = e_shift_to_right(number, offset);
  char* res_str = e_dec_to_split_str(&number);
  
  // Assert
  ck_assert_str_eq(res_str, bin_str);
}
END_TEST

START_TEST(left_0) {
  // Arrange
  e_decimal number = {0};
  //                 76543210765432107654321076543210
  number.bits[0] = 0b10110100101101001011010010110100;
  number.bits[1] = 0b10010110100101101001011010010110;
  number.bits[2] = 0b10101101010010101101010010101101;
  number.bits[3] = 0b10000000011010010000000000000000;
  char bin_str[132] = "10000000011010010000000000000000 10101101010010101101010010101101 10010110100101101001011010010110 10110100101101001011010010110100";
  int offset = 0;
  // Act
  number = e_shift_to_left(number, offset);
  char* res_str = e_dec_to_split_str(&number);
  
  // Assert
  ck_assert_str_eq(res_str, bin_str);
}
END_TEST

START_TEST(left_1) {
  // Arrange
  e_decimal number = {0};
  //                 76543210765432107654321076543210
  number.bits[0] = 0b10110100101101001011010010110100;
  number.bits[1] = 0b10010110100101101001011010010110;
  number.bits[2] = 0b00010110101001010110110010101101;
  number.bits[3] = 0b00000000011010010000000000000000;
  int offset = 1;
  char bin_str[132] = "00000000011010010000000000000000 00101101010010101101100101011011 00101101001011010010110100101101 01101001011010010110100101101000";

  // Act
  number = e_shift_to_left(number, offset);
  char* res_str = e_dec_to_split_str(&number);
  
  // Assert
  ck_assert_str_eq(res_str, bin_str);
}
END_TEST

START_TEST(left_32) {
  // Arrange
  e_decimal number = {0};
  //                 76543210765432107654321076543210
  number.bits[0] = 0b10000000011010010000000000000000;
  number.bits[1] = 0b10010110100101101001011010010110;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b10101101010010101101010010101101;
  int offset = 32;
  char bin_str[132] = "10101101010010101101010010101101 10010110100101101001011010010110 10000000011010010000000000000000 00000000000000000000000000000000";

  // Act
  number = e_shift_to_left(number, offset);
  char* res_str = e_dec_to_split_str(&number);
  
  // Assert
  ck_assert_str_eq(res_str, bin_str);
}
END_TEST

START_TEST(left_64) {
  // Arrange
  e_decimal number = {0};
  //                 76543210765432107654321076543210
  number.bits[0] = 0b10110100101101001011010010110100;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b10000000011010010000000000000000;
  int offset = 64;
  char bin_str[132] = "10000000011010010000000000000000 10110100101101001011010010110100 00000000000000000000000000000000 00000000000000000000000000000000";

  // Act
  number = e_shift_to_left(number, offset);
  char* res_str = e_dec_to_split_str(&number);
  
  // Assert
  ck_assert_str_eq(res_str, bin_str);
}
END_TEST

Suite* get_bit_func(void) {
  Suite* s;
  TCase* tc_right;
  TCase* tc_left;

  s = suite_create("Shift functions");

  tc_right = tcase_create("Right shift cases");
  tcase_add_test(tc_right, right_0);
  tcase_add_test(tc_right, right_1);
  tcase_add_test(tc_right, right_32);
  tcase_add_test(tc_right, right_64);
  suite_add_tcase(s, tc_right);

  tc_left = tcase_create("Left shift cases");
  tcase_add_test(tc_left, left_0);
  tcase_add_test(tc_left, left_1);
  tcase_add_test(tc_left, left_32);
  tcase_add_test(tc_left, left_64);
  suite_add_tcase(s, tc_left);

  return s;
}

int main(void) {
  Suite* shift_suite;
  SRunner* runner;

  shift_suite = get_bit_func();
  runner = srunner_create(shift_suite);

  srunner_run_all(runner, CK_NORMAL);
  int tests_count = srunner_ntests_run(runner);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  printf("\033[0;32mSUCCESS: %d\n", tests_count - failed);
  printf("\033[0;31mFAILED: %d\n", failed);

  return failed ? 1 : 0;
}
