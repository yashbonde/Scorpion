#ifndef SCORPION_H_
#define SCORPION_H_

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "./scorpion_core_files/scorpion_core.h"
#include "./scorpion_core_files/scorpion_core_ops.h"
#include "./scorpion_layers/core_layers.h"
#include "./scorpion_layers/scorpion_layers.h"
// #include "./scorpion_ops.h"
#include "./external/json.hpp"

using json = nlohmann::json;
using string = std::string;

// #include "scorpion.h"

/*
This is just a road map file for scorpion.h, the function that will actually be called
during the execution of the model.
*/

class ScorpionModel{
 public:
    json model_name;
    json layers;
    std::vector<Matrix> weight;
    std::vector<Matrix> bias;
    std::vector<string> type;
    std::vector<int> activation;

    // to make it usable
    void load_architecture(string arch) {
        std::ifstream i(arch);
        json j;
        i >> j;
        model_name = j["model_name"];
        layers = j["layers"];
        for (int i = 0; i < layers.size(); i++) {
            weight.push_back(Matrix(layers[i]["output_dim"].get<int>(), layers[i]["input_dim"].get<int>()));
            bias.push_back(Matrix(layers[i]["output_dim"].get<int>(), 1));
            type.push_back(layers[i]["type"].get<string>());
            // activations
            string act = layers[i]["activation"].get<string>();
            if(act == "sigmoid") activation.push_back(1);
            else if(act == "tanh") activation.push_back(2);
            else if(act == "relu") activation.push_back(3);
            else if(act == "softmax") activation.push_back(4);
            else activation.push_back(5);
        }
    }

    void load_parameters(string params) {
        std::ifstream i(params);
        json j;
        i >> j;
    }

    int predict(Matrix inp) {
        /*
        Do the ops call scorpion_core_layers.h for this
        */
        ScorpionLayer sl;
        for (int i = 0; i < layers.size(); i++) {
            if(type[i] == "dense") inp = sl.dense(inp, weight[i], bias[i], activation[i]);
        }
        return 0;
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