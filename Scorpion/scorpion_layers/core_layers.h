/*
core_layers header file for Scorpion Framework, written for Texas Instruments
Launchpad devices and Arduino. This framework aims to implement machine
learning on small embedded devices.

This header file contains some of the core functionality required for running
neural layers.

See license for legal queries.
2017-2018 , Yash Bonde
*/

#ifndef SCORPION_CORE_LAYERS_H_
#define SCORPION_CORE_LAYERS_H_

#include "../scorpion_core/scorpion_core.h" // defines the Matrix
#include "../scorpion_core/scorpion_core_ops.h" // defines the core operations
#include "core_layers.h" // header file

class CoreLayers{
public:
	// Activation class starts
	class Activations(){
		static <?type> sigmoid(<?type> input_vector);
		static <?type> tanh(<?type> input_vector);
		static <?type> softmax(<?type> input_vector);
	};
	// Activation class ends

	// Ops class starts
	class Ops{
		static <?type> flatten(<?type> input_matrix);
		static <?type> argmax(<?type> input_vector);
	};
	// Ops class ends

	
private:
};

#endif