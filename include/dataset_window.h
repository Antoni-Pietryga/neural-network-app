#ifndef DATASET_WINDOW_H
#define DATASET_WINDOW_H

#include <QDialog>

namespace Ui {
class Dataset_Window;
}
/** @brief The class responsible for displaying
    train window, choose parameters and start trainig of neural network

*/
class Dataset_Window : public QDialog
{
    Q_OBJECT

public:
    explicit Dataset_Window(QWidget *parent = nullptr);
    ~Dataset_Window();

private slots:
    /**
    Pick training data
    */
    void on_data_directory_button_clicked();
    /**
    	Start model trainig after clicked button
    */
    void on_create_dataset_button_clicked();

private:
    Ui::Dataset_Window *ui;
};

#endif // DATASET_WINDOW_H
