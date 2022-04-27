#ifndef STATS_WINDOW_H
#define STATS_WINDOW_H

#include <QDialog>

namespace Ui {
class Stats_Window;
}

class Stats_Window : public QDialog
{
    Q_OBJECT

public:
    explicit Stats_Window(QWidget *parent = nullptr);
    ~Stats_Window();

private:
    Ui::Stats_Window *ui;
};

#endif // STATS_H
