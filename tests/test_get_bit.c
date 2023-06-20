#include <stdio.h>
#include <check.h>
#include "../e_decimal.h"

START_TEST (get_bit_5) {
  // Arrange
  //                                                 76543210
  int number = 11;  // 0b 00000000 00000000 00000000 00001011
  
  // Act
  int i = 8;
  char str[9] = {0};
  while (i--) str[7 - i] = e_get_bit(number, i) + 48;
  printf("\nget_bits result for %d: %s\n\n", number, str);
  // Assert
  ck_assert_str_eq(str, "00001011");
} END_TEST

Suite* get_bit_func(void) {
  Suite* s;
  TCase* tc_1;

  s = suite_create("Get_Bit");

  tc_1 = tcase_create("Eleven");
  tcase_add_test(tc_1, get_bit_5);
  suite_add_tcase(s, tc_1);

  return s;
}

int main(void) {
  int failed = 0;
  Suite* get_bits;
  SRunner *runner;

  get_bits = get_bit_func();
  runner = srunner_create(get_bits);

  srunner_run_all(runner, CK_NORMAL);
  failed += srunner_ntests_failed(runner);
  srunner_free(runner);

  printf("FAILED: %d\n", failed);

  return failed ? 1 : 0;
}
