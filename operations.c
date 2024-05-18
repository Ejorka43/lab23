#include <stdio.h>
#include <stdlib.h>
#include "operations.h"
Matrix* matrix_sum(Matrix* m1, Matrix* m2) {
    if (m1->rows != m2->rows || m1->cols != m2->cols) {  // Checking for matrices of different sizes.
        printf("Matrix size error \n");
        return NULL;
    }

    Matrix* result = matrix_alloc(m1->rows, m1->cols);

    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->cols; j++) {
            double sum =  matrix_get(m1, i, j) + matrix_get(m2, i, j);
            matrix_set(result, i, j, sum);
        }
    }

    return result;
}

void matrix_multiply_scalar(Matrix* matrix, double scalar) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            double multi = matrix_get(matrix, i, j) * scalar;
            matrix_set(matrix, i, j, multi);
        }
    }
}

Matrix* matrix_multiply(const Matrix* m1, const Matrix* m2) {
    if (m1->cols != m2->rows) {
        return NULL;
    }

    Matrix* result = matrix_alloc(m1->rows, m2->cols);

    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m2->cols; j++) {
            matrix_set(result, i, j, 0);
            //double multi = 0;
            double multi;
            for (int k = 0; k < m1->cols; k++) {
                multi +=  matrix_get(m1, i, k) * matrix_get(m2, k, j);
                matrix_set(result, i, j, multi);
            }
            multi = 0;
        }
    }

    return result;
}


void matrix_transpose_simple(Matrix* matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = i + 1; j < matrix->cols; j++) {
             double key1 = matrix_get(matrix, i, j);
             double key2 = matrix_get(matrix, j, i);
             matrix_set(matrix, i, j, key2);
             matrix_set(matrix, j, i, key1);
        }
    }
}

Matrix* matrix_transpose(const Matrix* matrix) {
    Matrix* result = matrix_alloc(matrix->cols, matrix->rows);

    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            double key = matrix_get(matrix, j, i);
            matrix_set(result, i, j, key);;
        }
    }

    return result;
}
