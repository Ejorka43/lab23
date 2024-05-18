#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "operations_raws.h"

void multiply_row(Matrix* matrix, double scalar, double row) {
    for (size_t i = 0; i < matrix->cols; i++) {
        double key = matrix_get(matrix, row, i);
        matrix_set(matrix, row, i, key * scalar);
    }
}

void add_strings(Matrix* matrix, size_t row1, size_t row2) { //прибавим к первому второй
    for (size_t i = 0; i < matrix->cols; i++) {
        double key = matrix_get(matrix, row1, i) + matrix_get(matrix, row2, i);
        matrix_set(matrix, row1, i, key);
    }
}

void permute_string(Matrix* matrix, size_t row1, size_t row2) {
    for (size_t i = 0; i < matrix->cols; i++) {
        double key1 = matrix_get(matrix, row1, i);
        double key2 = matrix_get(matrix, row2, i);
        matrix_set(matrix, row1, i, key2);
        matrix_set(matrix, row2, i, key1);
    }
}

size_t max_row_norm(Matrix* matrix) {
    size_t maxRowNorm = 0;
    for (size_t i = 0; i < matrix->rows; i++) {
        int rowNorm = 0;
        for (size_t j = 0; j < matrix->cols; j++) {
            rowNorm += abs(matrix_get(matrix, i, j));
        }
        if (rowNorm > maxRowNorm) {
            maxRowNorm = rowNorm;
        }
    }
    return maxRowNorm;
}

size_t max_col_norm(Matrix* matrix) {
    size_t maxColumnNorm = 0;
    for (size_t j = 0; j < matrix->cols; j++) {
        int columnNorm = 0;
        for (size_t i = 0; i < matrix->rows; i++) {
            columnNorm += abs(matrix_get(matrix, i, j));
        }
        if (columnNorm > maxColumnNorm) {
            maxColumnNorm = columnNorm;
        }
    }
    return maxColumnNorm;
}

Matrix*  allocate_submatrix(Matrix* matrix, size_t excluding_row, size_t excluding_col) {
    Matrix* submatrix = matrix_alloc(matrix->rows - 1 , matrix->cols - 1);

    size_t dest_row = 0;
    for (size_t row = 0; row < matrix->rows; row++) {
        if (row == excluding_row) {
            continue;
        }
        size_t dest_col = 0;
        for (size_t col = 0; col < matrix->cols; col++) {
            if (col == excluding_col) {
                continue;
            }
            submatrix->data[dest_row * submatrix->cols + dest_col] = matrix->data[row * matrix->cols + col];
            dest_col++;
        }
        dest_row++;
    }

    return submatrix;
}
double matrix_determinant(Matrix* mat) {
    if (mat->rows != mat->cols) {
        return 0; // Determinant is not available for a non-square matrix
    }

    if (mat->rows == 1) {
        return mat->data[0];
    }

    double det = 0;
    int sign = 1;
    for (size_t col = 0; col < mat->cols; col++) {
        Matrix* subMat = allocate_submatrix(mat, 0, col);
        det += sign * mat->data[col] * matrix_determinant(subMat);
        sign = -sign;
        free(subMat->data);
    }

    return det;
}
