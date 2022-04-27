#include <iostream>
#include <torch/torch.h>
#include "dataset.h"
#include "neural_net.h"
#include "train_params.h"
#include "ui_train_window.h"
#include <QFileDialog>
using namespace std;


class Train{
public:
	string train_path;
	TrainParameters params = TrainParameters(30, 20, 50, 0.001);
	string model_save_path;
	Ui_Train_Window *ui;
	explicit Train(string train_path_, const TrainParameters &params_, string model_save_path_, Ui_Train_Window *ui);
	void train();

};
