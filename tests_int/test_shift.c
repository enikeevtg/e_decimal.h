#include <check.h>
#include <stdio.h>

#include "../e_integer.h"

/*
SHIFT_right_FUNCTION
*/
START_TEST(right_0) {
  // Arrange
  int number = 110;
  int offset = 0;
  // Act
  int result = e_shift_to_right(number, offset);
  // Assert
  ck_assert_int_eq(result, number >> offset);
}
END_TEST

START_TEST(right_5) {
  // Arrange
  int number = 110;
  int offset = 5;
  // Act
  int result = e_shift_to_right(number, offset);
  // Assert
  ck_assert_int_eq(result, number >> offset);
}
END_TEST

START_TEST(right_31) {
  // Arrange
  int number = 11;
  int offset = 31;
  // Act
  int result = e_shift_to_right(number, offset);
  // Assert
  ck_assert_int_eq(result, number >> offset);
}
END_TEST

START_TEST(right_256) {
  // Arrange
  int number = 0b11111110111111101111111011111110;
  int offset = 256;
  // Act
  int result = e_shift_to_right(number, offset);
  // Assert
  ck_assert_int_eq(result, number >> offset);
}
END_TEST

/*
SHIFT_left_FUNCTION
*/
START_TEST(left_0) {
  // Arrange
  int number = 110;
  int offset = 0;
  // Act
  int result = e_shift_to_left(number, offset);
  // Assert
  ck_assert_int_eq(result, number << offset);
}
END_TEST

START_TEST(left_5) {
  // Arrange
  int number = 110;
  int offset = 5;
  // Act
  int result = e_shift_to_left(number, offset);
  // Assert
  ck_assert_int_eq(result, number << offset);
}
END_TEST

START_TEST(left_31) {
  // Arrange
  int number = 11;
  int offset = 31;
  // Act
  int result = e_shift_to_left(number, offset);
  // Assert
  ck_assert_int_eq(result, number << offset);
}
END_TEST

START_TEST(left_256) {
  // Arrange
  int number = 0b11111110111111101111111011111110;
  int offset = 256;
  // Act
  int result = e_shift_to_left(number, offset);
  // Assert
  ck_assert_int_eq(result, number << offset);
}
END_TEST

Suite* shift_func(void) {
  Suite* s;
  TCase* tc_right;
  TCase* tc_left;

  s = suite_create("shift functions");

  tc_right = tcase_create("shift to right");
  tcase_add_test(tc_right, right_0);
  tcase_add_test(tc_right, right_5);
  tcase_add_test(tc_right, right_31);
  tcase_add_test(tc_right, right_256);
  suite_add_tcase(s, tc_right);

  tc_left = tcase_create("shift to left");
  tcase_add_test(tc_left, left_0);
  tcase_add_test(tc_left, left_5);
  tcase_add_test(tc_left, left_31);
  tcase_add_test(tc_left, left_256);
  suite_add_tcase(s, tc_left);

  return s;
}

int main(void) {
  int failed = 0;
  Suite* shift_suite;
  SRunner* runner;

  shift_suite = shift_func();
  runner = srunner_create(shift_suite);

  srunner_run_all(runner, CK_NORMAL);
  int tests_count = srunner_ntests_run(runner);
  failed += srunner_ntests_failed(runner);
  srunner_free(runner);

  printf("\033[0;32mSUCCESS: %d\n", tests_count - failed);
  printf("\033[0;31mFAILED: %d\n", failed);

  return failed ? 1 : 0;
}
