#include <check.h>
#include <stdio.h>

#include "../e_decimal.h"

START_TEST(set_bit_01) {
  // Arrange
  e_decimal number = {0};
  //                 76543210765432107654321076543210
  number.bits[0] = 0b10110100101101001011010010110100;
  number.bits[1] = 0b10010110100101101001011010010110;
  number.bits[2] = 0b10101101010010101101010010101101;
  number.bits[3] = 0b10000000011010011000000000000000;

  // Act
  int i = 128;
  while (i--) e_set_bit(&number, i, i % 2);
  
  // Assert
  char* res_str = e_dec_to_split_str(&number);
  char ref_str[132] = "10101010101010101010101010101010 10101010101010101010101010101010 10101010101010101010101010101010 10101010101010101010101010101010";
  ck_assert_str_eq(res_str, ref_str);
}
END_TEST

START_TEST(set_sign_minus) {
  // Arrange
  e_decimal number = {0};
  //                 76543210765432107654321076543210
  number.bits[0] = 0b10110100101101001011010010110100;
  number.bits[1] = 0b10010110100101101001011010010110;
  number.bits[2] = 0b10101101010010101101010010101101;
  number.bits[3] = 0b00000000011010011000000000000000;

  // Act
  e_set_sign(&number, MINUS);
  
  // Assert
  char* res_str = e_dec_to_split_str(&number);
  char ref_str[132] = "10000000011010011000000000000000 10101101010010101101010010101101 10010110100101101001011010010110 10110100101101001011010010110100";
  ck_assert_str_eq(res_str, ref_str);
}
END_TEST

START_TEST(set_sign_plus) {
  // Arrange
  e_decimal number = {0};
  //                 76543210765432107654321076543210
  number.bits[0] = 0b10110100101101001011010010110100;
  number.bits[1] = 0b10010110100101101001011010010110;
  number.bits[2] = 0b10101101010010101101010010101101;
  number.bits[3] = 0b10000000011010011000000000000000;

  // Act
  e_set_sign(&number, PLUS);
  
  // Assert
  char* res_str = e_dec_to_split_str(&number);
  char ref_str[132] = "00000000011010011000000000000000 10101101010010101101010010101101 10010110100101101001011010010110 10110100101101001011010010110100";
  ck_assert_str_eq(res_str, ref_str);
}
END_TEST

START_TEST(set_scale_1) {
  // Arrange
  e_decimal number = {0};
  //                 76543210765432107654321076543210
  number.bits[0] = 0b10110100101101001011010010110100;
  number.bits[1] = 0b10010110100101101001011010010110;
  number.bits[2] = 0b10101101010010101101010010101101;
  number.bits[3] = 0b10000000111111110000000000000000;

  // Act
  e_set_scale(&number, 1);
  
  // Assert
  char* res_str = e_dec_to_split_str(&number);
  char ref_str[132] = "10000000000000010000000000000000 10101101010010101101010010101101 10010110100101101001011010010110 10110100101101001011010010110100";
  ck_assert_str_eq(res_str, ref_str);
}
END_TEST

START_TEST(set_scale_255) {
  // Arrange
  e_decimal number = {0};
  //                 76543210765432107654321076543210
  number.bits[0] = 0b10110100101101001011010010110100;
  number.bits[1] = 0b10010110100101101001011010010110;
  number.bits[2] = 0b10101101010010101101010010101101;
  number.bits[3] = 0b10000000000000010000000000000000;

  // Act
  e_set_scale(&number, 255);
  
  // Assert
  char* res_str = e_dec_to_split_str(&number);
  char ref_str[132] = "10000000111111110000000000000000 10101101010010101101010010101101 10010110100101101001011010010110 10110100101101001011010010110100";
  ck_assert_str_eq(res_str, ref_str);
}
END_TEST

Suite* set_funcs(void) {
  Suite* s;
  TCase* tc_bit;
  TCase* tc_scale;
  TCase* tc_sign;

  s = suite_create("set_bit functions suite");

  tc_bit = tcase_create("set_bit function testcase");
  tcase_add_test(tc_bit, set_bit_01);
  suite_add_tcase(s, tc_bit);

  tc_scale = tcase_create("set_scale function testcase");
  tcase_add_test(tc_scale, set_scale_1);
  tcase_add_test(tc_scale, set_scale_255);
  suite_add_tcase(s, tc_scale);

  tc_sign = tcase_create("set_sign function testcase");
  tcase_add_test(tc_sign, set_sign_minus);
  tcase_add_test(tc_sign, set_sign_plus);
  suite_add_tcase(s, tc_sign);

  return s;
}

int main(void) {
  Suite* set_suite;
  SRunner* runner;

  set_suite = set_funcs();
  runner = srunner_create(set_suite);

  srunner_run_all(runner, CK_NORMAL);
  int tests_count = srunner_ntests_run(runner);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  printf("\033[0;32m  SUCCESS: %d\n", tests_count - failed);
  printf("\033[0;31m  FAILED: %d\n", failed);

  return failed ? 1 : 0;
}
