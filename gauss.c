#include <stdio.h>
#include <stdlib.h>
#include "gauss.h"

Matrix* add_multiply_row_by_scalar(Matrix* m, size_t k, size_t t, double scalar){
    for (size_t i = 0; i < m->cols; ++i) {
        matrix_set(m, k, i, matrix_get(m, k, i) + scalar * matrix_get(m, t, i));
    }
    return m;
}

Matrix* inverse_matrix(Matrix* m) {
    if (m->rows != m->cols) {
        return NULL;
    }

    Matrix* result = matrix_create_unit_square(m->rows);
    if (result == NULL) {
        return NULL;
    }

    Matrix* temp = matrix_clone(m);
    if (temp == NULL) {
        matrix_free(result);
        return NULL;
    }

    for (size_t i = 0; i < temp->rows; ++i) {
        size_t row = i;
        while (row < temp->rows && matrix_get(temp, row, i) == 0) {
            row++;
        }
        if (row == temp->rows) {
            matrix_free(result);
            matrix_free(temp);
            return NULL;
        }
        permute_string(temp, i, row);
        permute_string(result, i, row);

        double element = matrix_get(temp, i, i);
        multiply_row(temp, 1 / element, i);
        multiply_row(result, 1 / element, i);

        for (size_t j = 0; j < temp->rows; ++j) {
            if (j != i) {
                double scalar = -matrix_get(temp, j, i);

                for (size_t k = 0; k < temp->cols; ++k) {
                    matrix_set(temp, j, k, matrix_get(temp, j, k) + scalar * matrix_get(temp, i, k));
                    matrix_set(result, j, k, matrix_get(result, j, k) + scalar * matrix_get(result, i, k));
                }
            }
        }
    }

    matrix_free(temp);
    return result;
}

Matrix* solve_system(Matrix* A, Matrix* B, Matrix* x) {

    if (A->rows != A->cols) {
        return NULL;
    }
    Matrix *A_inv = inverse_matrix(A);
    if (A_inv == NULL) {
        return NULL;
    }

    x = matrix_multiply(A_inv, B);
    matrix_free(A_inv);
    return x;
}

