#include "s21_matrix.h"

/**
 * @brief Функция создания матрицы по указанным значениям
 * @param rows Число строк в матрице.
 * @param column Число столбцов в матрице.
 * @param results Указатель на структру matrix_t.
 * @return 0 - OK; 1 - Ошибка, некорректная матрица; 2 - Ошибка вычисления.
 */
int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int res = OK;
  if (rows > 0 && columns > 0) {
    result->columns = columns;
    result->rows = rows;
  } else {
    res = INVALID_MATRIX;
  }
  result->matrix = malloc(rows * sizeof(double *));
  for (int i = 0; i < rows && !res; ++i) {
    result->matrix[i] = malloc(columns * sizeof(double));
  }
  for (int i = 0; i < rows && !res; ++i) {
    for (int j = 0; j < columns && !res; ++j) {
      result->matrix[i][j] = 0;
    }
  }
  return res;
}