#include <iostream>
#include <torch/torch.h>
#include "dataset.h"
#include "neural_net.h"
#include "train_params.h"
using namespace std;


class Train{
public:
	string train_path;
	TrainParameters params = TrainParameters(30, 20, 50, 0.001);
	string model_save_path;
	
	explicit Train(string train_path_, const TrainParameters &params_, string model_save_path_);
	void train();
	
};

