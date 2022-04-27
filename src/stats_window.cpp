#include "stats_window.h"
#include "ui_stats_window.h"
#include <QVBoxLayout>

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

void Stats_Window::setCv(QChartView* cv_)
{
    this->cv = cv_;
}

void Stats_Window::printChart()
{
  QVBoxLayout *main_layout = new QVBoxLayout(ui->label_2);
  //main_layout.setAlignment(Qt::AlignCenter);
  cv->setMaximumSize(10000,100000);
  main_layout->addWidget(cv,Qt::AlignCenter);
  //main_layout.resize(640,480);
  setLayout(main_layout);
}
