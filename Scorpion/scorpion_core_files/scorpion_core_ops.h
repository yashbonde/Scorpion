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

#include <string>
#include <vector>
#include "scorpion_core.h"  // defining the matrix

class CoreOps{
 public:
    // methods
    Matrix mat_add(Matrix, Matrix);
    Matrix mat_sub(Matrix, Matrix);
    Matrix mat_mul(Matrix, Matrix);
    Matrix element_wise_matmul(Matrix, Matrix);
    float determinant(Matrix);  // |A|
    Matrix adjoint(Matrix);  // find matrix adjoint
    Matrix transpose(Matrix);  // find matrix transpose
    Matrix inverse(Matrix);  // find inverse of a given matrix
    Matrix reshape(Matrix, int new_shape_arr[]); // reshape the given matrix to new shape given by array
    // the reshape should have a subroutine to check is the shape change is possible
    std::vector<double> argmax(Matrix, int);
 private:
    void shape_check(Matrix, Matrix, bool, std::string); // add in
    // each method so it improves the redundency
    bool verify_new_shape(int old_shape[], int new_shape[]);
    // This is the subroutive that will check if shape change is possible, if True
    // allow the shape change, else throw a stack error explaining the error
};

//========= Public =========//
Matrix CoreOps :: mat_add(Matrix A, Matrix B) {
    /*
    Add the elements of Matrix A and B and make a new Matrix
    */
    Matrix temp(A.no_of_rows, A.no_of_cols);
    for (int i = 0; i < A.no_of_rows; ++i) {
        for (int j = 0; j < A.no_of_cols; ++j) {
            temp.base[i][j] = A.base[i][j] + B.base[i][j];
        }
    }
    return temp;
}

Matrix CoreOps :: mat_sub(Matrix A, Matrix B) {
    /*
    Subtract the elements of Matrix B from A and make a new Matrix
    */
    Matrix temp(A.no_of_rows, A.no_of_cols);
    for (int i = 0; i < A.no_of_rows; ++i) {
        for (int j = 0; j < A.no_of_cols; ++j) {
            temp.base[i][j] = A.base[i][j] - B.base[i][j];
        }
    }
    return temp;
}

Matrix CoreOps :: mat_mul(Matrix A, Matrix B) {
    /*
    Return a Matrix multiplication of two matrices A and B
    */
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
    /*
    Return a Matrix element wise multiplication of two matrices A and B
    */
    Matrix temp(A.no_of_rows, A.no_of_cols);
    for (int i = 0; i < A.no_of_rows; ++i) {
        for (int j = 0; j < A.no_of_cols; ++j) {
            temp.base[i][j] = A.base[i][j] * B.base[i][j];
        }
    }
    return temp;
}

float CoreOps :: determinant(Matrix A) {
    /*
    Return the determinant of matrix A
    */
    return 0.5;  // to be built
}

Matrix CoreOps :: adjoint(Matrix A) {
    /*
    Return the adjoint of Matrix A
    */
    return A;  // to be built
}

Matrix CoreOps :: inverse(Matrix A) {
    /*
    Return the inverse of Matrix A
    */
    return A;  // to be built
}

Matrix CoreOps::reshape(Matrix A, int new_shape_arr[]) {
    /*
    Reshape the input Matrix to new shape and also have a subroutine to check if
    such a shape change is possible
    */
}

std::vector<double> CoreOps::argmax(Matrix A, int axis = 0) {
    /*
    let any Matrix A be
    [[1 2 3]
     [1 4 7]
     [1 4 9]]

    argmax(A, axis = 0) --> return index in linear terms of the largest element. So this will return
        8 (default)

    argmax(A, axis = 1) --> return index array in each vector. So this will return
        [2,2,2]
    */
    std::vector <double> v;
    return v;
}


Matrix CoreOps::transpose(Matrix A) {
    Matrix B(A.no_of_rows, A.no_of_cols);
    for (int i = 0; i < A.no_of_cols; ++i) {
        for (int j = 0; j < A.no_of_rows; ++j) {
            B.base[j][i] = A.base[i][j];
        }
    }
    return B;
}
//========= Private =========//

bool verify_new_shape(int old_shape[], int new_shape[]) {
    /*
    If shape change is possible, return True, else return False
    */
    if (old_shape[0]*old_shape[1] == new_shape[0]*new_shape[1]){
        return true;
    }
    else{
        // throw error explaining the problem
        return false;
    }
}
#endif  // SCORPION_SCORPION_CORE_FILES_SCORPION_CORE_OPS_H_