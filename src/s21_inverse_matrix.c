#include "s21_matrix.h"

/**
 * @brief Функция нахождения обратной матрицы.
 * @param A Указатель на исходную матрицу.
 * @param result Указатель на матрицу, в которую запишется обратная матрица.
 * @return 0 - OK; 1 - Ошибка, некорректная матрица; 2 - Ошибка вычисления.
 */
int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int res = OK;
  double deter_A;
  res = s21_determinant(A, &deter_A);
  if (A->rows == A->columns && res == 0 && deter_A != 0) {
    matrix_t calc_matr, mult_matr;
    res = s21_calc_complements(A, &calc_matr);
    res = s21_mult_number(&calc_matr, 1 / deter_A, &mult_matr);
    res = s21_transpose(&mult_matr, result);
    s21_remove_matrix(&calc_matr);
    s21_remove_matrix(&mult_matr);
  } else if (deter_A == 0) {
    res = INVALID_MATRIX;
  } else {
    res = CALCULATION_ERROR;
  }
  return res;
}