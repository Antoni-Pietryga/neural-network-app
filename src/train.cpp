#include "train.h"
#include <QMessageBox>
#include "ui_train_window.h"
#include <QFileDialog>
#include <tuple>
#include <vector>
using namespace std;

tuple<vector<double>, vector<double>> Train::train(){
		NeuralNet net(params.input_size, params.hidden_size, params.num_classes);
		auto train_data = Data(train_path);
		auto train_dataset = train_data.map(torch::data::transforms::Stack<>());
		auto train_loader = torch::data::make_data_loader<torch::data::samplers::RandomSampler>(std::move(train_dataset), params.batch_size);
		// Number of samples in the training set
		auto num_train_samples = train_data.targets().sizes()[0];
		// Optimizer
		torch::optim::SGD optimizer(net->parameters(), 0.01); // Learning Rate 0.01

		vector<double> loss_arr;
		vector<double> accuracy_arr;

		for(size_t epoch=1; epoch<=params.num_epochs; ++epoch) {
			size_t batch_index = 0;
			size_t num_correct = 0;
			torch::Tensor loss;
			// Iterate data loader to yield batches from the dataset
			for (auto& batch: *train_loader) {
				// Reset gradients
				optimizer.zero_grad();
				// Execute the model
				torch::Tensor prediction = net->forward(batch.data.view({params.batch_size, 1, 1, 500}));

				// Compute loss value
				loss = torch::nll_loss(prediction, batch.target);
				// Compute gradients
				loss.backward();
				// Update the parameters
				optimizer.step();
				// Update number of correctly classified samples
				auto pred = prediction.argmax(1);

				num_correct += pred.eq(batch.target).sum().item<int64_t>();


			}

			auto accuracy = static_cast<double>(num_correct) / num_train_samples;
			loss_arr.push_back(loss.item<double>());
			accuracy_arr.push_back((double)accuracy);
			
			ui->textBrowser->append(QStringLiteral("Epoch [ %1/%2], Accuracy: %3, Loss: %4 \n").arg(epoch).arg(params.num_epochs).arg(accuracy).arg(loss.item<float>()));
   			qApp->processEvents();

			std::cout << "Epoch [" << (epoch) << "/" << params.num_epochs << "],  Accuracy: " << accuracy << " | Loss: " << loss.item<float>() << '\n';
		}
		torch::save(net, model_save_path);
	
	return make_tuple(loss_arr, accuracy_arr);
	}

Train::Train(string train_path_, const TrainParameters &params_, string model_save_path_, Ui_Train_Window *ui_){
		train_path = train_path_;
		params = params_;
		model_save_path = model_save_path_;
		ui = ui_;
	}
