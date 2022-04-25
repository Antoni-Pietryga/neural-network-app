#include "train_params.h"
TrainParameters::TrainParameters(int64_t input_size_, int64_t hidden_size_, int64_t num_epochs_, double learning_rate_){
	input_size = input_size_;
	hidden_size = hidden_size_;
	num_epochs = num_epochs_;
	learning_rate = learning_rate_;
		
}
