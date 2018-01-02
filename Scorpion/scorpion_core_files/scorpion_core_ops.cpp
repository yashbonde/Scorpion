/*
scorpion_core_ops source file for Scorpion Framework for scorpion_core_ops header file,
written for Texas Instruments Launchpad devices and Arduino. This framework aims
to implement machine learning on small embedded devices.

This source file contain the core operations to be used on Matrix for linear
algebra operations.

See license for legal queries.
2017-2018, Yash Bonde
*/

#include<iostream>
#include "scorpion_core.h" // Scorpion core to use for making Matrices
#include "scorpion_core_ops.h" // Scorpion core ops

//========= Public =========//  

// addition core operation
static Matrix CoreOps::mat_add(Matrix A, Matrix B){
	// check for exception
	shape_check(Matrix A, Matrix b, false, "Addition")
	// Initializing an empty matrix 
	std::vector<std::vector<float, B.shape()[1]> > C(A.shape()[0]);
	for(int i=0; i<A.shape()[0]; i++){
		//std::vector<float> temp(B.shape()[1]);
		for(int j=0; j<A.shape()[1]; j++){
			// addition of elements
			C[i][j] = A.get_val(i,j) + B.get_val(i,j);
		}
		C.push_back(temp);
	}
	return Matrix(C);
}

// subtraction core operation
static Matrix CoreOps::mat_sub(Matrix A, Matrix B){
	// check for exception
	shape_check(Matrix A, Matrix b, false, "Subtraction")
	// Initializing an empty matrix 
	std::vector<std::vector<float> > C;
	for(int i=0; i<A.shape()[0]; i++){
		std::vector<float> temp(B.shape()[1]);
		for(int j=0; j<A.shape()[1]; j++){
			// subtraction of elements
			temp[j] = A.get_val(i,j) - B.get_val(i,j);
		}
		C.push_back(temp);
	}
	return Matrix(C);
}

// element wise multiplication core operation
static Matrix CoreOps::element_wise_matmul(Matrix A, Matrix B){
	// check for exception
	shape_check(Matrix A, Matrix b, false, "Element Wise Multiplication")
	// Initializing an empty matrix 
	std::vector<std::vector<float> > C;
	for(int i=0; i<A.shape()[0]; i++){
		std::vector<float> temp(B.shape()[1]);
		for(int j=0; j<A.shape()[1]; j++){
			// multiplication of elements
			temp[j] = A.get_val(i,j) * B.get_val(i,j);
		}
		C.push_back(temp);
	}
	return Matrix(C);
}

// function to perform matrix multiplication
static Matrix CoreOps::mat_mul(Matrix A, Matrix B){
	// check for shape
	shape_check(Matrix A, Matrix b, true, "MatMul")
	// rest of the code
}

// function to divide all the elements of a matrix by a fixed flaot value
static Matrix CoreOps::divide(Matrix A, float x){
	// code
}

// function to calculate the determinant of the matrix
float CoreOps::det(Matrix A){
	// code
}

// function to find the adjoint of a given matrix
static Matrix CoreOps::adjoint(Matrix A){
	// code
}

// function to find the inverse of a given matrix
static Matrix CoreOps::inverse(Matrix A){
	// code
}

//========= Private =========//

// function to check the shapes of the matrices
void CoreOps::shape_check(Matrix A, Matrix B, bool mul, std::string op){
	// if mul = True, check only for ay and bx, for matrix multiplication we need to
	// verify only these two values
	int ax = A.shape()[0], ay = A.shape()[1], bx = B.shape()[0], by = B.shape()[1];
	bool correct = true; // variable to tell if check true or not
	if (mul == false && (ax != bx || ay != by)) correct = false;
	if (mul == true && (ay != bx)) correct = false;
	if not correct{
		throw std::string("[!] For %s the shapes must be same but got, (%d, %d) and (%d, %d)", op, ax, ay, bx, by);
	}
}
