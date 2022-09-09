#ifndef NEURAL_NET_H
#define NEURAL_NET_H

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
    	NeuralNetImpl(int64_t input_size, int64_t num_classes);
    	torch::Tensor forward(torch::Tensor x);
    	/** Calculate output for tensor
	@param x - input tensor.	
	*/

private:
	torch::nn::Linear fc1{nullptr}, fc2{nullptr}, fc3{nullptr};
};

TORCH_MODULE(NeuralNet);
#endif
