#ifndef OPERATIONS_H_INCLUDED
#define OPERATIONS_H_INCLUDED

#include "matrix.h"
#include "math.h"

Matrix* matrix_sum(Matrix* m1, Matrix* m2);

void matrix_multiply_scalar(Matrix* matrix, double scalar);

Matrix* matrix_multiply(const Matrix* m1, const Matrix* m2);

void matrix_transpose_simple(Matrix* matrix);

Matrix* matrix_transpose(const Matrix* matrix);

#endif // OPERATIONS_H_INCLUDED
