#include <check.h>
#include <stdio.h>

#include "../e_decimal.h"

START_TEST(set_bit_0) {
  // Arrange
  //             76543210
  int number = 0b10101110;
  int bit_position = 2;
  int new_bit_value = 0;

  // Act
  e_set_bit(&number, bit_position, new_bit_value);

  // Assert
  ck_assert_int_eq(e_get_bit(number, bit_position), new_bit_value);
}
END_TEST

START_TEST(set_bit_1) {
  // Arrange
  //             76543210
  int number = 0b00000000;
  int bit_position = 31;
  int new_bit_value = 1;

  // Act
  e_set_bit(&number, bit_position, new_bit_value);

  // Assert
  ck_assert_int_eq(e_get_bit(number, bit_position), new_bit_value);
}
END_TEST

Suite* set_bit_func(void) {
  Suite* s;
  TCase* tc_1;

  s = suite_create("set_bit function");

  tc_1 = tcase_create("set 0 or 1 to a number bit");
  tcase_add_test(tc_1, set_bit_0);
  tcase_add_test(tc_1, set_bit_1);
  suite_add_tcase(s, tc_1);

  return s;
}

int main(void) {
  int failed = 0;
  Suite* set_bit_suite;
  SRunner* runner;

  set_bit_suite = set_bit_func();
  runner = srunner_create(set_bit_suite);

  srunner_run_all(runner, CK_NORMAL);
  int tests_count = srunner_ntests_run(runner);
  failed += srunner_ntests_failed(runner);
  srunner_free(runner);

  printf("\033[0;32mSUCCESS: %d\n", tests_count - failed);
  printf("\033[0;31mFAILED: %d\n", failed);

  return failed ? 1 : 0;
}
