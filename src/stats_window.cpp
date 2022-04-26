#include "stats_window.h"
#include "ui_stats_window.h"

Stats_Window::Stats_Window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Stats_Window)
{
    ui->setupUi(this);

    //ui->label_2->setPixmap(QPixmap(QString::fromUtf8("D:/plot.jpg")));
    //ui->label_2->show();
}

Stats_Window::~Stats_Window()
{
    delete ui;
}
