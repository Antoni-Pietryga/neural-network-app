#ifndef TRAIN_WINDOW_H
#define TRAIN_WINDOW_H

#include <QDialog>
namespace Ui {
class Train_Window;
}

class Train_Window : public QDialog
{
    Q_OBJECT

public:
    explicit Train_Window(QWidget *parent = nullptr);
    ~Train_Window();

private slots:

    void on_data_button_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Train_Window *ui;
};

#endif // TRAIN_H
