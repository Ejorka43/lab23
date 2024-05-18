#ifndef OPERATIONS_RAWS_H_INCLUDED
#define OPERATIONS_RAWS_H_INCLUDED

#include "matrix.h"
#include "math.h"

void multiply_row(Matrix* matrix, double scalar, double row);

void add_strings(Matrix* matrix, size_t row, size_t row2);

void permute_string(Matrix* matrix, size_t row1, size_t row2);

size_t max_row_norm(Matrix* matrix);

size_t max_col_norm(Matrix* matrix);

Matrix* allocate_submatrix(Matrix* matrix, size_t excluding_row, size_t excluding_col);

double matrix_determinant(Matrix* mat);

#endif // OPERATIONS_RAWS_H_INCLUDED
