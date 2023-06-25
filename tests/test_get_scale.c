#include <check.h>
#include <stdio.h>

#include "../e_decimal.h"

START_TEST(get_scale_1) {
  // Arrange
  e_decimal number = {0};
  //                 76543210765432107654321076543210
  number.bits[0] = 0b10110100101101001011010010110100;
  number.bits[1] = 0b10010110100101101001011010010110;
  number.bits[2] = 0b10101101010010101101010010101101;
  number.bits[3] = 0b10000000000000010000000000000000;
  // char bin_str[129] = "10000000011010010000000000000000101011010100101011010100101011011001011010010110100101101001011010110100101101001011010010110100";

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
  // char bin_str[129] = "10000000011010010000000000000000101011010100101011010100101011011001011010010110100101101001011010110100101101001011010010110100";

  // Act
  int scale = e_get_scale(number);
  
  // Assert
  ck_assert_int_eq(scale, 255);
}
END_TEST


Suite* get_bit_func(void) {
  Suite* s;
  TCase* tc_1;

  s = suite_create("get_scale function");

  tc_1 = tcase_create("get_scale function");
  tcase_add_test(tc_1, get_scale_1);
  tcase_add_test(tc_1, get_scale_255);
  suite_add_tcase(s, tc_1);

  return s;
}

int main(void) {
  Suite* get_scale_suite;
  SRunner* runner;

  get_scale_suite = get_bit_func();
  runner = srunner_create(get_scale_suite);

  srunner_run_all(runner, CK_NORMAL);
  int tests_count = srunner_ntests_run(runner);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  printf("\033[0;32mSUCCESS: %d\n", tests_count - failed);
  printf("\033[0;31mFAILED: %d\n", failed);

  return failed ? 1 : 0;
}
