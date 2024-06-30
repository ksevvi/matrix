#include <check.h>
#include <stdlib.h>

#include "../s21_matrix.h"

void set_matrix(double num, matrix_t *A) {
  for (int i = 0; i < A->rows; ++i)
    for (int j = 0; j < A->columns; num += 1.0, ++j) A->matrix[i][j] = num;
}

// create
START_TEST(create_matrix_1) {
  matrix_t matrix;
  ck_assert_uint_eq(s21_create_matrix(-1, 2, &matrix), 1);
}
END_TEST

START_TEST(create_matrix_2) {
  matrix_t matrix;
  ck_assert_uint_eq(s21_create_matrix(2, 0, &matrix), 1);
}
END_TEST

START_TEST(create_matrix_3) {
  matrix_t matrix;
  ck_assert_uint_eq(s21_create_matrix(0, 0, &matrix), 1);
}
END_TEST

// remove
START_TEST(remove_matrix_1) {
  int res = 0;
  matrix_t matrix;
  res = s21_create_matrix(2, 2, &matrix);
  set_matrix(2.0, &matrix);
  s21_remove_matrix(&matrix);
  ck_assert_uint_eq(res, OK);
}
END_TEST

START_TEST(remove_matrix_2) {
  int res = 0;
  matrix_t matrix;
  res = s21_create_matrix(5, 4, &matrix);
  set_matrix(3.0, &matrix);
  s21_remove_matrix(&matrix);
  ck_assert_uint_eq(res, OK);
}
END_TEST

START_TEST(remove_matrix_3) {
  int res = 0;
  matrix_t matrix;
  res = s21_create_matrix(2, 5, &matrix);
  set_matrix(4.0, &matrix);
  s21_remove_matrix(&matrix);
  ck_assert_uint_eq(res, OK);
}
END_TEST

// equal

START_TEST(equal_matrix_1) {
  matrix_t matrix1, matrix2;
  int res = 0;
  s21_create_matrix(4, 3, &matrix1);
  s21_create_matrix(2, 3, &matrix2);
  set_matrix(2.0, &matrix1);
  set_matrix(2.0, &matrix2);
  res = s21_eq_matrix(&matrix1, &matrix2);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  ck_assert_uint_eq(res, FAILURE);
}
END_TEST

START_TEST(equal_matrix_2) {
  matrix_t matrix1, matrix2;
  int res = 0;
  s21_create_matrix(2, 3, &matrix1);
  s21_create_matrix(2, 3, &matrix2);
  set_matrix(2.0, &matrix1);
  set_matrix(1.0, &matrix2);
  res = s21_eq_matrix(&matrix1, &matrix2);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  ck_assert_uint_eq(res, FAILURE);
}
END_TEST

START_TEST(equal_matrix_3) {
  matrix_t matrix1, matrix2;
  int res = 0;
  s21_create_matrix(3, 3, &matrix1);
  s21_create_matrix(3, 3, &matrix2);
  set_matrix(3.0, &matrix1);
  set_matrix(3.0, &matrix2);
  res = s21_eq_matrix(&matrix1, &matrix2);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  ck_assert_uint_eq(res, SUCCESS);
}
END_TEST

// sum
START_TEST(sum_matrix_1) {
  matrix_t matrix1, matrix2, etalon, result;
  int res = 0;
  ck_assert_uint_eq(s21_create_matrix(4, 4, &matrix1), 0);
  ck_assert_uint_eq(s21_create_matrix(4, 4, &matrix2), 0);
  ck_assert_uint_eq(s21_create_matrix(4, 4, &etalon), 0);

  set_matrix(1.0, &matrix1);
  set_matrix(1.0, &matrix2);
  etalon.matrix[0][0] = 2.0;
  etalon.matrix[0][1] = 4.0;
  etalon.matrix[0][2] = 6.0;
  etalon.matrix[0][3] = 8.0;

  etalon.matrix[1][0] = 10.0;
  etalon.matrix[1][1] = 12.0;
  etalon.matrix[1][2] = 14.0;
  etalon.matrix[1][3] = 16.0;

  etalon.matrix[2][0] = 18.0;
  etalon.matrix[2][1] = 20.0;
  etalon.matrix[2][2] = 22.0;
  etalon.matrix[2][3] = 24.0;

  etalon.matrix[3][0] = 26.0;
  etalon.matrix[3][1] = 28.0;
  etalon.matrix[3][2] = 30.0;
  etalon.matrix[3][3] = 32.0;
  res = s21_sum_matrix(&matrix1, &matrix2, &result);

  ck_assert_uint_eq(res, OK);
  ck_assert_uint_eq(s21_eq_matrix(&result, &etalon), SUCCESS);

  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  s21_remove_matrix(&etalon);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sum_matrix_2) {
  matrix_t matrix1, matrix2, result;
  int res = 0;
  ck_assert_uint_eq(s21_create_matrix(4, 4, &matrix1), 0);
  ck_assert_uint_eq(s21_create_matrix(4, 2, &matrix2), 0);

  set_matrix(1.0, &matrix1);
  set_matrix(1.0, &matrix2);
  res = s21_sum_matrix(&matrix1, &matrix2, &result);

  ck_assert_uint_eq(res, CALCULATION_ERROR);

  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
}
END_TEST

// sub
START_TEST(sub_matrix_1) {
  matrix_t matrix1, matrix2, etalon, result;
  int res = 0;
  ck_assert_uint_eq(s21_create_matrix(4, 4, &matrix1), 0);
  ck_assert_uint_eq(s21_create_matrix(4, 4, &matrix2), 0);
  ck_assert_uint_eq(s21_create_matrix(4, 4, &etalon), 0);

  set_matrix(1.0, &matrix1);
  set_matrix(1.0, &matrix2);
  etalon.matrix[0][0] = 0.0;
  etalon.matrix[0][1] = 0.0;
  etalon.matrix[0][2] = 0.0;
  etalon.matrix[0][3] = 0.0;

  etalon.matrix[1][0] = 0.0;
  etalon.matrix[1][1] = 0.0;
  etalon.matrix[1][2] = 0.0;
  etalon.matrix[1][3] = 0.0;

  etalon.matrix[2][0] = 0.0;
  etalon.matrix[2][1] = 0.0;
  etalon.matrix[2][2] = 0.0;
  etalon.matrix[2][3] = 0.0;

  etalon.matrix[3][0] = 0.0;
  etalon.matrix[3][1] = 0.0;
  etalon.matrix[3][2] = 0.0;
  etalon.matrix[3][3] = 0.0;
  res = s21_sub_matrix(&matrix1, &matrix2, &result);

  ck_assert_uint_eq(res, OK);
  ck_assert_uint_eq(s21_eq_matrix(&result, &etalon), SUCCESS);

  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  s21_remove_matrix(&etalon);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sub_matrix_2) {
  matrix_t matrix1, matrix2, result;
  int res = 0;
  ck_assert_uint_eq(s21_create_matrix(4, 4, &matrix1), 0);
  ck_assert_uint_eq(s21_create_matrix(4, 2, &matrix2), 0);

  set_matrix(1.0, &matrix1);
  set_matrix(1.0, &matrix2);
  res = s21_sub_matrix(&matrix1, &matrix2, &result);

  ck_assert_uint_eq(res, CALCULATION_ERROR);

  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
}
END_TEST

// mult_num
START_TEST(mult_num_1) {
  matrix_t matrix1, etalon, result;
  double num = 3.0;
  ck_assert_uint_eq(s21_create_matrix(4, 4, &matrix1), 0);
  ck_assert_uint_eq(s21_create_matrix(4, 4, &etalon), 0);

  etalon.matrix[0][0] = 3.0;
  etalon.matrix[0][1] = 6.0;
  etalon.matrix[0][2] = 9.0;
  etalon.matrix[0][3] = 12.0;

  etalon.matrix[1][0] = 15.0;
  etalon.matrix[1][1] = 18.0;
  etalon.matrix[1][2] = 21.0;
  etalon.matrix[1][3] = 24.0;

  etalon.matrix[2][0] = 27.0;
  etalon.matrix[2][1] = 30.0;
  etalon.matrix[2][2] = 33.0;
  etalon.matrix[2][3] = 36.0;

  etalon.matrix[3][0] = 39.0;
  etalon.matrix[3][1] = 42.0;
  etalon.matrix[3][2] = 45.0;
  etalon.matrix[3][3] = 48.0;

  set_matrix(1.0, &matrix1);

  ck_assert_uint_eq(s21_mult_number(&matrix1, num, &result), 0);
  ck_assert_uint_eq(s21_eq_matrix(&result, &etalon), SUCCESS);

  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&etalon);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_num_2) {
  matrix_t matrix1, etalon, result;
  double num = 5.0;
  ck_assert_uint_eq(s21_create_matrix(4, 4, &matrix1), 0);
  ck_assert_uint_eq(s21_create_matrix(4, 4, &etalon), 0);

  etalon.matrix[0][0] = 5.0;
  etalon.matrix[0][1] = 10.0;
  etalon.matrix[0][2] = 15.0;
  etalon.matrix[0][3] = 20.0;

  etalon.matrix[1][0] = 25.0;
  etalon.matrix[1][1] = 30.0;
  etalon.matrix[1][2] = 35.0;
  etalon.matrix[1][3] = 40.0;

  etalon.matrix[2][0] = 45.0;
  etalon.matrix[2][1] = 50.0;
  etalon.matrix[2][2] = 55.0;
  etalon.matrix[2][3] = 60.0;

  etalon.matrix[3][0] = 65.0;
  etalon.matrix[3][1] = 70.0;
  etalon.matrix[3][2] = 75.0;
  etalon.matrix[3][3] = 80.0;

  set_matrix(1.0, &matrix1);

  ck_assert_uint_eq(s21_mult_number(&matrix1, num, &result), 0);
  ck_assert_uint_eq(s21_eq_matrix(&result, &etalon), SUCCESS);

  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&etalon);
  s21_remove_matrix(&result);
}
END_TEST

// mult_matrix

START_TEST(mult_matrix_1) {
  matrix_t matrix1, matrix2, etalon, result;
  ck_assert_uint_eq(s21_create_matrix(4, 4, &matrix1), 0);
  ck_assert_uint_eq(s21_create_matrix(4, 4, &matrix2), 0);
  ck_assert_uint_eq(s21_create_matrix(4, 4, &etalon), 0);

  set_matrix(1.0, &matrix1);
  set_matrix(-5.0, &matrix2);

  etalon.matrix[0][0] = 30.0;
  etalon.matrix[0][1] = 40.0;
  etalon.matrix[0][2] = 50.0;
  etalon.matrix[0][3] = 60.0;

  etalon.matrix[1][0] = 46.0;
  etalon.matrix[1][1] = 72.0;
  etalon.matrix[1][2] = 98.0;
  etalon.matrix[1][3] = 124.0;

  etalon.matrix[2][0] = 62.0;
  etalon.matrix[2][1] = 104.0;
  etalon.matrix[2][2] = 146.0;
  etalon.matrix[2][3] = 188.0;

  etalon.matrix[3][0] = 78.0;
  etalon.matrix[3][1] = 136.0;
  etalon.matrix[3][2] = 194.0;
  etalon.matrix[3][3] = 252.0;

  ck_assert_uint_eq(s21_mult_matrix(&matrix1, &matrix2, &result), 0);
  ck_assert_uint_eq(s21_eq_matrix(&result, &etalon), SUCCESS);

  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  s21_remove_matrix(&etalon);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_matrix_2) {
  matrix_t matrix1 = {0}, matrix2 = {0}, result = {0};

  ck_assert_uint_eq(s21_mult_matrix(&matrix1, &matrix2, &result),
                    INVALID_MATRIX);

  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_matrix_3) {
  matrix_t matrix1, matrix2, result;

  ck_assert_uint_eq(s21_create_matrix(2, 3, &matrix1), 0);
  ck_assert_uint_eq(s21_create_matrix(4, 4, &matrix2), 0);

  set_matrix(-5.0, &matrix1);
  set_matrix(1.0, &matrix2);

  ck_assert_uint_eq(s21_mult_matrix(&matrix1, &matrix2, &result),
                    CALCULATION_ERROR);

  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
}
END_TEST

// trans
START_TEST(transpose_matrix_1) {
  matrix_t matrix1 = {0};

  ck_assert_uint_eq(s21_transpose(&matrix1, &matrix1), INVALID_MATRIX);

  s21_remove_matrix(&matrix1);
}
END_TEST

START_TEST(transpose_matrix_2) {
  matrix_t matrix1, etalon, result;
  ck_assert_uint_eq(s21_create_matrix(2, 3, &matrix1), 0);
  ck_assert_uint_eq(s21_create_matrix(3, 2, &etalon), 0);

  etalon.matrix[0][0] = 1.0;
  etalon.matrix[0][1] = 4.0;

  etalon.matrix[1][0] = 2.0;
  etalon.matrix[1][1] = 5.0;

  etalon.matrix[2][0] = 3.0;
  etalon.matrix[2][1] = 6.0;

  set_matrix(1.0, &matrix1);

  ck_assert_uint_eq(s21_transpose(&matrix1, &result), 0);
  ck_assert_uint_eq(s21_eq_matrix(&result, &etalon), SUCCESS);

  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&etalon);
  s21_remove_matrix(&result);
}
END_TEST

// determinant

START_TEST(determinant_matrix_1) {
  matrix_t matrix1;
  ck_assert_uint_eq(s21_create_matrix(2, 3, &matrix1), 0);

  matrix1.matrix[0][0] = 1;
  matrix1.matrix[0][1] = 2;
  matrix1.matrix[0][2] = 3;

  matrix1.matrix[1][0] = 4;
  matrix1.matrix[1][1] = 5;
  matrix1.matrix[1][2] = 6;

  double result;
  ck_assert_uint_eq(s21_determinant(&matrix1, &result), 2);

  s21_remove_matrix(&matrix1);
}
END_TEST

START_TEST(determinant_matrix_2) {
  matrix_t matrix1;
  ck_assert_uint_eq(s21_create_matrix(1, 1, &matrix1), 0);

  matrix1.matrix[0][0] = 13;

  double result;
  double etalon = 13;

  ck_assert_uint_eq(s21_determinant(&matrix1, &result), 0);
  ck_assert_float_eq_tol(result, etalon, S21_EPS);

  s21_remove_matrix(&matrix1);
}
END_TEST

// calc_compliments

START_TEST(calc_complements_1) {
  matrix_t matrix1, result;
  ck_assert_uint_eq(s21_create_matrix(2, 3, &matrix1), 0);

  matrix1.matrix[0][0] = 1;
  matrix1.matrix[0][1] = 2;
  matrix1.matrix[0][2] = 3;

  matrix1.matrix[1][0] = 0;
  matrix1.matrix[1][1] = 4;
  matrix1.matrix[1][2] = 2;

  ck_assert_uint_eq(s21_calc_complements(&matrix1, &result), 2);

  s21_remove_matrix(&matrix1);
}
END_TEST

START_TEST(calc_complements_2) {
  matrix_t matrix1, etalon, result;
  ck_assert_uint_eq(s21_create_matrix(3, 3, &matrix1), 0);
  ck_assert_uint_eq(s21_create_matrix(3, 3, &etalon), 0);

  matrix1.matrix[0][0] = 2;
  matrix1.matrix[0][1] = 5;
  matrix1.matrix[0][2] = 7;

  matrix1.matrix[1][0] = 6;
  matrix1.matrix[1][1] = 3;
  matrix1.matrix[1][2] = 4;

  matrix1.matrix[2][0] = 5;
  matrix1.matrix[2][1] = -2;
  matrix1.matrix[2][2] = -3;

  etalon.matrix[0][0] = -1;
  etalon.matrix[0][1] = 38;
  etalon.matrix[0][2] = -27;

  etalon.matrix[1][0] = 1;
  etalon.matrix[1][1] = -41;
  etalon.matrix[1][2] = 29;

  etalon.matrix[2][0] = -1;
  etalon.matrix[2][1] = 34;
  etalon.matrix[2][2] = -24;

  ck_assert_uint_eq(s21_calc_complements(&matrix1, &result), 0);
  ck_assert_uint_eq(s21_eq_matrix(&result, &etalon), SUCCESS);

  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&etalon);
  s21_remove_matrix(&result);
}
END_TEST

// inverse_matrix

START_TEST(inverse_matrix_1) {
  matrix_t matrix1, result;
  ck_assert_uint_eq(s21_create_matrix(3, 3, &matrix1), 0);

  matrix1.matrix[0][0] = 1;
  matrix1.matrix[0][1] = 2;
  matrix1.matrix[0][2] = 3;

  matrix1.matrix[1][0] = 4;
  matrix1.matrix[1][1] = 5;
  matrix1.matrix[1][2] = 6;

  matrix1.matrix[2][0] = 7;
  matrix1.matrix[2][1] = 8;
  matrix1.matrix[2][2] = 9;

  ck_assert_uint_eq(s21_inverse_matrix(&matrix1, &result), 1);

  s21_remove_matrix(&matrix1);
}
END_TEST

START_TEST(inverse_matrix_2) {
  matrix_t matrix1, result;
  ck_assert_uint_eq(s21_create_matrix(2, 3, &matrix1), 0);

  matrix1.matrix[0][0] = 1;
  matrix1.matrix[0][1] = 2;
  matrix1.matrix[0][2] = 3;

  matrix1.matrix[1][0] = 4;
  matrix1.matrix[1][1] = 5;
  matrix1.matrix[1][2] = 6;

  ck_assert_uint_eq(s21_inverse_matrix(&matrix1, &result), 2);

  s21_remove_matrix(&matrix1);
}
END_TEST

START_TEST(inverse_matrix_3) {
  matrix_t matrix1, etalon, result;
  ck_assert_uint_eq(s21_create_matrix(4, 4, &matrix1), 0);
  ck_assert_uint_eq(s21_create_matrix(4, 4, &etalon), 0);

  matrix1.matrix[0][0] = 1;
  matrix1.matrix[0][1] = 2;
  matrix1.matrix[0][2] = 3;
  matrix1.matrix[0][3] = 4;

  matrix1.matrix[1][0] = 4;
  matrix1.matrix[1][1] = 0;
  matrix1.matrix[1][2] = 0;
  matrix1.matrix[1][3] = 3;

  matrix1.matrix[2][0] = 0;
  matrix1.matrix[2][1] = 3;
  matrix1.matrix[2][2] = 3;
  matrix1.matrix[2][3] = 1;

  matrix1.matrix[3][0] = 0;
  matrix1.matrix[3][1] = 7;
  matrix1.matrix[3][2] = 2;
  matrix1.matrix[3][3] = 6;

  etalon.matrix[0][0] = -45.0 / 199.0;
  etalon.matrix[0][1] = 61.0 / 199.0;
  etalon.matrix[0][2] = 51.0 / 199.0;
  etalon.matrix[0][3] = -9.0 / 199.0;

  etalon.matrix[1][0] = -64.0 / 199.0;
  etalon.matrix[1][1] = 16.0 / 199.0;
  etalon.matrix[1][2] = 46.0 / 199.0;
  etalon.matrix[1][3] = 27.0 / 199.0;

  etalon.matrix[2][0] = 44.0 / 199.0;
  etalon.matrix[2][1] = -11.0 / 199.0;
  etalon.matrix[2][2] = 43.0 / 199.0;
  etalon.matrix[2][3] = -31.0 / 199.0;

  etalon.matrix[3][0] = 60.0 / 199.0;
  etalon.matrix[3][1] = -15.0 / 199.0;
  etalon.matrix[3][2] = -68.0 / 199.0;
  etalon.matrix[3][3] = 12.0 / 199.0;

  ck_assert_uint_eq(s21_inverse_matrix(&matrix1, &result), 0);
  ck_assert_uint_eq(s21_eq_matrix(&result, &etalon), SUCCESS);

  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&etalon);
  s21_remove_matrix(&result);
}
END_TEST

Suite *suite_creating() {
  Suite *suite = suite_create("s21_matrix");

  TCase *tcase_create_matrix = tcase_create("create_matrix");
  tcase_add_test(tcase_create_matrix, create_matrix_1);
  tcase_add_test(tcase_create_matrix, create_matrix_2);
  tcase_add_test(tcase_create_matrix, create_matrix_3);
  suite_add_tcase(suite, tcase_create_matrix);

  TCase *tcase_remove_matrix = tcase_create("remove_matrix");
  tcase_add_test(tcase_remove_matrix, remove_matrix_1);
  tcase_add_test(tcase_remove_matrix, remove_matrix_2);
  tcase_add_test(tcase_remove_matrix, remove_matrix_3);
  suite_add_tcase(suite, tcase_remove_matrix);

  TCase *tcase_equal_matrix = tcase_create("equal_matrix");
  tcase_add_test(tcase_equal_matrix, equal_matrix_1);
  tcase_add_test(tcase_equal_matrix, equal_matrix_2);
  tcase_add_test(tcase_equal_matrix, equal_matrix_3);
  suite_add_tcase(suite, tcase_equal_matrix);

  TCase *tcase_sum_matrix = tcase_create("sum_matrix");
  tcase_add_test(tcase_sum_matrix, sum_matrix_1);
  tcase_add_test(tcase_sum_matrix, sum_matrix_2);
  suite_add_tcase(suite, tcase_sum_matrix);

  TCase *tcase_sub_matrix = tcase_create("sub_matrix");
  tcase_add_test(tcase_sub_matrix, sub_matrix_1);
  tcase_add_test(tcase_sub_matrix, sub_matrix_2);
  suite_add_tcase(suite, tcase_sub_matrix);

  TCase *tcase_mult_num = tcase_create("mult_num");
  tcase_add_test(tcase_mult_num, mult_num_1);
  tcase_add_test(tcase_mult_num, mult_num_2);
  suite_add_tcase(suite, tcase_mult_num);

  TCase *tcase_mult_matrix = tcase_create("mult_matrix");
  tcase_add_test(tcase_mult_matrix, mult_matrix_1);
  tcase_add_test(tcase_mult_matrix, mult_matrix_2);
  tcase_add_test(tcase_mult_matrix, mult_matrix_3);
  suite_add_tcase(suite, tcase_mult_matrix);

  TCase *tcase_transpose_matrix = tcase_create("transpose_matrix");
  tcase_add_test(tcase_transpose_matrix, transpose_matrix_1);
  tcase_add_test(tcase_transpose_matrix, transpose_matrix_2);
  suite_add_tcase(suite, tcase_transpose_matrix);

  TCase *tcase_determinant_matrix = tcase_create("determinant_matrix");
  tcase_add_test(tcase_determinant_matrix, determinant_matrix_1);
  tcase_add_test(tcase_determinant_matrix, determinant_matrix_2);
  suite_add_tcase(suite, tcase_determinant_matrix);

  TCase *tcase_calc_complements = tcase_create("calc_complements");
  tcase_add_test(tcase_calc_complements, calc_complements_1);
  tcase_add_test(tcase_calc_complements, calc_complements_2);
  suite_add_tcase(suite, tcase_calc_complements);

  TCase *tcase_inverse_matrix = tcase_create("inverse_matrix");
  tcase_add_test(tcase_inverse_matrix, inverse_matrix_1);
  tcase_add_test(tcase_inverse_matrix, inverse_matrix_2);
  tcase_add_test(tcase_inverse_matrix, inverse_matrix_3);
  suite_add_tcase(suite, tcase_inverse_matrix);

  return suite;
}

int main() {
  int number_failed;
  Suite *suite = suite_creating();
  SRunner *srunner = srunner_create(suite);
  srunner_run_all(srunner, CK_VERBOSE);
  number_failed = srunner_ntests_failed(srunner);
  srunner_free(srunner);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}