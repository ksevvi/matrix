#include "s21_matrix.h"

/**
 * @brief Функция удаления матрицы.
 * Функция очищает всю выделенную память для матрицы {A} и устанавливает
 * новый указатель на NULL.
 * @param A Указатель на матрицу, которую хотим удалить.
 */
void s21_remove_matrix(matrix_t *A) {
  if (A) {
    for (int i = 0; i < A->rows; ++i) {
      free(A->matrix[i]);
    }
    free(A->matrix);
    A->matrix = NULL;
  }
  A->rows = 0;
  A->columns = 0;
}