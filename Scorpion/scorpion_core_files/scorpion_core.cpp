/*
scorpion_core source file for Scorpion Framework for scorpion_core header file,
written for Texas Instruments Launchpad devices and Arduino. This framework aims
to implement machine learning on small embedded devices.

This source file defines the Matrix which is used as basis for the entire
scorpion framework.

See license for legal queries.
2017, Yash Bonde
*/

#include "Energia.h" // Energia class to interact with the board
#include "scorpion_core.h" // for accessing the matrix making ops

Matrix::Matrix(int x, int y){
	/*
	Args:
		x (type int): the x-dimension of the matrix
		y (type int): the y-dimension of the matrix
	Returns:
		A Matrix constructor for further operations
	*/
	x_ = x; y_ = y;
}

Matrix::shape(){
	// code
}

Matrix::add_val(){
	// code
}