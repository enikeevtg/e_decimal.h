#include <check.h>
#include <stdio.h>

#include "../e_decimal.h"

START_TEST(negate_1) {
  // Arrange
  e_decimal number = {0};
  //                 76543210765432107654321076543210
  number.bits[0] = 0b10110100101101001011010010110100;
  number.bits[1] = 0b10010110100101101001011010010110;
  number.bits[2] = 0b10101101010010101101010010101101;
  number.bits[3] = 0b00000000011010011000000000000000;

  e_decimal result = {0};

  // Act
  e_negate(number, &result);
  
  // Assert
  char* res_str = e_dec_to_split_str(&result);
  char ref_str[132] = "10000000011010011000000000000000 10101101010010101101010010101101 10010110100101101001011010010110 10110100101101001011010010110100";
  ck_assert_str_eq(res_str, ref_str);
}
END_TEST

START_TEST(negate_0) {
  // Arrange
  e_decimal number = {0};
  //                 76543210765432107654321076543210
  number.bits[0] = 0b10110100101101001011010010110100;
  number.bits[1] = 0b10010110100101101001011010010110;
  number.bits[2] = 0b10101101010010101101010010101101;
  number.bits[3] = 0b10000000011010011000000000000000;

  e_decimal result = {0};

  // Act
  e_negate(number, &result);
    
  // Assert
  char* res_str = e_dec_to_split_str(&result);
  char ref_str[132] = "00000000011010011000000000000000 10101101010010101101010010101101 10010110100101101001011010010110 10110100101101001011010010110100";
  ck_assert_str_eq(res_str, ref_str);
  
}
END_TEST

Suite* set_funcs(void) {
  Suite* s;
  TCase* tc_negate;

  s = suite_create("negate function suite");

  tc_negate = tcase_create("change sign function testcase");
  tcase_add_test(tc_negate, negate_1);
  tcase_add_test(tc_negate, negate_0);
  suite_add_tcase(s, tc_negate);

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
