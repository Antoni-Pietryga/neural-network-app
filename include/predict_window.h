#ifndef PREDICT_WINDOW_H
#define PREDICT_WINDOW_H

#include <QDialog>

namespace Ui {
class Predict_Window;
}

class Predict_Window : public QDialog
{
    Q_OBJECT

public:
    explicit Predict_Window(QWidget *parent = nullptr);
    ~Predict_Window();

private slots:
    void on_pushButton_clicked();

    void on_model_button_clicked();

    void on_data_button_clicked();

    void on_data_button_2_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Predict_Window *ui;
};

#endif // PREDICT_H
