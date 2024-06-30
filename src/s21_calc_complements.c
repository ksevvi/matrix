#include "s21_matrix.h"

/**
 * @brief Функция нахождения матрицы алгебраических дополнений.
 * @param A Указатель на матрицу.
 * @param result Указатель на матрицу, в которую запишется результат.
 * @return 0 - OK; 1 - Ошибка, некорректная матрица; 2 - Ошибка вычисления.
 */
int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int res = OK;
  res = s21_create_matrix(A->rows, A->columns, result);
  if (A->columns != A->rows) res = CALCULATION_ERROR;
  if (A->rows == 1 && !res) result->matrix = A->matrix;
  if (A->rows >= 2 && !res) {
    for (int i = 0; i < A->rows; ++i) {
      for (int j = 0; j < A->columns; ++j) {
        matrix_t minor;
        s21_getting_minor_matrix(A, &minor, i, j);
        result->matrix[i][j] = pow(-1, i + j) * determinant(&minor);
        s21_remove_matrix(&minor);
      }
    }
  }
  return res;
}