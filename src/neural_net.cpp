#include "neural_net.h"
#include <torch/torch.h>


NeuralNetImpl::NeuralNetImpl(int64_t input_size, int64_t num_classes) :
	fc1(input_size, 64),
	fc2(64, 32),
	fc3(32, num_classes){

	register_module("fc1", fc1);
    register_module("fc2", fc2);
    register_module("fc3", fc3);
}

torch::Tensor NeuralNetImpl::forward(torch::Tensor x) {

        x = torch::relu(fc1->forward(x));
        x = torch::relu(fc2->forward(x));
		x = fc3->forward(x);
        return x;
    }
