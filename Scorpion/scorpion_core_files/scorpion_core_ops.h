/*
scorpion_core_ops header file for Scorpion Framework, written for Texas Instruments
Launchpad devices and Arduino. This framework aims to implement machine
learning on small embedded devices.

This header file contains the core operations for linear algebra. We need to call
this file to work on matrix operations.

See license for legal queries.
2017-2018, Yash Bonde
*/

#ifndef SCORPION_CORE_OPS_H_
#define SCORPION_CORE_OPS_H_

#include "scorpion_core.h" // defining the matrix
#include "scorpion_core_ops.h" // the name of this header file

class CoreOps{
public:
	static Matrix mat_add(Matrix A, Matrix B); // A+B
	static Matrix mat_sub(Matrix A, Matrix B); // A-B
	static Matrix mat_mul(Matrix A, Matrix B); // A*B -> Matrix multiplication
	static Matrix element_wise_matmul(Matrix A, Matrix B); // A.*B -> Element wise
	float det(Matrix A); // |A|
	static Matrix adjoint(Matrix A); // find matrix adjoint
	static Matrix inverse(Matrix A); // find inverse of a given matrix
private:
	void shape_check(Matrix A, Matrix B, bool mul, std::string op)
};

#endif