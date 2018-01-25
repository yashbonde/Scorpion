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

#include "../scorpion_core/scorpion_core.h" // defines the Matrix
#include "../scorpion_core/scorpion_core_ops.h" // defines the core operations
#include "core_layers.h" // header file

class CoreLayers{
public:
	// Activations
	Matrix sigmoid(Matrix); // sigmoid
	Matrix tanh(Matrix); // tanh
	Matrix relu(Matrix); // relu
	Matrix softmax(Matrix); // softmax

	// Ops
	Matrix flatten(Matrix);
	float reduce_mean(Matrix);

private:a
};

//========= Public =========//

// Activations
Matrix CoreLayers::igmoid(Matrix input_matrix) {
	/*
	Perform for each value in Matrix x, sigmoid activation (1/(1 + e^-x))
	*/
}

Matrix CoreLayers::tanh(Matrix input_matrix) {
	/*
	Perform for each value in Matrix x, tanh activation ((e^(2x) - 1)/(e^(2x) + 1))
	*/
}

Matrix CoreLayers::relu(Matrix input_matrix) {
	/*
	Perform for each value in Matrix x, relu activation (x if x > 0; else 0)
	*/
}

Matrix CoreLayers::softmax(Matrix input_matrix) {
	/*
	Perform for each value in Matrix of shape [1, len] x,
		softmax activation (e^(x)/ sum(e^(x[i])))
	*/
}

// Ops
Matrix CoreLayers::flatten(Matrix input_matrix) {
	/*
	Call core ops reshape function and convert to [1, no_rows*no_cols]
	*/
	Matrix reshaped_matrix = CoreOps::reshape(input_matrix, [1, input_matrix.no_of_rows * input_matrix.no_of_cols]);
	return reshaped_matrix;
}

float reduce_mean(Matrix input_matrix, int axis){
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