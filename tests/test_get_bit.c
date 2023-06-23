#include <check.h>
#include <stdio.h>

#include "../e_decimal.h"

START_TEST(get_bit_1) {
  // Arrange
  e_decimal number = {0};
  //                 76543210765432107654321076543210
  number.bits[0] = 0b10110100101101001011010010110100;
  number.bits[1] = 0b10010110100101101001011010010110;
  number.bits[2] = 0b10101101010010101101010010101101;
  number.bits[3] = 0b10000000011010011000000000000000;
  char bin_str[129] = "10000000011010011000000000000000101011010100101011010100101011011001011010010110100101101001011010110100101101001011010010110100";

  // Act
  char* res_str = e_dec_to_str(&number);
  
  // Assert
  ck_assert_str_eq(res_str, bin_str);
}
END_TEST

Suite* get_bit_func(void) {
  Suite* s;
  TCase* tc_1;

  s = suite_create("get_bit function");

  tc_1 = tcase_create("Eleven");
  tcase_add_test(tc_1, get_bit_1);
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