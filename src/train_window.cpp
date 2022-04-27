#include <torch/torch.h>
#include "train_window.h"
#include "ui_train_window.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <iostream>
#include "stats_window.h"
#include "train.h"
#include <tuple>
#include <vector>

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


void Train_Window::on_data_button_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "Choose data", "C://");
    ui->pred_dir->setText(filename);
}


void Train_Window::on_pushButton_2_clicked()
{
    QString n = "None";
    if ( ui->pred_dir->text() != n ){
        int epochs = ui->horizontalSlider->value();
        double lr =  ui->lineEdit->text().toInt();
        int first_layer_neurons = ui->lineEdit_2->text().toInt();
        int second_layer_neurons = ui->lineEdit_3->text().toInt();
        std::string dataset_dir = ui->pred_dir->text().toStdString();
        //Run trainig
        TrainParameters params = TrainParameters(first_layer_neurons, second_layer_neurons, epochs, lr);
        std::cout << "Training...\n";
	ui->textBrowser->append(QStringLiteral("Training..."));
	qApp->processEvents();
      	string train_root = dataset_dir; //"../data/train.csv";
      	string save_path = "../net.pt";
      	Train train = Train(train_root, params, save_path, ui);
      	auto loss_accuracy = train.train();
	auto loss_data = get<0>(loss_accuracy);
	auto accuracy_data = get<1>(loss_accuracy);
        std::cout << "Training finished!\n\n";
	ui->textBrowser->append(QStringLiteral("Training finished..."));
	QMessageBox messageBox;
	QString mess =  QString::fromStdString("Trainig ended. Saved model to  " + save_path);
	messageBox.information(0,"Finished",  mess);
	messageBox.setFixedSize(500,200);
        
        
        /*QLineSeries *loss = new QLineSeries();
	array<double, 14> los_arr = {6.32, 5.22, 5.14, 4.67, 4.2, 4.34, 4.1, 3.8, 3.4, 3.12, 2.6, 1.2, 0.7, 0.2};
	for(int i=0; i<los_arr.size(); i++)
		loss->append(i, los_arr[i]);

	QLineSeries *accuracy = new QLineSeries();
	array<double, 14> accuracy_arr = {0.01, 0.05, 0.07, 0.12, 0.1, 0.17, 0.22, 0.20, 0.33, 0.38, 0.41, 0.48,0.55, 0.64};
	for(int i=0; i<accuracy_arr.size(); i++)
		accuracy->append(i, accuracy_arr[i]);


	QChart *chart = new QChart();
	chart->legend()->hide();
	chart->addSeries(loss);
	chart->addSeries(accuracy);
	chart->createDefaultAxes();
	chart->setTitle("Loss and accuracy");

	QChartView *chartView = new QChartView(chart);
	chartView->setRenderHint(QPainter::Antialiasing);

	Stats_Window status_win;
        status_win.setModal(true);
	status_win.addWidget(chartView);
        status_win.exec();*/
    }
    else {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Wrong dataset directory!");
        messageBox.setFixedSize(500,200);
    }


}
