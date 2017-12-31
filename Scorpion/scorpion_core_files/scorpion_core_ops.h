/*
scorpion_core_ops header file for Scorpion Framework, written for Texas Instruments
Launchpad devices and Arduino. This framework aims to implement machine
learning on small embedded devices.

This header file contains the core operations for linear algebra. We need to call
this file to work on matrix operations.

See license for legal queries.
2017, Yash Bonde
*/

#ifndef SCORPION_CORE_OPS_H
#define SCORPION_CORE_OPS_H

#include "scorpion_core_ops.h" // the name of this header file

class core_ops{
public:
	Matrix mat_add(Matrix A, Matrix B); // A+B
	Matrix mat_sub(Matrix A, Matrix B); // A-B
	Matrix mat_mul(Matrix A, Matrix B); // A*B -> Matrix multiplication
	Matrix element_wise_matmul(Matrix A, Matrix B); // A.*B -> Element wise
	float det(Matrix A); // |A|
	Matrix adjoint(Matrix A); // 
	Matrix inverse(Matrix A);
};

#endif