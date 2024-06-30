#include "s21_matrix.h"

/**
 * @brief Функция транспонирования матрицы.
 * @param A Указатель на матрицу, которую транспонируем.
 * @param result Указатель на матрицу, в которую запишется транспонированная
 * матрица.
 * @return 0 - OK; 1 - Ошибка, некорректная матрица.
 */
int s21_transpose(matrix_t *A, matrix_t *result) {
  int res = OK;
  res = s21_create_matrix(A->columns, A->rows, result);
  for (int i = 0; i < A->rows && !res; ++i) {
    for (int j = 0; j < A->columns && !res; ++j) {
      result->matrix[j][i] = A->matrix[i][j];
    }
  }
  return res;
}
