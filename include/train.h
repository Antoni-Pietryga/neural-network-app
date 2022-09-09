#ifndef TRAIN_H
#define TRAIN_H

#include <iostream>
#include <torch/torch.h>
#include "dataset.h"
#include "neural_net.h"
#include "train_params.h"
#include "ui_train_window.h"
#include <QFileDialog>
#include <tuple>
#include <vector>
#include "dataset.h"

using namespace std;
/** @brief  Required polymorphism implementation.
*/
class TrainBase{
public:
    virtual tuple<vector<double>, vector<double>> train()=0;
};
/** @brief The class responsible for train pipeline.
*/
class Train : TrainBase{
public:
	string train_path;
	TrainParameters params = TrainParameters(6, 1, 50, 0.001, 6, "p (mbar)","./data/jena_climate_2009_2016.csv");
	string model_save_path;
	Ui_Train_Window *ui;
	/** Constructor. Initialize train_path, params and model_path.
	@param train_path - path to the dataset
	@param params - object of structure contains input size, output size, number of epochs, learning rate, shift, name of column and path to csv file
	@param model_save_path_ - path when trained model will be save
	@param ui - object contains all window arguments
	**/
	explicit Train(string train_path_, const TrainParameters &params_, string model_save_path_, Ui_Train_Window *ui);
	/**Run train on selected file and given parameters.
        @return tuple of calculated loss and accuracy.
        */
	tuple<vector<double>, vector<double>> train();
private:
	void log_message(string message);
};
#endif
