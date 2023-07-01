#include <check.h>
#include <stdio.h>

#include "../e_decimal.h"

START_TEST(get_bit_1) {
  // Arrange
  e_decimal number = {0};
  //                 76543210765432107654321076543210
  number.bits[0] = 0b10110100101101001011010010110100;
  number.bits[1] = 0b10010110100101101001011010010110;
  number.bits[2] = 0b10101101010010101101010010101101;
  number.bits[3] = 0b10000000011010010000000000000000;
  char ref_str[132] = "10000000011010010000000000000000 10101101010010101101010010101101 10010110100101101001011010010110 10110100101101001011010010110100";

  // Act
  char* res_str = e_dec_to_split_str(&number);  // using e_get_bit() inside
  
  // Assert
  ck_assert_str_eq(res_str, ref_str);
}
END_TEST

START_TEST(get_sign_minus) {
  // Arrange
  e_decimal number = {0};
  //                 76543210765432107654321076543210
  number.bits[0] = 0b10110100101101001011010010110100;
  number.bits[1] = 0b10010110100101101001011010010110;
  number.bits[2] = 0b10101101010010101101010010101101;
  number.bits[3] = 0b10000000000000010000000000000000;

  // Act
  int sign = e_get_sign(number);
  
  // Assert
  ck_assert_int_eq(sign, MINUS);
}
END_TEST

START_TEST(get_sign_plus) {
  // Arrange
  e_decimal number = {0};
  //                 76543210765432107654321076543210
  number.bits[0] = 0b10110100101101001011010010110100;
  number.bits[1] = 0b10010110100101101001011010010110;
  number.bits[2] = 0b10101101010010101101010010101101;
  number.bits[3] = 0b00000000000000010000000000000000;

  // Act
  int sign = e_get_sign(number);
  
  // Assert
  ck_assert_int_eq(sign, PLUS);
}
END_TEST

START_TEST(get_scale_1) {
  // Arrange
  e_decimal number = {0};
  //                 76543210765432107654321076543210
  number.bits[0] = 0b10110100101101001011010010110100;
  number.bits[1] = 0b10010110100101101001011010010110;
  number.bits[2] = 0b10101101010010101101010010101101;
  number.bits[3] = 0b10000000000000010000000000000000;

  // Act
  int scale = e_get_scale(number);
  
  // Assert
  ck_assert_int_eq(scale, 1);
}
END_TEST

START_TEST(get_scale_255) {
  // Arrange
  e_decimal number = {0};
  //                 76543210765432107654321076543210
  number.bits[0] = 0b10110100101101001011010010110100;
  number.bits[1] = 0b10010110100101101001011010010110;
  number.bits[2] = 0b10101101010010101101010010101101;
  number.bits[3] = 0b10000000111111110000000000000000;

  // Act
  int scale = e_get_scale(number);
  
  // Assert
  ck_assert_int_eq(scale, 255);
}
END_TEST

Suite* get_funcs(void) {
  Suite* s;
  TCase* tc_bit;
  TCase* tc_scale;
  TCase* tc_sign;

  s = suite_create("get_bit function suite");

  tc_bit = tcase_create("get_bit function testcase");
  tcase_add_test(tc_bit, get_bit_1);
  suite_add_tcase(s, tc_bit);

  tc_sign = tcase_create("get_sign function testcase");
  tcase_add_test(tc_sign, get_sign_minus);
  tcase_add_test(tc_sign, get_sign_plus);
  suite_add_tcase(s, tc_sign);

  tc_scale = tcase_create("get_scale function testcase");
  tcase_add_test(tc_scale, get_scale_1);
  tcase_add_test(tc_scale, get_scale_255);
  suite_add_tcase(s, tc_scale);

  return s;
}

int main(void) {
  Suite* get_suite;
  SRunner* runner;

  get_suite = get_funcs();
  runner = srunner_create(get_suite);

  srunner_run_all(runner, CK_NORMAL);
  int tests_count = srunner_ntests_run(runner);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  printf("\033[0;32m  SUCCESS: %d\n", tests_count - failed);
  printf("\033[0;31m  FAILED: %d\n", failed);

  return failed ? 1 : 0;
}
