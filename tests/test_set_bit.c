#include <check.h>
#include <stdio.h>

#include "../e_decimal.h"

START_TEST(set_bit_1) {
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
  char* res_str = e_dec_to_str(&number);
  char bin_str[129] =   "10101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010";
  ck_assert_str_eq(res_str, bin_str);
}
END_TEST

Suite* set_bit_func(void) {
  Suite* s;
  TCase* tc_1;

  s = suite_create("set_bit function");

  tc_1 = tcase_create("Eleven");
  tcase_add_test(tc_1, set_bit_1);
  suite_add_tcase(s, tc_1);

  return s;
}

int main(void) {
  Suite* set_bit_suite;
  SRunner* runner;

  set_bit_suite = set_bit_func();
  runner = srunner_create(set_bit_suite);

  srunner_run_all(runner, CK_NORMAL);
  int tests_count = srunner_ntests_run(runner);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  printf("\033[0;32mSUCCESS: %d\n", tests_count - failed);
  printf("\033[0;31mFAILED: %d\n", failed);

  return failed ? 1 : 0;
}
