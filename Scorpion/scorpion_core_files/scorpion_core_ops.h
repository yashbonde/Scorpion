/*
scorpion_core_ops header file for Scorpion Framework, written for Texas Instruments
Launchpad devices and Arduino. This framework aims to implement machine
learning on small embedded devices.

This header file contains the core operations for linear algebra. We need to call
this file to work on matrix operations.

See license for legal queries.
Copyright 2017-2018, Yash Bonde, Arpit Chaudhary
*/

#ifndef SCORPION_SCORPION_CORE_FILES_SCORPION_CORE_OPS_H_
#define SCORPION_SCORPION_CORE_FILES_SCORPION_CORE_OPS_H_

#include <string>
#include <vector>
#include <limits>
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
    Matrix concatenate(Matrix, Matrix, int); // concatenate any two matrices according to axis
    Matrix stack(Matrix, Matrix, int); // stack any two input matrices according to axis
    std::vector<float> argmax(Matrix, int);
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

Matrix CoreOps::transpose(Matrix A) {
    /*
    Returns the transpose of a matrix
    */
    Matrix B(A.no_of_rows, A.no_of_cols);
    for (int i = 0; i < A.no_of_cols; ++i) {
        for (int j = 0; j < A.no_of_rows; ++j) {
            B.base[j][i] = A.base[i][j];
        }
    }
    return B;
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

Matrix CoreOps::concatenate(Matrix A, Matrix B, int axis = 0){
    /*
    a = array([[1, 2], [3, 4]])
    b = array([[5, 6]])

    Case # 1 --> axis = 0
    concatenate((a, b), axis=0)
    op --> array([[1, 2],
          [3, 4],
          [5, 6]])

    Case # 2 --> axis = 1
    * b.T means transpose of b
    concatenate((a, b.T), axis=1)
    op --> array([[1, 2, 5],
           [3, 4, 6]])
    */
    Matrix error(1,1);
    if (axis == 0) {
        if(A.row_size == B.row_size) {
            int rowa = A.no_of_rows;
            int rowb = B.no_of_rows;
            int cols = A.no_of_cols;
            Matrix temp(rowa+rowb, cols);
            for (int j=0;j<cols;j++) {
                for (int i = 0; i<rowa; i++)
                    temp.base[i][j] = A.base[i][j];
                for (int i=rowa; i<rowa+rowb;i++)
                    temp.base[i][j] = B.base[i-rowa][j];
            }
            return temp;
        }
        else {
            std::cout<<"error in concatenate\n";
        }
    }
    else if (axis == 1) {
        if(A.col_size = B.col_size) {
            int rows = A.no_of_rows;
            int cola = A.no_of_cols;
            int colb = B.no_of_cols;
            Matrix temp(rows, cola+colb);
            for (int i=0;i<rows;i++) {
                for (int j = 0; j<cola; j++)
                    temp.base[i][j] = A.base[i][j];
                for (int j=cola; j<cola+colb;i++)
                    temp.base[i][j] = B.base[i][j-cola];
            }
            return temp;
        }
        else {
            std::cout<<"error in concatenate\n";
        }
    }
    return error;
}

Matrix CoreOps::stack(Matrix A, Matrix B, int axis){
    /*
    a = array([1, 2, 3])
    b = array([2, 3, 4])
    
    Case #1
    stack((a, b), axis = 0)
    op --> array([1, 2, 3, 2, 3, 4])

    Case #1
    stack((a, b), axis = 1)
    op --> array([[1, 2, 3],
           [2, 3, 4]])
    
    Case #2
    stack((a, b), axis=-1)
    op --> array([[1, 2],
           [2, 3],
           [3, 4]])
    */
}

std::vector<float> CoreOps::argmax(Matrix A, int axis = 0) {
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
    std::vector <float> v;
    if (axis == 0) {
        float max = std::numeric_limits<float>::min();
        int pos = -1;
        for (int j=0; j<A.row_size; j++) {
            for (int i=0;i<A.col_size; i++) {
                if(A.base[i][j] > max) {
                    max = A.base[i][j];
                    pos = (A.row_size * i) + j;
                }
            }
        }
        v.push_back(pos);
    }
    else if (axis = 1) {
        for (int i = 0; i<A.no_of_rows; i++) {
            float max = std::numeric_limits<float>::min();
            int pos = -1;
            for(int j=0; j< A.no_of_cols; j++) {
                if(A.base[i][j] > max) {
                    max = A.base[i][j];
                    pos = j;
                }
            }
            v.push_back(pos);
        }
    }
    return v;
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