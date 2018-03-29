#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "./scorpion_core_files/scorpion_core.h"
#include "./scorpion_core_files/scorpion_core_ops.h"
#include "./scorpion_layers/core_layers.h"
#include "./external/json.hpp"

using json = nlohmann::json;
using string = std::string;

// #include "scorpion.h"

/*
This is just a road map file for scorpion.h, the function that will actually be called
during the execution of the model.
*/
#ifndef SCORPION_H
#define SCORPION_H

class ScorpionModel{
 public:
    json model_name;
    json layers;
    std::vector<Matrix> weight;

    // to make it usable
    void load_architecture(string arch) {
        std::ifstream i(arch);
        json j;
        i >> j;
        model_name = j["model_name"];
        layers = j["layers"];
    }

    void load_parameters(string params) {
        std::ifstream i(params);
        json j;
        i >> j;
    }

    int predict(float input_signal[]) {
        /*
        Do the ops call scorpion_core_layers.h for this
        */
    }

    void view_pred(int len) {
        /*
        view last 'len' predictions by the model
        */
    }

    void save_pred() {
        /*
        Code to save the predictions in an array and as required dump them in SD Card
        */
    }

//    void update_parameters(args) {
        /*
        Code to update the parameters if required
        */
//    }

 private:
    bool check_format_architecture(string path);  // check format if the file is correct
    bool check_format_params(string path);  // check format if the file is correct

//    void _understand_architecture(array_of_layers);  // store the architecture in some way
//    void _understand_params(array_of_parameters);  // store the parameters somewhere
//    void _extract_file(path_to_file, type_of_file);  // uncompress the file

    // prediction array
    int predictions[];
    // architecture_array is the array that has all the instructions in numbers
    int architecture_array[];
    // array_with_layer_names is the array that has the names of all the elements of array
    // string_array array_with_layer_names[];  // still don't know how to store the stuff
};
#endif