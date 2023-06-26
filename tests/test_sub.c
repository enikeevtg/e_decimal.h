#include <check.h>
#include <stdio.h>

#include "../e_decimal.h"

START_TEST(sub_pos_result) {
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
  e_sub(val_1, val_2, &res);
                  //  00000000000000000000000000000000101011010100101011010100101011011001011010010110100101101001011000011010010010110000111000011010

  // Assert
  char* res_str = e_dec_to_split_str(&res);
  char bin_str[132] = "00000000000000000000000000000000 10101101010010101101010010101101 10010110100101101001011010010110 00011010010010110000111000011010";
#ifdef DEBUG
  printf("\nresult: %s\nstring: %s\n\n", res_str, bin_str);
#endif  // DEBUG

  ck_assert_str_eq(res_str, bin_str);
}
END_TEST

START_TEST(sub_neg_result) {
  // Arrange
  e_decimal val_1;
  e_decimal val_2;
  e_decimal res = {0};

  val_1.bits[0] = 0b10011010011010011010011010011010;
  val_1.bits[1] = 0;
  val_1.bits[2] = 0;
  val_1.bits[3] = 0;
                  // 00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000010011010011010011010011010011010
  
  val_2.bits[0] = 0b10110100101101001011010010110100;
  val_2.bits[1] = 0b10010110100101101001011010010110;
  val_2.bits[2] = 0b10101101010010101101010010101101;
  val_2.bits[3] = 0;
                  //00000000000000000000000000000000101011010100101011010100101011011001011010010110100101101001011010110100101101001011010010110100

  // Act
  e_sub(val_1, val_2, &res);
                  // 10000000000000000000000000000000101011010100101011010100101011011001011010010110100101101001011000011010010010110000111000011010

  // Assert
  char* res_str = e_dec_to_split_str(&res);
  char bin_str[132] = "10000000000000000000000000000000 10101101010010101101010010101101 10010110100101101001011010010110 00011010010010110000111000011010";

  ck_assert_str_eq(res_str, bin_str);
}
END_TEST

START_TEST(sub_neg_result_2) {
  // Arrange
  e_decimal val_1;
  e_decimal val_2;
  e_decimal res = {0};

  val_1.bits[0] = 0b00011010010010110000111000011010;
  val_1.bits[1] = 0b10010110100101101001011010010110;
  val_1.bits[2] = 0b10101101010010101101010010101101;
  val_1.bits[3] = 0;
                  // 00000000000000000000000000000000101011010100101011010100101011011001011010010110100101101001011000011010010010110000111000011010
  
  val_2.bits[0] = 0b10110100101101001011010010110100;
  val_2.bits[1] = 0b10010110100101101001011010010110;
  val_2.bits[2] = 0b10101101010010101101010010101101;
  val_2.bits[3] = 0;
                  //00000000000000000000000000000000101011010100101011010100101011011001011010010110100101101001011010110100101101001011010010110100

  // Act
  e_sub(val_1, val_2, &res);
                  // 10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000010011010011010011010011010011010

  // Assert
  char* res_str = e_dec_to_split_str(&res);
  char bin_str[132] = "10000000000000000000000000000000 00000000000000000000000000000000 00000000000000000000000000000000 10011010011010011010011010011010";

  ck_assert_str_eq(res_str, bin_str);
}
END_TEST

START_TEST(sub_neg_result_min5_10) {
  // Arrange
  e_decimal val_1;
  e_decimal val_2;
  e_decimal res = {0};

  val_1.bits[0] = 5;
  val_1.bits[1] = 0;
  val_1.bits[2] = 0;
  val_1.bits[3] = 0b10000000000000000000000000000000;
  
  val_2.bits[0] = 10;
  val_2.bits[1] = 0;
  val_2.bits[2] = 0;
  val_2.bits[3] = 0;

  // Act
  e_sub(val_1, val_2, &res);

  // Assert
  char* res_str = e_dec_to_split_str(&res);
  char bin_str[132] = "10000000000000000000000000000000 00000000000000000000000000000000 00000000000000000000000000000000 00000000000000000000000000001111";

  ck_assert_str_eq(res_str, bin_str);
}
END_TEST

Suite* sub_func(void) {
  Suite* s;
  TCase* tc_sub;

  s = suite_create("sub function");

  tc_sub = tcase_create("two numbers difference");
  tcase_add_test(tc_sub, sub_pos_result);
  tcase_add_test(tc_sub, sub_neg_result);
  tcase_add_test(tc_sub, sub_neg_result_2);
  tcase_add_test(tc_sub, sub_neg_result_min5_10);
  suite_add_tcase(s, tc_sub);

  return s;
}

int main(void) {
  Suite* sub_suite;
  SRunner* runner;

  sub_suite = sub_func();
  runner = srunner_create(sub_suite);

  srunner_run_all(runner, CK_NORMAL);
  int tests_count = srunner_ntests_run(runner);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  printf("\033[0;32mSUCCESS: %d\n", tests_count - failed);
  printf("\033[0;31mFAILED: %d\n", failed);

  return failed ? 1 : 0;
}
