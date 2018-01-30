/*
core_layers header file for Scorpion Framework, written for Texas Instruments
Launchpad devices and Arduino. This framework aims to implement machine
learning on small embedded devices.

This header file contains some of the core functionality required for running
neural layers.

See license for legal queries.
2017-2018 , Yash Bonde
*/

#ifndef SCORPION_CORE_LAYERS_H_
#define SCORPION_CORE_LAYERS_H_

#include <cmath>
#include "../scorpion_core/scorpion_core.h"  // defines the Matrix
#include "../scorpion_core/scorpion_core_ops.h"  // defines the core operations
#include "core_layers.h"  // header file

class CoreLayers{
 public:
    // Activations
    Matrix sigmoid(Matrix);  // sigmoid
    Matrix tanh(Matrix);  // tanh
    Matrix relu(Matrix);  // relu
    Matrix softmax(Matrix, char);  // softmax

    // Ops
    Matrix flatten(Matrix);
    float reduce_mean(Matrix);

 private:
};

//========= Public =========//

// Activations
Matrix CoreLayers::sigmoid(Matrix input_matrix) {
    /*
    Perform for each value in Matrix x, sigmoid activation (1/(1 + e^-x))
    */
    Matrix temp(input_matrix.no_of_rows, input_matrix.no_of_cols);
    for (int i = 0; i < temp.no_of_rows; ++i) {
        for (int j = 0; j < temp.no_of_cols; ++j) {
            temp[i][j] = 1.0/(1.0+exp(-input_matrix[i][j]));
        }
    }
    return temp;
}

Matrix CoreLayers::tanh(Matrix input_matrix) {
    /*
    Perform for each value in Matrix x, tanh activation ((e^(2x) - 1)/(e^(2x) + 1))
    */
    Matrix temp(input_matrix.no_of_rows, input_matrix.no_of_cols);
    for (int i = 0; i < temp.no_of_rows; ++i) {
        for (int j = 0; j < temp.no_of_cols; ++j) {
            temp[i][j] = (exp(2.0*input_matrix[i][j])-1.0)/(exp(2.0*input_matrix[i][j])+1.0);
        }
    }
    return temp;
}

Matrix CoreLayers::relu(Matrix input_matrix) {
    /*
    Perform for each value in Matrix x, relu activation (x if x > 0; else 0)
    */
    Matrix temp(input_matrix.no_of_rows, input_matrix.no_of_cols);
    for (int i = 0; i < temp.no_of_rows; ++i) {
        for (int j = 0; j < temp.no_of_cols; ++j) {
            temp[i][j] = (input_matrix[i][j]>0?input_matrix[i][j]:0);
        }
    }
    return temp;
}

Matrix CoreLayers::softmax(Matrix input_matrix, char axis) {
    /*
    Perform for each value in Matrix of shape [1, len] x,
        softmax activation (e^(x)/ sum(e^(x[i])))
    */
    Matrix temp(input_matrix.no_of_rows, input_matrix.no_of_cols);
    if (axis == 'h') {
        //  row wise
        for (int i = 0; i < input_matrix.col_size; ++i) {
            float sum = 0;
            for (int j = 0; j < input_matrix.row_size; ++j) {
                sum += exp(input_matrix[i][j]);
            }
            for (int j = 0; j < input_matrix.row_size; ++j) {
                temp[i][j] = exp(input_matrix[i][j])/sum;
            }
        }
    } else if (axis == 'v') {
        //  column wise
        for (int i = 0; i < input_matrix.row_size; ++i) {
            float sum = 0;
            for (int j = 0; j < input_matrix.col_size; ++j) {
                sum += exp(input_matrix[i][j]);
            }
            for (int j = 0; j < input_matrix.col_size; ++j) {
                temp[i][j] = exp(input_matrix[i][j])/sum;
            }
        }
    } else {
        //  throw an error
        // std::cerr << "Error in softmax" << "\n";
    }
    return temp;
}

// Ops
Matrix CoreLayers::flatten(Matrix input_matrix) {
    /*
    Call core ops reshape function and convert to [1, no_rows*no_cols]
    */
    Matrix reshaped_matrix = CoreOps::reshape(input_matrix, [1, input_matrix.no_of_rows * input_matrix.no_of_cols]);
    return reshaped_matrix;
}

float reduce_mean(Matrix input_matrix, int axis) {
    /*
    let any Matrix A be
    [[1 2 3]
     [1 4 7]
     [1 4 9]]

    reduce_mean(A, axis = 0) --> return mean of all the values in Matrix (default)
    reduce_mean(A, axis = 1) --> return mean of values in each row of Matrix
    */
}

#endif
