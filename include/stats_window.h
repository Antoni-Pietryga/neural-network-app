#ifndef STATS_WINDOW_H
#define STATS_WINDOW_H

#include <QDialog>
#include "ui_stats_window.h"
#include <QtCharts/QChartView>
using namespace QtCharts;
namespace Ui {
class Stats_Window;
}
/** @brief The class responsible for displaying
the results of the training of neural network

*/
class Stats_Window : public QDialog
{
    Q_OBJECT

public:
    explicit Stats_Window(QWidget *parent = nullptr);
    ~Stats_Window();
    /** Assigns the chart to a private field *cv
        @param cv_ *chartView of accuracy/loss chart
    */
    void setCv(QChartView* cv_);
    /** Display chart on label_2 field
    */
    void printChart();

private:
    Ui::Stats_Window *ui;
    QChartView* cv;
};

#endif // STATS_H
