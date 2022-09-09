#include "train_params.h"

TrainParameters::TrainParameters(int input_size_, int output_size_, int epoch_number_, double lr_, int shift_, string column_name_, string dataset_dir_){
	input_size = input_size_;
	output_size = output_size_;
	epoch_number = epoch_number_;
	lr = lr_;
	shift = shift_;
	column_name = column_name_;
	dataset_dir = dataset_dir_;
}

