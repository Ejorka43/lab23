#include <stdio.h>
#include <stdlib.h>
#include "exponent.h"

Matrix* matrix_assign(Matrix* m1, Matrix* m2) {
    if (m1->rows != m2->rows || m1->cols != m2->cols) {
        return NULL;
    }
    for (size_t i = 0; i < m1->rows; ++i) {
        for (size_t j = 0; j < m1->cols; ++j) {
            double key = matrix_get(m2, i, j);
            matrix_set(m1, i, j, key);
        }
    }
    return m1;
}

Matrix* matrix_power(Matrix* A, int power, Matrix* res) {
    if (power == 0) {
        matrix_free(res);
        return matrix_create_unit_square(A->rows);
    }
    else if (power == 1) {
        matrix_free(res);
        return matrix_clone(A);
    }
    else {
        Matrix* temp = matrix_clone(A);

        for (int i = 2; i <= power; i++) {
            matrix_free(res);
            res = matrix_multiply(temp, A);
            matrix_assign(temp, res);
        }

        matrix_free(temp);
        return res;
    }
}

Matrix* matrix_exponential(const Matrix *A, double eps) {
    Matrix *result = matrix_create_unit_square(A->rows);

    Matrix *temp = matrix_clone(A);

    double n_factorial = 1;
    double norm_term = 0;
    for (int n = 1; ; n++) {
        matrix_power(A, n, temp);
        n_factorial *= n;
        matrix_multiply_scalar(temp, 1.0 / n_factorial);
        result = matrix_sum(temp, result);
        norm_term = max_row_norm(temp);
        if (norm_term < eps) {
            break;
        }
    }
    matrix_free(temp);
    return result;
}
