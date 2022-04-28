#include <iostream>
#include <torch/torch.h>
#include "dataset.h"
#include "neural_net.h"
#include "train_params.h"
#include "ui_train_window.h"
#include <QFileDialog>
#include <tuple>
#include <vector>

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
	TrainParameters params = TrainParameters(30, 20, 50, 0.001);
	string model_save_path;
	Ui_Train_Window *ui;
	/** Constructor. Initialize train_path, params and model_path.
	**/
	explicit Train(string train_path_, const TrainParameters &params_, string model_save_path_, Ui_Train_Window *ui);
	/**Run train on selected file and given parameters.
        @return tuple of calculated loss and accuracy.
        */
	tuple<vector<double>, vector<double>> train();

};
