#ifndef TRAIN_PARAMETERS_
#define TRAIN_PARAMETERS_
#include <torch/torch.h>

struct TrainParameters{
public:
	int64_t input_size;
    	int64_t hidden_size;
    	int64_t num_classes = 2;
    	int64_t batch_size = 100;
    	size_t num_epochs;
    	double learning_rate;
	TrainParameters(int64_t input_size_, int64_t hidden_size_, int64_t num_epochs_, double learning_rate_);
};
#endif
