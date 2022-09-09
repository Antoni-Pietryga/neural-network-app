#include "train.h"
#include "ui_train_window.h"
#include "dataset.h"

#include <QMessageBox>
#include <QFileDialog>
#include <tuple>
#include <vector>
#include <torch/torch.h>
#include <iostream>

using namespace std;

void Train::log_message(string message){
	cout<<message<<endl;
	ui->text_browser->append(QString::fromStdString(message));
	qApp->processEvents();
}

tuple<vector<double>, vector<double>> Train::train(){

	int batch_size = 32;

	//prepare dataset
	WindowGenerator wg = WindowGenerator(params.dataset_dir);
	wg.split_to_windows(params.input_size, params.output_size, params.shift, params.column_name);

	auto train_data = wg.get_train();
	auto train_data_x = train_data.first;
	auto train_data_y = train_data.second;

	int num_train_samples = train_data_x.size();
	int num_batches = (int)num_train_samples/batch_size;
	num_train_samples = num_batches*batch_size;

	auto targets = torch::empty({num_batches, batch_size, params.output_size}, torch::kFloat);
    auto values = torch::empty({num_batches, batch_size, params.input_size}, torch::kFloat);
  	// write data to tensor

	log_message("Creaing train dataset...");

	for(int i=0;i<num_train_samples;i++){

		for(int j=0;j<params.output_size;j++)
			targets[(int)i/batch_size][i%batch_size][j] = train_data_y[i][j];
		for(int j=0;j<params.input_size;j++)
			values[(int)i/batch_size][i%batch_size][j] = train_data_x[i][j];

	  }

	log_message("Creaing valid dataset...");

	auto valid_data = wg.get_valid();
	auto valid_data_x = valid_data.first;
	auto valid_data_y = valid_data.second;

	int num_valid_samples = valid_data_x.size();
	int num_valid_batches = (int)num_valid_samples/batch_size;
	num_valid_samples = num_valid_batches*batch_size;

	auto valid_targets = torch::empty({num_valid_batches, batch_size, params.output_size}, torch::kFloat);
    auto valid_values = torch::empty({num_valid_batches, batch_size, params.input_size}, torch::kFloat);

	// write data to tensor
	for(int i=0;i<num_valid_samples;i++){

		for(int j=0;j<params.output_size;j++)
			valid_targets[(int)i/batch_size][i%batch_size][j] = valid_data_y[i][j];
		for(int j=0;j<params.input_size;j++)
			valid_values[(int)i/batch_size][i%batch_size][j] = valid_data_x[i][j];

	  }
	  //Training

	NeuralNet net(params.input_size, params.output_size);

	// Optimizer
	torch::optim::SGD optimizer(net->parameters(), params.lr); // Learning Rate 0.01

	log_message("Training...");

	vector<double> loss_arr;
	vector<double> val_loss_arr;
	for(size_t epoch=1; epoch<=params.epoch_number; ++epoch) {
		torch::Tensor loss;
		// Iterate data loader to yield batches from the dataset
		float loss_sum = 0;
		float loss_valid_sum = 0;
		for (int batch_id=0;batch_id<num_batches;batch_id++) {
			optimizer.zero_grad();
			torch::Tensor prediction = net->forward(values[batch_id]);
			loss = torch::nn::functional::mse_loss(prediction, targets[batch_id]);
			loss.backward();
			optimizer.step();
			loss_sum += loss.item<double>();

		}
		loss_arr.push_back(loss_sum/num_batches);

		for (int batch_id=0;batch_id<num_valid_batches;batch_id++) {
			torch::Tensor prediction = net->forward(valid_values[batch_id]);
			loss = torch::nn::functional::mse_loss(prediction, valid_targets[batch_id]);
			loss_valid_sum += loss.item<double>();

		}
		val_loss_arr.push_back(loss_valid_sum/num_valid_batches);

		stringstream ss;
		ss << "Epoch [" << (epoch) << "/" << params.epoch_number << "]" << " | Loss: " << loss_sum/num_batches  << " | Val Loss: " << loss_valid_sum/num_valid_batches << '\n';
		log_message(ss.str());

	}
	torch::save(net, model_save_path);
	return make_tuple(loss_arr, val_loss_arr);
}

Train::Train(string train_path_, const TrainParameters &params_, string model_save_path_, Ui_Train_Window *ui_){
		train_path = train_path_;
		params = params_;
		model_save_path = model_save_path_;
		ui = ui_;
	}
