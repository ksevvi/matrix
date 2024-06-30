#include "s21_matrix.h"

/**
 * @brief Функция сравнения двух матриц.
 * @param A Указатель на первую матрицу.
 * @param B Указатель на вторую матрицу.
 * @return 1 - SUCCESS (если матрицы равны); 0 - FAILURE
 * (если матрицы невозможно сравнить или если они не равны).
 */
int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int res = SUCCESS;
  if (A->columns != B->columns || A->rows != B->rows) {
    res = FAILURE;
  }
  for (int i = 0; i < A->rows && res; ++i) {
    for (int j = 0; j < A->columns && res; ++j) {
      if (fabs(A->matrix[i][j] - B->matrix[i][j]) > S21_EPS) {
        res = FAILURE;
      }
    }
  }
  return res;
}