#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

typedef struct {
    double* data;
    size_t rows;
    size_t cols;
} Matrix;

Matrix* matrix_alloc(size_t rows, size_t cols);

Matrix* matrix_clone(const Matrix* m);

Matrix* matrix_resize(Matrix* m, size_t rows, size_t cols);

double matrix_get(const Matrix* matrix, size_t row, size_t col);

void matrix_set(Matrix* matrix, size_t row, size_t col, double value);

void matrix_print(const Matrix* matrix);

void matrix_free(Matrix* matrix);

Matrix* zero_matrix_set(Matrix* matrix);

Matrix* zero_matrix_alloc(size_t rows, size_t cols);

Matrix* matrix_create_unit_square(size_t size);
#endif // MATRIX_H_INCLUDED
