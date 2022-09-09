#include <torch/torch.h>
#include "predict_window.h"
#include "ui_predict_window.h"
#include "main_window.h"
#include "ui_main_window.h"
#include <QFileDialog>
#include <QMessageBox>
#include <string>
#include "predict.h"
#include "train_params.h"

Predict_Window::Predict_Window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Predict_Window)
{
    ui->setupUi(this);
}

Predict_Window::~Predict_Window()
{
    delete ui;
}


void Predict_Window::log_message(string message){
	cout<<message<<endl;
	ui->text_browser->append(QString::fromStdString(message));
	qApp->processEvents();
}

void Predict_Window::on_model_button_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "Choose model", "C://");
    ui->model_dir->setText(filename);
}



void Predict_Window::on_data_button_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "Choose data", "C://");
    ui->pred_dir->setText(filename);
}

void Predict_Window::on_test_button_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "Choose csv file", "C://");
    ui->test_dir->setText(filename);
}


void Predict_Window::on_predict_button_clicked()
{
  string model_dir = ui->model_dir->text().toStdString();
  string config_dir = ui->pred_dir->text().toStdString();
  Predict prediction = Predict(model_dir, config_dir, ui);
  float f = prediction.predict();
  /*
    QString n = "None";
    if (ui->model_dir->text() != n && ui->pred_dir->text() != n ){
        std::string save_path = ui->model_dir->text().toStdString();
        std::string test_root = ui->pred_dir->text().toStdString();
        //std::string save_path = ui->res_dir->text().toStdString();

        int first_layer_neurons = ui->lineEdit_2->text().toInt();
        int second_layer_neurons = ui->lineEdit_3->text().toInt();

        //Run prediction
        TrainParameters params = TrainParameters(first_layer_neurons, second_layer_neurons, 20, 0.001);

        //string save_path = "../net.pt";
        std::cout << "Testing...\n";
      	//string test_root = "../data/test.csv";
      	Test test = Test(test_root, params, save_path);
      	float Accuracy = test.test();
      	std::cout << "Testing finished!\n\n";

        QMessageBox messageBox;
        QString mess =  QString::fromStdString("Prediction complete \n Accuracy(%): " + std::to_string(Accuracy));
        messageBox.information(0,"Prediction complete",  mess);
        messageBox.setFixedSize(500,200);
    }
    else{
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Wrong input");
        messageBox.setFixedSize(500,200);
    }*/
}
