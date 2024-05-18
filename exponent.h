#ifndef EXPONENT_H_INCLUDED
#define EXPONENT_H_INCLUDED

#include "matrix.h"
#include "math.h"
#include "operations_raws.h"
#include "operations.h"

Matrix* matrix_assign(Matrix* m1, Matrix* m2);

Matrix* matrix_power(Matrix* A, int power, Matrix* res);

Matrix* matrix_exponential(const Matrix *A, double eps);

#endif // EXPONENT_H_INCLUDED
