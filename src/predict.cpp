#include "predict.h"
#include "dataset_window.h"
#include "ui_predict_window.h"
#include "predict_window.h"
using namespace std;
Predict::Predict(string model_dir, string config_dir, Ui_Predict_Window *ui_){//string test_path_, const TrainParameters &params_, string model_path_){
	predict_path = config_dir;
	model_path = model_dir;
	ui = ui_;
/*
	test_path = test_path_;
	params = params_;
	model_path = model_path_;
*/
}

vector <string> load_dataset(string config_path){
	ifstream config(config_path);
	string line;
	vector <string> lines;
	while(getline(config,line)){
			lines.push_back(line);
	}
	config.close();
 return lines;
}

void Predict::log_message(string message){
	cout<<message<<endl;
	ui->text_browser->append(QString::fromStdString(message));
	qApp->processEvents();
}

float Predict::predict(){

		int batch_size = 1;
		vector <string> config = load_dataset(this->predict_path);
		string csv_path = ui->test_dir->text().toStdString();
		int rows_number = stoi(config[0]);
		int output_number = stoi(config[1]);
		int shift = stoi(config[2]);
		string column_name = config[3];

		WindowGenerator wg = WindowGenerator(csv_path);
		wg.split_to_windows(rows_number, output_number, shift, column_name);
		auto train_data = wg.get_train();
		auto train_data_x = train_data.first;
		auto train_data_y = train_data.second;

		int num_train_samples = train_data_x.size();
		int num_batches = (int)num_train_samples/batch_size;
		num_train_samples = num_batches*batch_size;

		auto targets = torch::empty({num_batches, batch_size, output_number}, torch::kFloat);
	    auto values = torch::empty({num_batches, batch_size, rows_number}, torch::kFloat);
	  	// write data to tensor


		for(int i=0;i<num_train_samples;i++){

			for(int j=0;j<output_number;j++)
				targets[(int)i/batch_size][i%batch_size][j] = train_data_y[i][j];
			for(int j=0;j<rows_number;j++)
				values[(int)i/batch_size][i%batch_size][j] = train_data_x[i][j];

		  }

			NeuralNet net(rows_number, output_number);
			for(int i = 0; i<num_train_samples;i++){
			torch::Tensor prediction = net->forward(values[i]);
			stringstream ss;
			ss<<"Data: ";
			for(int j = 0; j<rows_number; j++){
				ss<<values[i][0][j].item<float>()<<' ';
			}
			ss<<"\nPrediction: ";
			if(output_number>1){
			for(int j = 0; j<output_number; j++){
				ss<<10*prediction[0][j].item<float>()<<' ';
			}
			ss<<endl<<endl;
		}
		else{
				ss<<10*prediction.item<float>()<<endl;
			}
			log_message(ss.str());

		}
		return 1.0;
	/*

		auto test_data = Data(test_path);
		auto test_dataset = test_data.map(torch::data::transforms::Stack<>());
		auto test_loader = torch::data::make_data_loader<torch::data::samplers::RandomSampler>(
			std::move(test_dataset), params.batch_size);
		auto num_test_samples = test_data.targets().sizes()[0];

		NeuralNet net(params.input_size, params.hidden_size, params.num_classes);
		torch::load(net, model_path);
		double running_loss = 0.0;
	    	size_t num_correct = 0;
			int c = 0;
	    	for (const auto& batch : *test_loader) {
			cout<<batch.data.sizes()<<endl;
			auto data = batch.data.view({params.batch_size, 1, 1, 500});
			auto target = batch.target;

			auto output = net->forward(data);

			auto loss = torch::nn::functional::cross_entropy(output, target);

			running_loss += loss.item<double>() * data.size(0);

			auto prediction = output.argmax(1);

			num_correct += prediction.eq(target).sum().item<int64_t>();
			c += 1;
			if(c == 2)
				break;
	    	}
		num_test_samples = 200;

	    	std::cout << "Testing finished!\n";

	    	auto test_accuracy = static_cast<double>(num_correct) / num_test_samples;
	    	auto test_sample_mean_loss = running_loss / num_test_samples;

	    	std::cout << "Testset - Loss: " << test_sample_mean_loss << ", Accuracy: " << test_accuracy << '\n';
				return test_accuracy;
				*/
				return 1.0;
		}
