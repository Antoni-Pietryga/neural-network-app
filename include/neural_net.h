#pragma once

#include <torch/torch.h>
/** @brief The class responsible for Neural network implementation.
*/
class NeuralNetImpl : public torch::nn::Module {
public:
	/** Constructor. Initialize path and mode.
	@param input_size - size of first layer.
	@param hidden_size - size of second layer.
	@param num_classes - oututput layer size.
	*/
    	NeuralNetImpl(int64_t input_size, int64_t hidden_size_, int64_t num_classes = 2);
	/** Calculate output for tensor
	@param x - input tensor.	
	*/
    	torch::Tensor forward(torch::Tensor x);

private:
	torch::nn::Conv2d conv1{nullptr};
 	torch::nn::Conv2d conv2{nullptr};
    	torch::nn::Dropout conv2_drop{nullptr};
    	torch::nn::Linear fc1{nullptr}, fc2{nullptr};
	int64_t hidden_size;
};

TORCH_MODULE(NeuralNet);
