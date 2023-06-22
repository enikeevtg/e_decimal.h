#include <check.h>
#include <stdio.h>

#include "../e_integer.h"

START_TEST(int_to_bin_8) {
  // Arrange
  //                                                      76543210
  int test_number = 8;  // 0b 00000000 00000000 00000000 00001011
  int _0b_8[32] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0};

  // Act
  int* result = e_int_to_bin(test_number);

  // Assert
  ck_assert_mem_eq(_0b_8, result, 32 * sizeof(int));
}
END_TEST

START_TEST(int_to_bin_11) {
  // Arrange
  //                                                      76543210
  int test_number = 11;  // 0b 00000000 00000000 00000000 00001011
  int _0b_11[32] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1};

  // Act
  int* result = e_int_to_bin(test_number);

  // Assert
  ck_assert_mem_eq(_0b_11, result, 32 * sizeof(int));
}
END_TEST

Suite* int_to_bin_func(void) {
  Suite* s = suite_create("int_to_bin function tests");
  TCase* tc = tcase_create("integer_tests");

  tcase_add_test(tc, int_to_bin_8);
  tcase_add_test(tc, int_to_bin_11);

  suite_add_tcase(s, tc);

  return s;
}

int main(void) {
  int failed = 0;
  Suite* int_to_bin_suite;
  SRunner* runner;

  int_to_bin_suite = int_to_bin_func();
  runner = srunner_create(int_to_bin_suite);

  srunner_run_all(runner, CK_NORMAL);
  int tests_count = srunner_ntests_run(runner);
  failed += srunner_ntests_failed(runner);
  srunner_free(runner);

  printf("\033[0;32mSUCCESS: %d\n", tests_count - failed);
  printf("\033[0;31mFAILED: %d\n", failed);

  return failed ? 1 : 0;
}
