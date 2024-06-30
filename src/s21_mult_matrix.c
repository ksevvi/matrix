#include "s21_matrix.h"

/**
 * @brief Функция умножения двух матриц.
 * @param A Указатель на первую матрицу (первый множитель).
 * @param B Указатель на вторую матрицу (второй множитель).
 * @param result Указатель на матрицу, в которую запишется результат умножения.
 * @return 0 - OK; 1 - Ошибка, некорректная матрица; 2 - Ошибка вычисления.
 */
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res = OK;
  if (A->columns == B->rows) {
    res = s21_create_matrix(A->rows, B->columns, result);
  } else {
    res = CALCULATION_ERROR;
  }
  for (int i = 0; i < A->rows && !res; ++i) {
    for (int j = 0; j < B->columns && !res; ++j) {
      for (int k = 0; k < A->columns && !res; ++k) {
        result->matrix[i][j] += (A->matrix[i][k] * B->matrix[k][j]);
      }
    }
  }
  return res;
}