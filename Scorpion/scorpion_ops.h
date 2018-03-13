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

class ScorpionOps
{
public:
	ScorpionOps();
	~ScorpionOps();
	
	// functionalities to run the scorpion
	class RNNWrapper
	 {
	 public:
	 	RNNWrapper(){
	 		// constructor things go here
	 		// variables_array so we don't redundantly keep calling them
	 		// other variables,
	 	};
	 	~RNNWrapper();
	 	
	 	Matrix execute(); // code to execute the input to the RNNWrapper cell

	 private:
	 	// all the information about the RNN wrapper is stored here

	 };


private:
	// all the information about a single layer is kept here
};

ScorpionOps::RNNWrapper::execute(Matrix input, Matrix prev_state){
	//
	// I assume input matrix is of dimensions(UNITS, X) and prev_state is of (1, X)
	int x = input.no_of_cols;
	Matrix output;
	vector<Matrix> temp;
	for (int i = 0; i < UNITS; i++) {
		temp = lstm_cell(input.get_row(i), , prev_state, ...);
		prev_state = temp[0];
		output = temp[1];
	}
	return output;
}
