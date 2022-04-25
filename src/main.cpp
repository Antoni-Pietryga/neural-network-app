#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <array>
#include <sstream>
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <cstring>
#include <iostream>
#include <iomanip>
#include "train.h"
#include "test.h"
#include "train_params.h"

#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>

using namespace std;


int main(int argc, char *argv[])
{	
	
	// Device
    	//auto cuda_available = torch::cuda::is_available();
    	//torch::Device device(cuda_available ? torch::kCUDA : torch::kCPU);
    	//std::cout << (cuda_available ? "CUDA available. Training on GPU." : "Training on CPU.") << '\n';
	
	TrainParameters params = TrainParameters(30, 20, 20, 0.001);
    	std::cout << "Training...\n";
	string train_root = "../data/train.csv";
	string save_path = "../net.pt"; 
	Train train = Train(train_root, params, save_path);
	train.train();
    	std::cout << "Training finished!\n\n";
	
	std::cout << "Testing...\n";
	string test_root = "../data/test.csv";
	Test test = Test(test_root, params, save_path);
	test.test();
	std::cout << "Testing finished!\n\n";
	
	QApplication app(argc, argv);

	QWidget widget;
	widget.resize(400, 400);
	widget.setWindowTitle("QTestApp");

	QGridLayout *gridLayout = new QGridLayout(&widget);

	QLabel * label = new QLabel("Test end");
	label->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);

	gridLayout->addWidget(label);

	widget.show();
	return app.exec();

	return 0;
}
