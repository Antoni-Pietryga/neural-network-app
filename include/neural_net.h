#pragma once

#include <torch/torch.h>

class NeuralNetImpl : public torch::nn::Module {
 public:
    NeuralNetImpl(int64_t input_size, int64_t hidden_size, int64_t num_classes = 2);

    torch::Tensor forward(torch::Tensor x);

 private:
	torch::nn::Conv2d conv1{nullptr};
 	torch::nn::Conv2d conv2{nullptr};
    	torch::nn::Dropout conv2_drop{nullptr};
    	torch::nn::Linear fc1{nullptr}, fc2{nullptr};
};

TORCH_MODULE(NeuralNet);
