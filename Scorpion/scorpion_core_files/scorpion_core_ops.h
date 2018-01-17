/*
scorpion_core_ops header file for Scorpion Framework, written for Texas Instruments
Launchpad devices and Arduino. This framework aims to implement machine
learning on small embedded devices.

This header file contains the core operations for linear algebra. We need to call
this file to work on matrix operations.

See license for legal queries.
Copyright 2017-2018, Yash Bonde
*/

#ifndef SCORPION_SCORPION_CORE_FILES_SCORPION_CORE_OPS_H_
#define SCORPION_SCORPION_CORE_FILES_SCORPION_CORE_OPS_H_
#endif  // SCORPION_SCORPION_CORE_FILES_SCORPION_CORE_OPS_H_

#include <string>
#include "scorpion_core.h"  // defining the matrix

class CoreOps{
 public:
    Matrix mat_add(Matrix, Matrix);
    Matrix mat_sub(Matrix, Matrix);
    Matrix mat_mul(Matrix, Matrix);
    Matrix element_wise_matmul(Matrix, Matrix);
    float determinant(Matrix);  // |A|
    Matrix adjoint(Matrix);  // find matrix adjoint
    Matrix inverse(Matrix);  // find inverse of a given matrix
 private:
    void shape_check(Matrix, Matrix, bool, std::string);
};

Matrix CoreOps :: mat_add(Matrix A, Matrix B) {
    Matrix temp(A.no_of_rows, A.no_of_cols);
    for (int i = 0; i < A.no_of_rows; ++i) {
        for (int j = 0; j < A.no_of_cols; ++j) {
            temp.base[i][j] = A.base[i][j] + B.base[i][j];
        }
    }
    return temp;
}

Matrix CoreOps :: mat_sub(Matrix A, Matrix B) {
    Matrix temp(A.no_of_rows, A.no_of_cols);
    for (int i = 0; i < A.no_of_rows; ++i) {
        for (int j = 0; j < A.no_of_cols; ++j) {
            temp.base[i][j] = A.base[i][j] - B.base[i][j];
        }
    }
    return temp;
}

Matrix CoreOps :: mat_mul(Matrix A, Matrix B) {
    Matrix temp(A.no_of_rows, B.no_of_cols);
    temp = 0;
    for (int i = 0; i < A.no_of_rows; ++i) {
        for (int j = 0; j < B.no_of_cols; ++j) {
            for (int k = 0; k < A.no_of_cols; ++k) {
                temp.base[i][j] += A.base[i][k] * B.base[k][j];
            }
        }
    }
    return temp;
}

Matrix CoreOps :: element_wise_matmul(Matrix A, Matrix B) {
    Matrix temp(A.no_of_rows, A.no_of_cols);
    for (int i = 0; i < A.no_of_rows; ++i) {
        for (int j = 0; j < A.no_of_cols; ++j) {
            temp.base[i][j] = A.base[i][j] * B.base[i][j];
        }
    }
    return temp;
}

float CoreOps :: determinant(Matrix A) {
    return 0.5;  // to be built
}

Matrix CoreOps :: adjoint(Matrix A) {
    return A;  // to be built
}

Matrix CoreOps :: inverse(Matrix A) {
    return A;  // to be built
}
