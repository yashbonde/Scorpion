#include "/scorpion_core/scorpion_core.h"
#include "/scorpion_core/scorpion_core_ops.h"
#include "/scorpion_layers/core_layers.h"

#include "scorpion.h"

/*
This is just a road map file for scorpion.h, the function that will actually be called
during the execution of the model.
*/

class ScorpionModel{
public:
	ScorpionModel();
	~ScorpionModel();

	// to make it usable
	void load_architecture(string path_to_architecture.scrarch){
		/*
		bool _arch_okay = check_format_architecture(string path_to_architecture.scarch)
		int instructions[] = understand_model(string path_to_architecture.scarch)
		load the model into the private array_with_layer_names[]
		*/
	}

	void load_parameters(string path_to_parameters.scrparam){
		/*
		bool param_okay = check_format_params(string path_to_parameters.scparam)
		load the private array_with_layer_names[] with weights and biases
		*/
	}

	int predict(float input_signal[]){
		/*
		Do the ops call scorpion_core_layers.h for this
		*/
	}

	void view_pred(int len) {
		/*
		view last 'len' predictions by the model
		*/
	}

	void save_pred(){
		/*
		Code to save the predictions in an array and as required dump them in SD Card
		*/
	}

	void update_parameters(args){
		/*
		Code to update the parameters if required
		*/
	}

private:
	bool check_format_architecture(string path_to_architecture.scarch); // check format if the file is correct
	bool check_format_params(string path_to_parameters.scparam); // check format if the file is correct

	void _understand_architecture(array_of_layers); // store the architecture in some way
	void _understand_params(array_of_parameters); // store the parameters somewhere
	void _extract_file(path_to_file, type_of_file); // uncompress the file

	// prediction array
	int predictions[];
	// architecture_array is the array that has all the instructions in numbers
	int architecture_array[];
	// array_with_layer_names is the array that has the names of all the elements of array
	string_array array_with_layer_names[]; // still don't know how to store the stuff
};