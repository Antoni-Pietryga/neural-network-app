#ifndef UI_PREDICT_WINDOW_H
#define UI_PREDICT_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_Predict_Window
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *model_button;
    QPushButton *data_button;
    QLabel *label_8;
    QLabel *label_9;
    //QPushButton *data_button_2;
    QLabel *model_dir;
    QLabel *pred_dir;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    //QLabel *res_dir;

    void setupUi(QDialog *Predict_Window)
    {
        if (Predict_Window->objectName().isEmpty())
            Predict_Window->setObjectName(QString::fromUtf8("Predict"));
        Predict_Window->resize(800, 600);
        label = new QLabel(Predict_Window);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(230, 50, 381, 101));
        QFont font;
        font.setPointSize(28);
        font.setBold(true);
        label->setFont(font);
        pushButton = new QPushButton(Predict_Window);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(40, 490, 171, 71));
        pushButton_2 = new QPushButton(Predict_Window);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(580, 490, 171, 71));
        model_button = new QPushButton(Predict_Window);
        model_button->setObjectName(QString::fromUtf8("model_button"));
        model_button->setGeometry(QRect(50, 190, 181, 71));
        data_button = new QPushButton(Predict_Window);
        data_button->setObjectName(QString::fromUtf8("data_button"));
        data_button->setGeometry(QRect(50, 270, 181, 71));
        //data_button_2 = new QPushButton(Predict_Window);
        //data_button_2->setObjectName(QString::fromUtf8("data_button_2"));
        //data_button_2->setGeometry(QRect(50, 350, 181, 71));
        model_dir = new QLabel(Predict_Window);
        model_dir->setObjectName(QString::fromUtf8("model_dir"));
        model_dir->setGeometry(QRect(250, 210, 531, 31));
        model_dir->setText("../net.pt");
        pred_dir = new QLabel(Predict_Window);
        pred_dir->setObjectName(QString::fromUtf8("pred_dir"));
        pred_dir->setGeometry(QRect(250, 290, 531, 31));
        pred_dir->setText("../data/test.csv");
        label_8 = new QLabel(Predict_Window);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(55, 370, 201, 20));
        label_9 = new QLabel(Predict_Window);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(55, 420, 201, 20));
        lineEdit_2 = new QLineEdit(Predict_Window);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(235, 370, 113, 28));
        lineEdit_2->setText("30");
        lineEdit_3 = new QLineEdit(Predict_Window);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(235, 420, 113, 28));
        lineEdit_3->setText("20");
        //res_dir = new QLabel(Predict_Window);
        //res_dir->setObjectName(QString::fromUtf8("res_dir"));
        //res_dir->setGeometry(QRect(250, 370, 531, 31));

        retranslateUi(Predict_Window);
        QObject::connect(pushButton, SIGNAL(clicked()), Predict_Window, SLOT(close()));

        QMetaObject::connectSlotsByName(Predict_Window);
    } // setupUi

    void retranslateUi(QDialog *Predict_Window)
    {
        Predict_Window->setWindowTitle(QApplication::translate("Predict", "Prediction mode", nullptr));
        label->setText(QApplication::translate("Predict", "Prediction mode", nullptr));
        pushButton->setText(QApplication::translate("Predict", "< Back to mode selector", nullptr));
        pushButton_2->setText(QApplication::translate("Predict", "Run prediction >", nullptr));
        model_button->setText(QApplication::translate("Predict", "Model directory", nullptr));
        data_button->setText(QApplication::translate("Predict", "Prediction data directory", nullptr));
        label_8->setText(QApplication::translate("Predict", "Neurons on first layer", nullptr));
        label_9->setText(QApplication::translate("Predict", "Neurons on second layer", nullptr));
        //data_button_2->setText(QApplication::translate("Predict", "Results directory", nullptr));
        //model_dir->setText(QApplication::translate("Predict", "None", nullptr));
        //pred_dir->setText(QApplication::translate("Predict", "None", nullptr));
        //res_dir->setText(QApplication::translate("Predict", "None", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Predict_Window: public Ui_Predict_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREDICT_H
