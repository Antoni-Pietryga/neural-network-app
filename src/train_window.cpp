#include <torch/torch.h>
#include "train_window.h"
#include "ui_train_window.h"
#include <QFileDialog>
#include <QMessageBox>
#include <iostream>
#include "stats_window.h"
#include "train.h"
#include "train_params.h"
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
      	string train_root = dataset_dir; //"../data/train.csv";
      	string save_path = "../net.pt";
      	Train train = Train(train_root, params, save_path, ui);
      	train.train();
          	std::cout << "Training finished!\n\n";

        //for(int i=1; i<=epochs; i++){

        //}
        /*
        Stats_Window status_win;
        status_win.setModal(true);
        status_win.exec();
        */
    }
    else {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Wrong dataset directory!");
        messageBox.setFixedSize(500,200);
    }


}
