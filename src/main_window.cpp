
#include "main_window.h"
#include "ui_main_window.h"
#include "predict_window.h"
#include "train_window.h"
#include <QApplication>
Main_Window::Main_Window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Main_Window)
{
    ui->setupUi(this);
}

Main_Window::~Main_Window()
{
    delete ui;
}


void Main_Window::on_predict_button_clicked()
{
    hide();
    Predict_Window predict_win;
    predict_win.setModal(true);
    predict_win.exec();
    show();
}


void Main_Window::on_train_button_clicked()
{
    hide();
    Train_Window train_win;
    train_win.setModal(true);
    train_win.exec();
    show();
}
