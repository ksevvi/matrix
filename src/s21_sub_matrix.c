#include "s21_matrix.h"

/**
 * @brief Функция вычитания двух матриц.
 * @param A Указатель на первую матрицу (уменьшаемое).
 * @param B Указатель на вторую матрицу (вычитаемое).
 * @param result Указатель на матрицу, в которую запишется результат вычитания.
 * @return 0 - OK; 1 - Ошибка, некорректная матрица; 2 - Ошибка вычисления.
 */
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res = OK;
  if (A->columns == B->columns && A->rows == B->rows) {
    res = s21_create_matrix(A->rows, A->columns, result);
  } else {
    res = CALCULATION_ERROR;
  }
  for (int i = 0; i < A->rows && !res; ++i) {
    for (int j = 0; j < A->columns && !res; ++j) {
      result->matrix[i][j] += (A->matrix[i][j] - B->matrix[i][j]);
    }
  }
  return res;
}