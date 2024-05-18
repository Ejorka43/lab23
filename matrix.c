#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

Matrix* matrix_alloc(size_t rows, size_t cols) {                         // Allocates memory for the matrix

    Matrix* matrix = (Matrix*) malloc(sizeof(Matrix));
    if (matrix == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    matrix->rows = rows;
    matrix->cols = cols;

    matrix->data = (double*) malloc(rows * cols * sizeof(double));

    if (matrix->data == NULL) {
        printf("Memory allocation failed.\n");
        free(matrix);
        return NULL;
    }

    return matrix;
}

Matrix* matrix_clone(const Matrix* m) {                                 // Makes matrix clone

    Matrix* clone = matrix_alloc(m->rows, m->cols);

    if (clone == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }


    for (size_t i = 0; i < m->rows; i++) {
        for (size_t j = 0; j < m->cols; j++) {
            clone->data[i * m->cols + j] = m->data[i * m->cols + j];
        }
    }

    return clone;
}

Matrix* matrix_resize(Matrix* m, size_t rows, size_t cols) {             // Changes size of matrix
    double* newData = (double*) realloc(m->data, rows * cols * sizeof(double));

    if (newData == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    m->rows = rows;
    m->cols = cols;
    m->data = newData;

    return m;
}

void matrix_set(Matrix* matrix, size_t row, size_t col, double value) {      // Sets values ​​to matrix cells
    size_t index = row * matrix->cols + col;
    matrix->data[index] = value;
}

double matrix_get(const Matrix* matrix, size_t row, size_t col) {            // Gets values from matrix sets
    size_t index = row * matrix->cols + col;
    return matrix->data[index];
}

void matrix_print(const Matrix* matrix) {                                 // Prints matrix
    for (size_t i = 0; i < matrix->rows; i++) {
        for (size_t j = 0; j < matrix->cols; j++) {
            printf("%-13lf", matrix_get(matrix, i, j));
        }
        printf("\n");
    }
}

Matrix* zero_matrix_set(Matrix* matrix) {
    size_t i, j;

    // Setting each element of the matrix to zero.
    for (i = 0; i < matrix->rows; i++) {
        for (j = 0; j < matrix->cols; j++) {
            matrix->data[i * matrix->cols + j] = 0.0;
        }
    }

    return matrix;  // Returning the matrix with all elements set to zero.
}

Matrix* zero_matrix_alloc(size_t rows, size_t cols) {
    Matrix* matrix = matrix_alloc(rows, cols);  // Allocating memory for the matrix.
    zero_matrix_set(matrix);                    // Setting all elements to zero.
    return matrix;                              // Returning the allocated matrix.
}

Matrix* matrix_create_unit_square(size_t size) {
    Matrix* matrix = zero_matrix_alloc(size, size);

    if (matrix == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < size; i++) {
        double key = 1;
        matrix->data[i * size + i] = key;
    }

    return matrix;
}

void matrix_free(Matrix* matrix) {
    free(matrix->data);  // Freeing the memory allocated for the matrix data.
    free(matrix);        // Freeing the memory allocated for the matrix structure.
}
