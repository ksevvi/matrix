#include "s21_matrix.h"

/**
 * @brief Функция нахождения определителя матрицы {A}.
 * @param A Указатель на матрицу, в которой ищем определитель.
 * @param result переменная типа double, в которую запишется определитель.
 * @return 0 - OK, 2 - Ошибка вычисления.
 */
int s21_determinant(matrix_t *A, double *result) {
  int res = OK;
  // *result = 1.0;
  if (A->rows == A->columns)
    *result = determinant(A);
  else
    res = CALCULATION_ERROR;
  return res;
}

/**
 * @brief Функция нахождения определителя матрицы {A}.
 * @param A Указатель на матрицу, в которой ищем определитель.
 * @return {det}. Функция возвращает вычисленный определитель.
 */
int determinant(matrix_t *A) {
  double det;
  if (A->rows == 1) det = A->matrix[0][0];
  if (A->rows == 2) {
    det = A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
  }
  if (A->rows >= 3) {
    int i = 0;
    det = 0;
    for (int j = 0; j < A->columns; j++) {
      matrix_t minor;
      s21_getting_minor_matrix(A, &minor, i, j);
      det += A->matrix[i][j] * pow(-1, i + j + 2) * determinant(&minor);
      s21_remove_matrix(&minor);
    }
  }
  return det;
}