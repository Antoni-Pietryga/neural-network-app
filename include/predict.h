#ifndef PREDICT_H
#define PREDICT_H

#include <torch/torch.h>
#include "train_params.h"
#include "dataset.h"
#include "neural_net.h"
#include "ui_predict_window.h"

using namespace std;
/** @brief Required polymorphism implementation.
*/
class PredictBase{
public:
    virtual float predict()=0;
};
/** @brief The class responsible for test pipeline.
*/
class Predict : PredictBase{
public:
	string predict_path;
	string model_path;
	Ui_Predict_Window *ui;

	TrainParameters params = TrainParameters(6, 1, 50, 0.001, 6, "p (mbar)","./data/jena_climate_2009_2016.csv");
	/** Constructor. Initialize params and model_path.
	**/
	explicit Predict(string model_dir, string config_dir,Ui_Predict_Window *ui);//string test_path_, const TrainParameters &params_, string model_path_);
	/** Run test on selected file.
	@return accuracy of predictions in selected file.
	*/
	float predict();
private:
	
	void log_message(string message);
};
#endif
