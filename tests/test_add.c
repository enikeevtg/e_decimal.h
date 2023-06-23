#include <check.h>
#include <stdio.h>

#include "../e_decimal.h"

START_TEST(add_1) {
  // Arrange
  e_decimal val_1;
  e_decimal val_2;
  e_decimal res = {0};
  
  val_1.bits[0] = 0b10110100101101001011010010110100;
  val_1.bits[1] = 0b10010110100101101001011010010110;
  val_1.bits[2] = 0b10101101010010101101010010101101;
  val_1.bits[3] = 0;
                  //00000000000000000000000000000000101011010100101011010100101011011001011010010110100101101001011010110100101101001011010010110100
  val_2.bits[0] = 0b10011010011010011010011010011010;
  val_2.bits[1] = 0;
  val_2.bits[2] = 0;
  val_2.bits[3] = 0;
                  // 00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000010011010011010011010011010011010

  // Act
  e_add(val_1, val_2, &res);
                  // 00000000000000000000000000000000101011010100101011010100101011011001011010010110100101101001011101001111000111100101101101001110

  // Assert
  char* res_str = e_dec_to_str(&res);
  char bin_str[129] = "00000000000000000000000000000000101011010100101011010100101011011001011010010110100101101001011101001111000111100101101101001110";
  ck_assert_str_eq(res_str, bin_str);
}
END_TEST



Suite* add_func(void) {
  Suite* s;
  TCase* tc_add;

  s = suite_create("add function");

  tc_add = tcase_create("two numbers summation");
  tcase_add_test(tc_add, add_1);
  // tcase_add_test(tc_add, add_neg);
  // tcase_add_test(tc_add, add_pos_neg);
  // tcase_add_test(tc_add, add_neg_pos);
  suite_add_tcase(s, tc_add);

  return s;
}

int main(void) {
  int failed = 0;
  Suite* add_suite;
  SRunner* runner;

  add_suite = add_func();
  runner = srunner_create(add_suite);

  srunner_run_all(runner, CK_NORMAL);
  int tests_count = srunner_ntests_run(runner);
  failed += srunner_ntests_failed(runner);
  srunner_free(runner);

  printf("\033[0;32mSUCCESS: %d\n", tests_count - failed);
  printf("\033[0;31mFAILED: %d\n", failed);

  return failed ? 1 : 0;
}
