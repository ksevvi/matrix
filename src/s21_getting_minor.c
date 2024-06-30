#include "s21_matrix.h"

/**
 * @brief Функция нахождения минора матрицы (вычеркиванием строки и столбца).
 * @param A Указатель на исходную матрицу.
 * @param minor Указатель на матрицу, в коотрую запишется минор {A}.
 * @param i номер строки для "вычеркивания".
 * @param j номер столбца для "вычеркивания".
 * @return 0 - OK; 1 - Ошибка, некорректная матрица.
 */
int s21_getting_minor_matrix(matrix_t *A, matrix_t *minor, int i, int j) {
  int res = OK;
  res = s21_create_matrix(A->rows - 1, A->columns - 1, minor);
  for (int matrix_i = 0, minor_i = 0; matrix_i < A->rows && !res;
       ++matrix_i, ++minor_i) {
    if (matrix_i == i) {
      ++matrix_i;
    }
    if (matrix_i == A->rows) {
      break;
    }
    for (int matrix_j = 0, minor_j = 0; matrix_j < A->columns && !res;
         ++matrix_j, ++minor_j) {
      if (matrix_j == j) {
        ++matrix_j;
      }
      if (matrix_j == A->columns) {
        break;
      }
      minor->matrix[minor_i][minor_j] = A->matrix[matrix_i][matrix_j];
    }
  }
  return res;
}