#include <check.h>
#include <stdio.h>

#include "../e_decimal.h"

START_TEST(is_not_equal_true_1) {
  // Arrange
  e_decimal val_1 = {{1, 0, 65001, 0}};
  e_decimal val_2 = {{1, 0, 65011, 0}};

  // Act
  int result = e_is_not_equal(val_1, val_2);

  // Assert
  ck_assert_int_eq(result, TRUE);
}
END_TEST

START_TEST(is_not_equal_true_2) {
  // Arrange
  e_decimal val_1 = {{1, 32001, 65000, 0}};
  e_decimal val_2 = {{1, 32011, 65000, 0}};

  // Act
  int result = e_is_not_equal(val_1, val_2);

  // Assert
  ck_assert_int_eq(result, TRUE);
}
END_TEST

START_TEST(is_not_equal_true_3) {
  // Arrange
  e_decimal val_1 = {{16001, 32000, 65000, 0}};
  e_decimal val_2 = {{16011, 32000, 65000, 0}};

  // Act
  int result = e_is_not_equal(val_1, val_2);

  // Assert
  ck_assert_int_eq(result, TRUE);
}
END_TEST

START_TEST(is_not_equal_false_1) {
  // Arrange
  e_decimal val_1 = {{1, 0, 65001, 0}};
  e_decimal val_2 = {{1, 0, 65001, 0}};

  // Act
  int result = e_is_not_equal(val_1, val_2);

  // Assert
  ck_assert_int_eq(result, FALSE);
}
END_TEST

Suite* is_not_equal_func(void) {
  Suite* s;
  TCase* tc_not_equal;
  TCase* tc_not_not_equal;

  s = suite_create("is_not_equal function");

  tc_not_equal = tcase_create("true cases");
  tcase_add_test(tc_not_equal, is_not_equal_true_1);
  tcase_add_test(tc_not_equal, is_not_equal_true_2);
  tcase_add_test(tc_not_equal, is_not_equal_true_3);
  suite_add_tcase(s, tc_not_equal);

  tc_not_not_equal = tcase_create("false cases");
  tcase_add_test(tc_not_not_equal, is_not_equal_false_1);
  suite_add_tcase(s, tc_not_not_equal);

  return s;
}

int main(void) {
  Suite* is_not_equal_suite;
  SRunner* runner;

  is_not_equal_suite = is_not_equal_func();
  runner = srunner_create(is_not_equal_suite);

  srunner_run_all(runner, CK_NORMAL);
  int tests_count = srunner_ntests_run(runner);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  printf("\033[0;32m  SUCCESS: %d\n", tests_count - failed);
  printf("\033[0;31m  FAILED: %d\n", failed);

  return failed ? 1 : 0;
}
