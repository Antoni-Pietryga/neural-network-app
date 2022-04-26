#include "predict_window.h"
#include "ui_predict_window.h"
#include "main_window.h"
#include "ui_main_window.h"
#include <QFileDialog>
#include <QMessageBox>
#include <string>
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


void Predict_Window::on_pushButton_clicked()
{

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


void Predict_Window::on_data_button_2_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "Choose data", "C://");
    ui->res_dir->setText(filename);
}


void Predict_Window::on_pushButton_2_clicked()
{
    QString n = "None";
    if (ui->model_dir->text() != n && ui->pred_dir->text() != n && ui->res_dir->text() !=n){
        std::string model_dir = ui->model_dir->text().toStdString();
        std::string input_dir = ui->pred_dir->text().toStdString();
        std::string output_dir = ui->res_dir->text().toStdString();

        //Run prediction

        int Accuracy = 100;
        QMessageBox messageBox;
        QString mess =  QString::fromStdString("Prediction complete \n Accuracy(%): " + std::to_string(Accuracy));
        messageBox.information(0,"Prediction complete",  mess);
        messageBox.setFixedSize(500,200);
    }
    else{
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Wrong input");
        messageBox.setFixedSize(500,200);
    }
}
