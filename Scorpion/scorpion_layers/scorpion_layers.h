/*
scorpion_layers header file for Scorpion Framework, written for Texas Instruments
Launchpad devices and Arduino. This framework aims to implement machine
learning on small embedded devices.

This header file contains the layers for the scorpion framework. To run an RNN
an external wrapper class will be used.

See license for legal queries.
2018, Yash Bonde
*/
#ifndef SCORPION_SCORPION_LAYERS_H_
#define SCORPION_SCORPION_LAYERS_H_
#include "./core_layers.h"
#include "../scorpion_core_files/scorpion_core.h"
#include "../scorpion_core_files/scorpion_core_ops.h"

class ScorpionLayer{
 public:
    // layers
    Matrix dense(Matrix, Matrix, Matrix, int);
    std::vector<Matrix> lstm_cell(Matrix, Matrix, Matrix,
            Matrix, Matrix, Matrix,
            Matrix, Matrix, Matrix,
            Matrix, Matrix, Matrix,
            Matrix, Matrix, Matrix);
    std::vector<Matrix> peephole_lstm_cell(Matrix, Matrix,
            Matrix, Matrix, Matrix,
            Matrix, Matrix, Matrix,
            Matrix, Matrix, Matrix,
            Matrix, Matrix, Matrix);
    // std::vector<Matrix> gru_cell;
    
};

Matrix ScorpionLayer::dense(Matrix x, Matrix W, Matrix b, int activation){
    /*
    A simple implementation of a fully connected dense layer.
    Args:
        x : input to the layers
        W : weights of the layer
        b : bias of the layer
        activation: activation can be of following types:
            1. sigmoid
            2. tanh
            3. relu
            4. softmax
            5. None (default)
    Returns:
        layer_out : a matrix with proper activation applied
    */
    CoreOps c;
    CoreLayers cl;
    Matrix layer_out = c.mat_add(c.mat_mul(x, W), b);
    switch(activation) {
        case 1: return cl.sigmoid(layer_out);
        case 2: return cl.tanh(layer_out);
        case 3: return cl.relu(layer_out);
        case 4: return cl.softmax(layer_out, 'h');
        default: return layer_out;
    }
}

std::vector<Matrix> ScorpionLayer::lstm_cell(Matrix input_, Matrix hidden_prev, Matrix prev_cell_state,
        Matrix W_f, Matrix U_f, Matrix b_f,
        Matrix W_i, Matrix U_i, Matrix b_i,
        Matrix W_c, Matrix U_c, Matrix b_c,
        Matrix W_o, Matrix U_o, Matrix b_o){
    /*
    Single instance to perform one LSTM operation.
    Args:
        input_: input to the LSTM Cell # 1 x input_dim
        hidden_prev: hidden state at previous time step # 1 x hid_dim
        prev_cell_state: cell state at previous time step # 1 x hid_dim
        W_f, U_f: weights for forget gate # hid_dim x input_dim, hid_dim * hid_dim  
        b_f: weights for forget gate # 1 x hid_dim
        W_i, U_i: weights for input gate # hid_dim x input_dim, hid_dim * hid_dim  
        b_i: weights for input gate # 1 x hid_dim
        W_c, U_c: weights for cell state gate # hid_dim x input_dim, hid_dim * hid_dim  
        b_c: weights for cell gate # 1 x hid_dim
        W_o, U_o: weights for output gate # hid_dim x input_dim, hid_dim * hid_dim  
        b_o: weights for output gate # 1 x hid_dim
    Returns:
        final_vector: a vector of values <state, output>
    */

    // forget gate
    CoreOps c;
    CoreLayers cl;
    Matrix forget_gate = c.mat_add(c.mat_mul(W_f, input_), c.mat_mul(U_f, hidden_prev));
    forget_gate = c.mat_add(forget_gate, b_f);
    forget_gate = cl.sigmoid(forget_gate);

    // input gate
    Matrix input_gate = c.mat_add(c.mat_mul(W_i, input_), c.mat_mul(U_i, hidden_prev));
    input_gate = c.mat_add(input_gate, b_i);
    input_gate = cl.sigmoid(input_gate);

    // output gate
    Matrix output_gate = c.mat_add(c.mat_mul(W_o, input_), c.mat_mul(U_o, hidden_prev));
    output_gate = c.mat_add(output_gate, b_o);
    output_gate = cl.sigmoid(output_gate);

    // cell state
    Matrix curr_cell_state = c.mat_add(c.mat_mul(W_c, input_), c.mat_mul(U_c, hidden_prev));
    curr_cell_state = c.mat_add(curr_cell_state, b_c);
    curr_cell_state = cl.tanh(curr_cell_state);
    curr_cell_state = c.element_wise_matmul(curr_cell_state, input_gate);
    curr_cell_state = c.mat_add(c.element_wise_matmul(forget_gate, prev_cell_state), curr_cell_state);

    // output of cell
    Matrix cell_output = c.element_wise_matmul(output_gate, cl.tanh(curr_cell_state));

    // make final vector
    std::vector<Matrix> final_vector;
    final_vector.push_back(curr_cell_state);
    final_vector.push_back(cell_output);

    // return the vector
    return final_vector;
}

std::vector<Matrix> ScorpionLayer::peephole_lstm_cell(Matrix input_, Matrix prev_cell_state,
        Matrix W_f, Matrix U_f, Matrix b_f,
        Matrix W_i, Matrix U_i, Matrix b_i,
        Matrix W_c, Matrix U_c, Matrix b_c,
        Matrix W_o, Matrix U_o, Matrix b_o){
    /*
    Single instance to perform one Peephole LSTM operation.
    Args:
        input_: input to the LSTM Cell # 1 x input_dim
        prev_cell_state: cell state at previous time step # 1 x hid_dim
        W_f, U_f: weights for forget gate # hid_dim x input_dim, hid_dim * hid_dim  
        b_f: weights for forget gate # 1 x hid_dim
        W_i, U_i: weights for input gate # hid_dim x input_dim, hid_dim * hid_dim  
        b_i: weights for input gate # 1 x hid_dim
        W_c, U_c: weights for cell state gate # hid_dim x input_dim, hid_dim * hid_dim  
        b_c: weights for cell gate # 1 x hid_dim
        W_o, U_o: weights for output gate # hid_dim x input_dim, hid_dim * hid_dim  
        b_o: weights for output gate # 1 x hid_dim
    Returns:
        final_vector: a vector of values <state, output>
    */

    // forget gate
    CoreOps c;
    CoreLayers cl;
    Matrix forget_gate = c.mat_add(c.mat_mul(W_f, input_), c.mat_mul(U_f, prev_cell_state));
    forget_gate = c.mat_add(forget_gate, b_f);
    forget_gate = cl.sigmoid(forget_gate);

    // input gate
    Matrix input_gate = c.mat_add(c.mat_mul(W_i, input_), c.mat_mul(U_i, prev_cell_state));
    input_gate = c.mat_add(input_gate, b_i);
    input_gate = cl.sigmoid(input_gate);

    // output gate
    Matrix output_gate = c.mat_add(c.mat_mul(W_o, input_), c.mat_mul(U_o, prev_cell_state));
    output_gate = c.mat_add(output_gate, b_o);
    output_gate = cl.sigmoid(output_gate);

    // cell state
    Matrix curr_cell_state = c.mat_add(c.mat_mul(W_c, input_), c.mat_mul(U_c, prev_cell_state));
    curr_cell_state = c.mat_add(curr_cell_state, b_c);
    curr_cell_state = cl.tanh(curr_cell_state);
    curr_cell_state = c.element_wise_matmul(curr_cell_state, input_gate);
    curr_cell_state = c.mat_add(c.element_wise_matmul(forget_gate, prev_cell_state), curr_cell_state);

    // output of cell
    Matrix cell_output = c.element_wise_matmul(output_gate, cl.tanh(curr_cell_state));

    // make final vector
    std::vector<Matrix> final_vector;
    final_vector.push_back(curr_cell_state);
    final_vector.push_back(cell_output);

    // return the vector
    return final_vector;
    
}


/*
finish later
std::vector<Matrix> ScorpionLayer::gru_cell(Matrix input_, Matrix prev_cell_state,
        Matrix W_z, Matrix U_z, Matrix b_z,
        Matrix W_r, Matrix U_r, Matrix b_r,
        Matrix W_h, Matrix U_h, Matrix b_h){
    /*
    Single instance to perform one GRU operation.
    Args:
        input_: input to the GRU Cell at current time
        prev_cell_state: output of GRU at previous time
        W_z, U_z: parameters matrices of update gate
        b_z: parameter bias of update gate
        W_r, U_r: parameters matrices of reset gate
        b_r: parameter bias of reset gate
        W_h, U_h: parameters matrices of output gate
        b_h: parameter bias of output gate
    Returns:
        final_vector: a vector of values <state, output>
    
    
    // update gate
    Matrix update_gate = CoreOps.mat_add(CoreOps.mat_mul(W_z, input_), CoreOps.mat_mul(U_z, prev_cell_state))
    update_gate = CoreOps.mat_add(update_gate, b_z)
    update_gate = CoreLayers.sigmoid(update_gate)

    // reset gate
    Matrix reset_gate = CoreOps.mat_add(CoreOps.mat_mul(W_r, input_), CoreOps.mat_mul(U_r, prev_cell_state))
    reset_gate = CoreOps.mat_add(reset_gate, b_r)
    reset_gate = CoreLayers.sigmoid(reset_gate)

    // output vector
    Matrix hid_1 = 

    // make vector

    // return the vector
}
*/
#endif