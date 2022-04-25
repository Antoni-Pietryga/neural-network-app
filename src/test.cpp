#include "test.h"
using namespace std;
Test::Test(string test_path_, const TrainParameters &params_, string model_path_){
	test_path = test_path_;
	params = params_;
	model_path = model_path_;
}

void Test::test(){
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

		}
