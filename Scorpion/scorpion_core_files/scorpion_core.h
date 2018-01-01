/*
scorpion_core header file for Scorpion Framework, written for Texas Instruments
Launchpad devices and Arduino. This framework aims to implement machine
learning on small embedded devices.

This header file contain the definition of Matrix class which will be used
in the scorpion framework.

See license for legal queries.
2017-2018, Yash Bonde
*/

#ifndef SCORPION_CORE_H
#define SCORPION_CORE_H

// this is the only header we need as this is the core and only defines
// the matrix class, all the other files we use will include this header
#include "scorpion_core.h"
#include<iostream>
#include<vector>

// Matrix in Scorpion is a class
class Matrix{
public:
	Matrix(std::vector<std::vector<float> > external_matrix);
	void Matrix_Initializer(int x, int y, float fill);
	std::vector<float> get_row(int row_num);
	std::vector<float> get_col(int col_num);
	// attribute functions
	std::vector<int> shape();
	std::vector<std::vector<float> > get_mat();
	float get_val(int x, int y);
private:
	std::vector<int> shape_vec;
	std::vector<std::vector<float> > core_matrix;
};

#endif