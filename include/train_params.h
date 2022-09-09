#ifndef TRAIN_PARAMS_H
#define TRAIN_PARAMS_H
#include <iostream>
using namespace std;

struct TrainParameters{
public:
	int input_size;
    int output_size;
   	string column_name;
    int shift = 6;
   	int epoch_number;
    double lr;
    string dataset_dir;
	
	TrainParameters(int input_size_, int output_size_, int epoch_number_, double lr_, int shift, string column_name_, string dataset_dir_);
};
#endif
