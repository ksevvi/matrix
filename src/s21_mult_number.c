#include "s21_matrix.h"

/**
 * @brief Функция умножения матрицы на число.
 * @param A Указатель на матрицу.
 * @param number Указатель на число, на которое умножаем матрицу.
 * @param result Указатель на матрицу, в которую запишется результат умножения.
 * @return 0 - OK; 1 - Ошибка, некорректная матрица.
 */
int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int res = OK;
  res = s21_create_matrix(A->rows, A->columns, result);
  for (int i = 0; i < A->rows && !res; ++i) {
    for (int j = 0; j < A->columns && !res; ++j) {
      result->matrix[i][j] += (A->matrix[i][j] * number);
    }
  }
  return res;
}