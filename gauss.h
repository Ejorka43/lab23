#ifndef GAUSS_H_INCLUDED
#define GAUSS_H_INCLUDED

#include "matrix.h"
#include "operations_raws.h"
#include "operations.h"

Matrix* add_multiply_row_by_scalar(Matrix* m, size_t k, size_t t, double scalar);
Matrix* inverse_matrix(Matrix *m);

Matrix* solve_system(Matrix* A, Matrix* B, Matrix* x);

#endif // GAUSS_H_INCLUDED
