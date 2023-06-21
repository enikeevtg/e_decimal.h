#include <check.h>
#include <stdio.h>

#include "../e_decimal.h"

START_TEST(get_bit_11) {
  // Arrange
  //                   low mid high exp+sign
  e_decimal number = {{11, 0, 0, 0}};
  char _0b_11_str[129] =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000001011";

  // Act
  char str[129];
  str[128] = '\0';
  int i = 128;
  while (i--) str[127 - i] = e_get_bit(number, i) + 48;

  // Assert
  ck_assert_str_eq(str, _0b_11_str);
}
END_TEST

Suite* get_bit_func(void) {
  Suite* s;
  TCase* tc_1;

  s = suite_create("get_bit function");

  tc_1 = tcase_create("Eleven");
  tcase_add_test(tc_1, get_bit_11);
  suite_add_tcase(s, tc_1);

  return s;
}

int main(void) {
  int failed = 0;
  Suite* get_bit_suite;
  SRunner* runner;

  get_bit_suite = get_bit_func();
  runner = srunner_create(get_bit_suite);

  srunner_run_all(runner, CK_NORMAL);
  failed += srunner_ntests_failed(runner);
  srunner_free(runner);

  printf("FAILED: %d\n", failed);

  return failed ? 1 : 0;
}
