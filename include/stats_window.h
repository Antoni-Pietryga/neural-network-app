#ifndef STATS_WINDOW_H
#define STATS_WINDOW_H

#include <QDialog>
#include "ui_stats_window.h"
#include <QtCharts/QChartView>
using namespace QtCharts;
namespace Ui {
class Stats_Window;
}

class Stats_Window : public QDialog
{
    Q_OBJECT

public:
    explicit Stats_Window(QWidget *parent = nullptr);
    ~Stats_Window();
    void setCv(QChartView* cv_);
    void printChart();

private:
    Ui::Stats_Window *ui;
    QChartView* cv;
};

#endif // STATS_H
