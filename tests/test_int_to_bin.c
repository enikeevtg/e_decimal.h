#include <check.h>
#include <stdio.h>

#include "../s21_decimal.h"

START_TEST(int_to_bin_11) {
  // Arrange
  //                                                      76543210
  int test_number = 11;  // 0b 00000000 00000000 00000000 00001011
  int _0b_11[32] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1};

  // Act
  int* result = s21_int_to_bin(test_number);

  // Assert
  ck_assert_mem_eq(_0b_11, result, 32 * sizeof(int));
}
END_TEST

Suite* int_to_bin_func(void) {
  Suite* s;
  TCase* tc_1;

  s = suite_create("int_to_bin function");

  tc_1 = tcase_create("Eleven");
  tcase_add_test(tc_1, int_to_bin_11);
  suite_add_tcase(s, tc_1);

  return s;
}

int main(void) {
  int failed = 0;
  Suite* int_to_bin_suite;
  SRunner* runner;

  int_to_bin_suite = int_to_bin_func();
  runner = srunner_create(int_to_bin_suite);

  srunner_run_all(runner, CK_NORMAL);
  failed += srunner_ntests_failed(runner);
  srunner_free(runner);

  printf("FAILED: %d\n", failed);

  return failed ? 1 : 0;
}
