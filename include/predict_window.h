#ifndef PREDICT_WINDOW_H
#define PREDICT_WINDOW_H

#include <QDialog>

namespace Ui {
class Predict_Window;
}
/** @brief The class responsible for start model prediction
*/
class Predict_Window : public QDialog
{
    Q_OBJECT

public:
    explicit Predict_Window(QWidget *parent = nullptr);
    ~Predict_Window();

private slots:
    /** Method let user pick directory of neural network model
    */
    void on_model_button_clicked();
    /** Method let user pick directory of test data
    */
    void on_data_button_clicked();
    /** Method runs prediction
    */
    void on_predict_button_clicked();
    
    /** Method let user pick directory of csv test file
    */
    void on_test_button_clicked();

private:
    
    Ui::Predict_Window *ui;
	void log_message(std::string message);
};

#endif // PREDICT_WINDOW_H
