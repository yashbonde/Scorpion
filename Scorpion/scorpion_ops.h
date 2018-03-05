/*
scorpion_ops header file for Scorpion Framework, written for Texas Instruments
Launchpad devices and Arduino. This framework aims to implement machine
learning on small embedded devices.

This header file contains some of the core functionality required for running
scorpion module

See license for legal queries.
2017-2018 , Yash Bonde
*/

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
	 		// variables_array so we don't redundantly keep callign them
	 		// other variables,
	 	};
	 	~RNNWrapper();
	 	
	 	Matrix exectute(); // code to execute the input to the RNNWrapper cell

	 private:
	 	// all the information about the RNN wrapper is stored here

	 };


private:
	// all the information about a single layer is kept here
};

ScorpionOps::RNNWrapper::execute(Matrix){
	// 
}
