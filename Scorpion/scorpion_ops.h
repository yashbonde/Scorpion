/*
scorpion_ops header file for Scorpion Framework, written for Texas Instruments
Launchpad devices and Arduino. This framework aims to implement machine
learning on small embedded devices.

This header file contains some of the core functionality required for running
scorpion module

See license for legal queries.
2017-2018 , Yash Bonde
*/
#define UNITS 40

#include <vector>

class ScorpionOps
{
public:
	int hid_dim, input_dim;
	ScorpionOps(int inp, int hid) {
		hid_dim = hid;
		input_dim = inp;
	};
	~ScorpionOps();
	
	// functionalities to run the scorpion
	class RNNWrapper
	 {
	 public:
		Matrix W_f(hid_dim, input_dim), U_f(hid_dim, hid_dim), b_f(1, hid_dim),
	         W_i(hid_dim, input_dim), U_i(hid_dim, hid_dim), b_i(1, hid_dim),
	         W_c(hid_dim, input_dim), U_c(hid_dim, hid_dim), b_c(1, hid_dim),
	         W_o(hid_dim, input_dim), U_o(hid_dim, hid_dim), b_o(1, hid_dim);
	 	RNNWrapper(){
	 		// constructor things go here
	 		// variables_array so we don't redundantly keep calling them
	 		// other variables,
	 		// set values of matrices here
	 	};
	 	~RNNWrapper();
	 	
	 	std::pair<std::vector<float>, std::vector<float> > execute(); // code to execute the input to the RNNWrapper cell

	 private:
	 	// all the information about the RNN wrapper is stored here

	 };


private:
	// all the information about a single layer is kept here
};

std::pair<std::vector<float>, std::vector<float> >ScorpionOps::RNNWrapper::execute(Matrix input, Matrix prev_state){
	//
	// I assume input matrix is of dimensions(UNITS, X) and prev_state is of (1, X)
	Matrix output;
	vector<Matrix> temp;
	for (int i = 0; i < UNITS; i++) {
		temp = lstm_cell(input.get_row(i), hidden, prev_state,
		                 W_f, U_f, b_f,
		                 W_i, U_i, b_i,
		                 W_c, U_c, b_c,
		                 W_o, U_o, b_o);
		prev_state = temp[0];
		output = temp[1];
	}
	return {output, prev_state};// returns output after every UNITS(40) iterations along with current state
}
