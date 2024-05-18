#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "operations.h"
#include "operations_raws.h"
#include "gauss.h"
#include "exponent.h"

int main()
{
    while(1){
        printf("Choose what part of task to do: \n");
        printf("1) Struct of matrix \n");
        printf("2) Operations with matrix \n");
        printf("3) Operations with rows \n");
        printf("4) Gauss method \n");
        printf("5) Exponent count \n");
        int choice;
        scanf("%d", &choice);

        switch(choice){
        case 1:
            printf("Enter your matrix size (first is height, second is width):\n");
            size_t h1, w1;
            scanf("%zu %zu", &h1, &w1);

            Matrix* matrix = matrix_alloc(h1, w1);

            if (matrix == NULL) {
                return 1;  // Exiting the program with a failure status.
            }

            if (matrix != NULL) {
                printf("Matrix created successfully.\n");
            }

            printf("Enter the elements of the matrix:\n");
            for (size_t i = 0; i < h1; i++) {
                for (size_t j = 0; j < w1; j++) {
                    double element;
                    scanf("%lf", &element);
                    matrix_set(matrix, i, j, element);
                }
            }

            printf("Matrix:\n");
            matrix_print(matrix);

            Matrix* matrix2 = matrix_clone(matrix);
            printf("Matrix clone:\n");
            matrix_print(matrix2);

            printf("Enter your resized matrix size (first is height, second is width):\n");
            size_t h2, w2;
            scanf("%zu %zu", &h2, &w2);

            Matrix* matrix3 = matrix_resize(matrix2, h2, w2);
            printf("Matrix resized:\n");
            matrix_print(matrix3);

            printf("Enter your zero matrix size (first is height, second is width):\n");
            size_t h3, w3;
            scanf("%zu %zu", &h3, &w3);

            Matrix* matrix4 = zero_matrix_alloc(h3, w3);
            printf("Zero matrix:\n");
            matrix_print(matrix4);

            printf("Enter the size of unit square matrix: \n");
            size_t size;
            scanf("%zu", &size);
            Matrix* matrix5 = matrix_create_unit_square(size);
            printf("Unit matrix:\n");
            matrix_print(matrix5);

            matrix_free(matrix);
            matrix_free(matrix2);
            matrix_free(matrix3);
            matrix_free(matrix4);
            matrix_free(matrix5);
            break;


        case 2:
            printf("Enter first matrix size for operations (first is height, second is width):\n");
            size_t h4, w4;
            scanf("%zu %zu", &h4, &w4);

            Matrix* matrix6 = matrix_alloc(h4, w4);

            if (matrix6 == NULL) {
                return 1;  // Exiting the program with a failure status.
            }

            if (matrix6 != NULL) {
                printf("Matrix created successfully.\n");
            }

            printf("Enter the elements of the matrix:\n");
            for (size_t i = 0; i < h4; i++) {
                for (size_t j = 0; j < w4; j++) {
                    double element;
                    scanf("%lf", &element);
                    matrix_set(matrix6, i, j, element);
                }
            }

            printf("Enter second matrix size for operations (first is height, second is width):\n");
            size_t h5, w5;
            scanf("%zu %zu", &h5, &w5);

            Matrix* matrix7 = matrix_alloc(h5, w5);

            if (matrix7 == NULL) {
                return 1;  // Exiting the program with a failure status.
            }

            if (matrix7 != NULL) {
                printf("Matrix created successfully.\n");
            }

            printf("Enter the elements of the matrix:\n");
            for (size_t i = 0; i < h5; i++) {
                for (size_t j = 0; j < w5; j++) {
                    double element;
                    scanf("%lf", &element);
                    matrix_set(matrix7, i, j, element);
                }
            }

            Matrix* result1 = matrix_sum(matrix6, matrix7);
            printf("Sum of matrix:\n");
            matrix_print(matrix6);
            printf("+ \n");
            matrix_print(matrix7);
            printf("= \n");
            matrix_print(result1);


            Matrix* matrix65 = matrix_clone(matrix6);

            printf("Input scalar (Clone of first matrix of pair will be multiplied: \n");
            double scalar;
            scanf("%lf", &scalar);

            matrix_multiply_scalar(matrix65, scalar);
            printf("Matrix multiplied with scalar:\n");
            matrix_print(matrix65);

            Matrix* result2 = matrix_multiply(matrix6, matrix7);
            printf("Matrix multiplied with matrix:\n");
            matrix_print(result2);

            Matrix* matrix66 = matrix_clone(matrix6);

            printf("Matrix transposed with two methods:\n");
            Matrix* result3 = matrix_transpose(matrix66);
            matrix_transpose_simple(matrix66);
            matrix_print(result3);
            printf("\n");
            matrix_print(matrix66);

            matrix_free(matrix6);
            matrix_free(matrix65);
            matrix_free(matrix66);
            matrix_free(matrix7);
            matrix_free(result1);
            matrix_free(result2);
            matrix_free(result3);
            break;

        case 3:
            printf("Enter size of matrix for operations with it's rows (first is height, second is width):\n");
            size_t h6, w6;
            scanf("%zu %zu", &h6, &w6);

            Matrix* matrix8 = matrix_alloc(h6, w6);

            if (matrix8 == NULL) {
                return 1;  // Exiting the program with a failure status.
            }

            if (matrix8 != NULL) {
                printf("Matrix created successfully.\n");
            }

            printf("Enter the elements of the matrix:\n");
            for (size_t i = 0; i < h6; i++) {
                for (size_t j = 0; j < w6; j++) {
                    double element;
                    scanf("%lf", &element);
                    matrix_set(matrix8, i, j, element);
                }
            }

            Matrix* matrix85 = matrix_clone(matrix8);
            Matrix* matrix86 = matrix_clone(matrix8);
            Matrix* matrix87 = matrix_clone(matrix8);
            Matrix* matrix88 = matrix_clone(matrix8);

            matrix_print(matrix85);
            printf("Input scalar and row (row of clone matrix will be multiplied: \n");
            double scalar_row;
            size_t st0;
            scanf("%lf", &scalar_row);
            scanf("%zu", &st0);
            multiply_row(matrix85, scalar_row, st0);
            matrix_print(matrix85);

            printf("Choose number of strings to me summed: \n");
            size_t st1, st2;
            scanf("%zu", &st1);
            scanf("%zu", &st2);
            add_strings(matrix86, st1, st2);
            matrix_print(matrix86);


            printf("Choose number of strings to me permuted: \n");
            size_t st3, st4;
            scanf("%zu", &st3);
            scanf("%zu", &st4);
            permute_string(matrix87, st3, st4);
            matrix_print(matrix87);

            printf("Max row norm: \n");
            printf("%zu \n", max_row_norm(matrix88));

            printf("Max col norm: \n");
            printf("%zu \n", max_col_norm(matrix88));

            printf("Choose number of strings for submatrix to be excluded: \n");
            size_t st5, st6;
            scanf("%zu", &st5);
            scanf("%zu", &st6);

            Matrix* submatrix = allocate_submatrix(matrix8, st5, st6);
            matrix_print(submatrix);

            printf("Determinant of matrix: \n");
            double det = matrix_determinant(matrix8);
            printf("%lf \n", det);

            matrix_free(matrix8);
            matrix_free(matrix85);
            matrix_free(matrix86);
            matrix_free(matrix87);
            matrix_free(matrix88);
            break;

        case 4:

            printf("Input 3x3 A matrix:\n");

            Matrix* matrixA = matrix_alloc(3, 3);

            if (matrixA == NULL) {
                return 1;
            }

            if (matrixA != NULL) {
                printf("Matrix created successfully.\n");
            }

            printf("Enter the elements of the matrix:\n");
            for (size_t i = 0; i < 3; i++) {
                for (size_t j = 0; j < 3; j++) {
                    double element;
                    scanf("%lf", &element);
                    matrix_set(matrixA, i, j, element);
                }
            }

            printf("Enter 3x1  B matrix:\n");

            Matrix* matrixB = matrix_alloc(3, 1);

            if (matrixB == NULL) {
                return 1;
            }

            if (matrixB != NULL) {
                printf("Matrix created successfully.\n");
            }

            printf("Enter the elements of the matrix:\n");
            for (size_t i = 0; i < 3; i++) {
                for (size_t j = 0; j < 1; j++) {
                    double element;
                    scanf("%lf", &element);
                    matrix_set(matrixB, i, j, element);
                }
            }

            Matrix* matrixx = matrix_alloc(3, 1);;
            Matrix* gauss_matrix = solve_system(matrixA, matrixB, matrixx);
            if (gauss_matrix != NULL) {
                printf("Solution matrix (x):\n");
                matrix_print(gauss_matrix);
                matrix_free(gauss_matrix);
            }
            else {
                printf("System is singular (no unique solution).\n");
            }

            matrix_free(matrixA);
            matrix_free(matrixB);
            matrix_free(matrixx);
            break;

        case 5:
            printf("Enter matrix size for exp operation:\n");
            size_t h10, w10;
            scanf("%zu %zu", &h10, &w10);

            Matrix* matrix10 = matrix_alloc(h10, w10);

            if (matrix10 == NULL) {
                return 1;
            }

            if (matrix10 != NULL) {
                printf("Matrix created successfully.\n");
            }

            printf("Enter the elements of the matrix:\n");
            for (size_t i = 0; i < h10; i++) {
                for (size_t j = 0; j < w10; j++) {
                    double element;
                    scanf("%lf", &element);
                    matrix_set(matrix10, i, j, element);
                }
            }

            Matrix* matrix11 = matrix_exponential(matrix10, 0.0000001);
            matrix_print(matrix11);

            matrix_free(matrix10);
            matrix_free(matrix11);
            break;



        default:
            printf("Input error \n");
            return 0;
    }


}












    return 0;
}


