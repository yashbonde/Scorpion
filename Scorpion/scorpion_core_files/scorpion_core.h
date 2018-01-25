/*
scorpion_core header file for Scorpion Framework, written for Texas Instruments
Launchpad devices and Arduino. This framework aims to implement machine
learning on small embedded devices.

This header file contain the definition of Matrix class which will be used
in the scorpion framework.

See license for legal queries.
Copyright 2017-2018, Yash Bonde
*/

#ifndef SCORPION_SCORPION_CORE_FILES_SCORPION_CORE_H_
#define SCORPION_SCORPION_CORE_FILES_SCORPION_CORE_H_
#endif  // SCORPION_SCORPION_CORE_FILES_SCORPION_CORE_H_

#include<iostream>
#include<vector>

// Matrix in Scorpion is a class
class Matrix{
 public:
    float **base;  // Matrix
    // can we remove these ?
    int no_of_rows; // will always be equal to col len
    int no_of_cols; // will always be equal to row len
    int row_size;
    int col_size;

    // constructor
    Matrix(int, int);
    // destructor
    ~Matrix();

    // methods
    std::vector<float> get_row(int);
    std::vector<float> get_column(int);
    void equate_2d_matrix(float *, int, int);

    // operator overloading
    void operator = (Matrix);
    void operator = (float);
    Matrix operator + (float);
    Matrix operator - (float);
    Matrix operator * (float);
};

//========= Constructor =========//
Matrix :: Matrix(int num_of_rows, int num_of_cols) {
	/*
	Initialize the Matrix class
	*/
    no_of_rows = num_of_rows;
    no_of_cols = num_of_cols;
    row_size = num_of_cols;
    col_size = num_of_rows;
    base = new float *[num_of_rows];
    for (int i = 0; i < num_of_rows; ++i) {
        base[i] = new float[num_of_cols];
    }
}

//========= Destructor =========//
Matrix :: ~Matrix() {
	/*
	Destroy the Matrix class
	*/
    delete base;
}

//========= Methods =========//
std::vector<float> Matrix :: get_row(int row_num) {
	/*
	Get values of a row in form of an vector
	*/
    std::vector<float> temp(row_size);
    for (int i = 0; i < row_size; ++i) {
        temp[i] = base[row_num][i];
    }
    return temp;
}

std::vector<float> Matrix :: get_column(int) {
	/*
	Get values of a column in form of an vector
	*/
    std::vector<float> temp(col_size);
    for (int i = 0; i < col_size; ++i) {
        temp[i] = base[i][col_size];
    }
    return temp;
}

void Matrix :: equate_2d_matrix(float *arr, int num_of_rows, int num_of_cols) {
    for (int i = 0; i < num_of_rows; ++i) {
        for (int j = 0; j < num_of_cols; ++j) {
            base[i][j] = *((arr + i * num_of_cols) + j);
        }
    }
}

//========= Operator Overloading =========//
void Matrix :: operator = (Matrix A) {
	/*
	Assign the same value as current Matrix to a new Matrix A
	*/
    for (int i = 0; i < no_of_rows; ++i) {
        for (int j = 0; j < no_of_cols; ++j) {
            base[i][j] = A.base[i][j];
        }
    }
}

void Matrix :: operator = (float value) {
	/*
	Assign same float 'value' to all the elements of Matrix
	*/
    for (int i = 0; i < no_of_rows; ++i) {
        for (int j = 0; j < no_of_cols; ++j) {
            base[i][j] = value;
        }
    }
}

Matrix Matrix :: operator + (float f) {
	/*
	Add float value f to all the elements of Matrix
	*/
    Matrix temp(no_of_rows, no_of_cols);
    for (int i = 0; i < no_of_rows; i++) {
        for (int j = 0; j < no_of_cols; j++) {
            temp.base[i][j] = base[i][j] + f;
        }
    }
    return temp;
}

Matrix Matrix :: operator - (float f) {
	/*
	Subtract float value f from all the elements of Matrix
	*/
    Matrix temp(no_of_rows, no_of_cols);
    for (int i = 0; i < no_of_rows; i++) {
        for (int j = 0; j < no_of_cols; j++) {
            temp.base[i][j] = base[i][j] - f;
        }
    }
    return temp;
}

Matrix Matrix :: operator * (float f) {
	/*
	Mulitply float value f to all the elements of Matrix
	*/
    Matrix temp(no_of_rows, no_of_cols);
    for (int i = 0; i < no_of_rows; i++) {
        for (int j = 0; j < no_of_cols; j++) {
            temp.base[i][j] = base[i][j] * f;
        }
    }
    return temp;
}
