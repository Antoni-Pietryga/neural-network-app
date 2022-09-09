#include <torch/torch.h>
#include <QFileDialog>
#include <QMessageBox>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <iostream>
#include <tuple>
#include <vector>

#include "dataset.h"
#include "train_window.h"
#include "ui_train_window.h"
#include "stats_window.h"
#include "train.h"
#include "train_params.h"

using namespace QtCharts;

Train_Window::Train_Window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Train_Window)
{
    ui->setupUi(this);
}

Train_Window::~Train_Window()
{
    delete ui;
}

void Train_Window::log_message(string message){
	cout<<message<<endl;
	ui->text_browser->append(QString::fromStdString(message));
	qApp->processEvents();
}

void Train_Window::on_dataset_button_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "Choose data", "C://");
    ui->dataset_dir_label->setText(filename);
}


void Train_Window::on_train_button_clicked()
{
    QString invalid_string = "None";
    if ( ui->dataset_dir_label->text() != invalid_string ){

		TrainParameters params = load_config_file();

		log_message("Training...\n");

      	string train_data_path = params.dataset_dir; //"../data/train.csv";
      	string save_path = ui->model_name_line_edit->text().toStdString();
        save_path = "../"+save_path;
      	Train train = Train(train_data_path, params, save_path, ui);
      	auto loss_accuracy = train.train();
		auto loss_data = get<0>(loss_accuracy);
		auto accuracy_data = get<1>(loss_accuracy);

		log_message("Training finished!\n\n");

		QMessageBox messageBox;
		QString mess =  QString::fromStdString("Trainig ended. Saved model to  " + save_path);
		messageBox.information(0,"Finished",  mess);
		messageBox.setFixedSize(500,200);


	  	Stats_Window stats_win;

	  	QLineSeries *loss_series = new QLineSeries();
	  	loss_series -> setName(QString("Loss"));

		for(int i=0; i<loss_data.size(); i++)
			loss_series->append(i, loss_data[i]);

	  	QLineSeries *accuracy_series = new QLineSeries();
	  	accuracy_series-> setName(QString("Validation loss"));

		for(int i=0; i<accuracy_data.size(); i++)
			accuracy_series->append(i, accuracy_data[i]);

		QChart *chart = new QChart();
		chart->legend()->hide();
		chart->addSeries(loss_series);
		chart->addSeries(accuracy_series);
		chart->createDefaultAxes();
		chart->setTitle("Loss");
	  	chart->legend()->setVisible(true);
	  	chart->legend()->setAlignment(Qt::AlignBottom);
	  	//chart->axisX()->setRange(0, 10);
	  	//chart->axisY()->setRange(0, 1);
	  	QChartView *chartView = new QChartView(chart);
		chartView->setRenderHint(QPainter::Antialiasing);

	  	stats_win.setCv(chartView);
	  	stats_win.printChart();
	  	stats_win.setModal(true);
	  	stats_win.exec();
		}
		else {
		    QMessageBox messageBox;
		    messageBox.critical(0,"Error","Wrong dataset directory!");
		    messageBox.setFixedSize(500,200);
		}
}

TrainParameters Train_Window::load_config_file(){
	// Load config variables from file
  	ifstream config_file(ui->dataset_dir_label->text().toStdString());
	string temp;

    getline (config_file, temp);
    int input_size = stoi(temp);

    getline (config_file, temp);
    int output_size = stoi(temp);

    getline (config_file, temp);
    int shift = stoi(temp);

	getline (config_file, temp);
    string column_name = temp;

	getline (config_file, temp);
    string dataset_dir = temp;

	config_file.close();

    int epoch_number = ui->epoch_num_line_edit->text().toInt();
    double lr =  ui->lr_line_edit->text().toDouble();

    TrainParameters params = TrainParameters(input_size, output_size, epoch_number, lr, shift, column_name, dataset_dir);

	return params;
}
