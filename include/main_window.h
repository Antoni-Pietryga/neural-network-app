#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Main_Window; }
QT_END_NAMESPACE
/** @brief The class responsible for displaying
main window, where user could pick app mode: 
- train mode
- predict mode

*/
class Main_Window : public QMainWindow
{
    Q_OBJECT

public:
    Main_Window(QWidget *parent = nullptr);
    ~Main_Window();

private slots:
    /**
    Pick predict mode
    */
    void on_predict_button_clicked();
    /**
    Pick train mode
    */
    void on_train_button_clicked();

private:
    Ui::Main_Window *ui;
};
#endif // TIME_SERIES_TRAINER_PREDICTOR_H
