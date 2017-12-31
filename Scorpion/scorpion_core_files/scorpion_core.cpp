/*
scorpion_core source file for Scorpion Framework for scorpion_core header file,
written for Texas Instruments Launchpad devices and Arduino. This framework aims
to implement machine learning on small embedded devices.

This source file defines the Matrix which is used as basis for the entire
scorpion framework.

See license for legal queries.
2017, Yash Bonde
*/

#include<iostream>
#include<vector>
#include "scorpion_core.h" // for accessing the matrix making ops

Matrix::Matrix(std::vector<std::vector<float> > ex_matrix){
	x_ = ex_matrix.size(); y_ = ex_matrix[0].size();
	shape_vec.push_back(x_); shape_vec.push_back(y_);
	// copying the elements of ex_matrix into the core_matrix
	core_matrix = ex_matrix;
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
	std::vector<float> col_;
	for(int i=0; i<shape_vec[0]; i++){
		col_.push_back(core_matrix[i][col_num]);
	}
	return col_;
}

// Functions telling the attribute of the Matrix
std::vector<int> Matrix::shape(){
	return shape_vec;
}

std::vector<std::vector<float> > Matrix::get_val(){
	return core_matrix;
}