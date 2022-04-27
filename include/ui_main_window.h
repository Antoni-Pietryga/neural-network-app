#ifndef UI_MAIN_WINDOW_H
#define UI_MAIN_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Main_Window
{
public:
    QWidget *centralwidget;
    QPushButton *train_button;
    QPushButton *predict_button;
    QLabel *label;
    QLabel *label_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Main_Window)
    {
        if (Main_Window->objectName().isEmpty())
            Main_Window->setObjectName(QString::fromUtf8("Time_Series_Trainer_Predictor"));
        Main_Window->resize(800, 600);
        centralwidget = new QWidget(Main_Window);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        train_button = new QPushButton(centralwidget);
        train_button->setObjectName(QString::fromUtf8("train_button"));
        train_button->setGeometry(QRect(60, 330, 151, 81));
        predict_button = new QPushButton(centralwidget);
        predict_button->setObjectName(QString::fromUtf8("predict_button"));
        predict_button->setGeometry(QRect(590, 330, 151, 81));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(270, 220, 321, 101));
        QFont font;
        font.setPointSize(18);
        label->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(130, 70, 651, 81));
        QFont font1;
        font1.setPointSize(28);
        font1.setBold(true);
        label_2->setFont(font1);
        Main_Window->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Main_Window);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        Main_Window->setMenuBar(menubar);
        statusbar = new QStatusBar(Main_Window);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Main_Window->setStatusBar(statusbar);

        retranslateUi(Main_Window);

        QMetaObject::connectSlotsByName(Main_Window);
    } // setupUi

    void retranslateUi(QMainWindow *Main_Window)
    {
        Main_Window->setWindowTitle(QApplication::translate("Time_Series_Trainer_Predictor", "Time Series Trainer/Predictor", nullptr));
        train_button->setText(QApplication::translate("Time_Series_Trainer_Predictor", "Train", nullptr));
        predict_button->setText(QApplication::translate("Time_Series_Trainer_Predictor", "Predict", nullptr));
        label->setText(QApplication::translate("Time_Series_Trainer_Predictor", "What you want to do ?", nullptr));
        label_2->setText(QApplication::translate("Time_Series_Trainer_Predictor", "Time Series Trainer/Predictor", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Main_Window: public Ui_Main_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
