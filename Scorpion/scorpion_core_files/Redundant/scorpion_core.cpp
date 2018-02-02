/* NOW REDUNDANT */

/*
scorpion_core source file for Scorpion Framework for scorpion_core header file,
written for Texas Instruments Launchpad devices and Arduino. This framework aims
to implement machine learning on small embedded devices.

This source file defines the Matrix which is used as basis for the entire
scorpion framework.

See license for legal queries.
2017-2018, Yash Bonde
*/

/*
#include<iostream>
#include<vector>
#include "scorpion_core.h" // for accessing the matrix making ops

//========= Public =========//  

Matrix::Matrix(std::vector<std::vector<float> > ex_matrix){
	shape_vec.push_back(ex_matrix.size()); // number of rows in the matrix
	shape_vec.push_back(ex_matrix[0].size()); // number of columns in the matrix
	// copying the elements of ex_matrix into the core_matrix
	core_matrix = ex_matrix;
}

void Matrix::matrix_initializer(int x, int y, float fill){
	shape_vec.push_back(x); // number of rows
	shape_vec.push_back(y); // number of columns
	for(int i=0; i<x; i++){
		std::vector<float> temp(y);
		for(int j=0; j<y; j++){
			temp[j] = fill;
		}
		core_matrix.push_back(temp);
	}
}

std::vector<float> Matrix::get_row(int row_num){
	if(row_num >= shape_vec[0] || row_num < 0){
		throw std::string("[!]Trying to get row number %d, while maximum is %d", row_num, shape_vec[0]);
	}
	std::vector<float> row_;
	row_ = core_matrix[row_num];
	return row_;
}

std::vector<float> Matrix::get_col(int col_num){
	if(col_num >= shape_vec[1] || col_num < 0){
		throw std::string("[!]Trying to get column number %d, while maximum is %d", col_num, shape_vec[1]);
	}
	// following lines are the way they are supposed to be and optimised
	float *col_ = new float[shape_vec[0]];
	for(int i=0; i<shape_vec[0]; i++){
		col_[i] = core_matrix[i][col_num];
	}
	std::vector<float> v(col_, col_+shape_vec[0]);
	delete [] col_;
	return v;
}

float Matrix::get_val(int x, int y){
	// get the value at any position
	return core_matrix.at(x).at(y);
}

//========= Private =========//

// Functions telling the attribute of the Matrix
std::vector<int> Matrix::shape(){
	// shape vector of the Matrix
	return shape_vec;
}

std::vector<std::vector<float> > Matrix::get_mat(){
	// return the total matrix
	return core_matrix;
}
*/
