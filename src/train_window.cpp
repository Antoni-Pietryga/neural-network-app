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


  Stats_Window stats_win;

  QLineSeries *loss_series = new QLineSeries();
  loss_series -> setName(QString("Loss"));
	for(int i=0; i<loss_data.size(); i++)
		loss_series->append(i, loss_data[i]);

  QLineSeries *accuracy_series = new QLineSeries();
  accuracy_series-> setName(QString("Accuracy"));
	for(int i=0; i<accuracy_data.size(); i++)
		accuracy_series->append(i, accuracy_data[i]);

	QChart *chart = new QChart();
	chart->legend()->hide();
	chart->addSeries(loss_series);
	chart->addSeries(accuracy_series);
	chart->createDefaultAxes();
	chart->setTitle("Loss and accuracy");
  chart->legend()->setVisible(true);
  chart->legend()->setAlignment(Qt::AlignBottom);
  //chart->axisX()->setRange(0, 10);
  chart->axisY()->setRange(0, 1);
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
