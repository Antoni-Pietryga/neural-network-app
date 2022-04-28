
#include "neural_net.h"
#include <torch/torch.h>

NeuralNetImpl::NeuralNetImpl(int64_t input_size, int64_t hidden_size_, int64_t num_classes) : 
	conv1(torch::nn::Conv2dOptions(1, input_size, {1, 5})),
	conv2(torch::nn::Conv2dOptions(input_size, hidden_size_, {1, 5})),
	conv2_drop(),
	fc1(19*hidden_size_, 50), 
	fc2(50, num_classes),
	hidden_size(hidden_size_) {

    	register_module("conv1", conv1);
    	register_module("conv2", conv2);
    	register_module("conv2_drop", conv2_drop);
	register_module("fc1", fc1);
    	register_module("fc2", fc2);
}

torch::Tensor NeuralNetImpl::forward(torch::Tensor x) {
        
        x = torch::relu(torch::max_pool2d(conv1->forward(x), {1, 5}));
        x = torch::relu(torch::max_pool2d(conv2_drop->forward(conv2->forward(x)), {1, 5}));
        x = x.view({100, 19*hidden_size});
        x = torch::relu(fc1->forward(x));
        x = torch::dropout(x, 0.5, is_training());
        x = fc2->forward(x);
        return torch::log_softmax(x, 1);
    }
