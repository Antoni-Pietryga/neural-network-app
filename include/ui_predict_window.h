#ifndef UI_PREDICT_WINDOW_H
#define UI_PREDICT_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_Predict_Window
{
public:
    QLabel *label;
    QPushButton *back_button;
    QPushButton *predict_button;
    QPushButton *model_button;
    QPushButton *data_button;
    QPushButton *test_button;
    
    QTextBrowser *text_browser;
    QLabel *model_dir;
    QLabel *pred_dir;
    QLabel *test_dir;
    
    /** 
    Create window and put all objects in right places
    */
    void setupUi(QDialog *Predict_Window)
    {
        if (Predict_Window->objectName().isEmpty())
            Predict_Window->setObjectName(QString::fromUtf8("Predict"));
        Predict_Window->resize(1200, 600);
        label = new QLabel(Predict_Window);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(230, 50, 381, 101));
        QFont font;
        font.setPointSize(28);
        font.setBold(true);
        label->setFont(font);
        back_button = new QPushButton(Predict_Window);
        back_button->setObjectName(QString::fromUtf8("back_button"));
        back_button->setGeometry(QRect(40, 490, 171, 71));
        
        predict_button = new QPushButton(Predict_Window);
        predict_button->setObjectName(QString::fromUtf8("predict_button"));
        predict_button->setGeometry(QRect(580, 490, 171, 71));
        
        model_button = new QPushButton(Predict_Window);
        model_button->setObjectName(QString::fromUtf8("model_button"));
        model_button->setGeometry(QRect(50, 190, 181, 71));
        
        data_button = new QPushButton(Predict_Window);
        data_button->setObjectName(QString::fromUtf8("data_button"));
        data_button->setGeometry(QRect(50, 270, 181, 71));
        
        test_button = new QPushButton(Predict_Window);
        test_button->setObjectName(QString::fromUtf8("test_button"));
        test_button->setGeometry(QRect(50, 350, 181, 71));
        
        text_browser = new QTextBrowser(Predict_Window);
        text_browser->setObjectName(QString::fromUtf8("text_browser"));
        text_browser->setGeometry(QRect(780, 50, 411, 541));
        
        model_dir = new QLabel(Predict_Window);
        model_dir->setObjectName(QString::fromUtf8("model_dir"));
        model_dir->setGeometry(QRect(250, 210, 531, 31));
        model_dir->setText("../my_model_name");
        
        pred_dir = new QLabel(Predict_Window);
        pred_dir->setObjectName(QString::fromUtf8("pred_dir"));
        pred_dir->setGeometry(QRect(250, 290, 531, 31));
        pred_dir->setText("../datasets/my_dataset.config");
        
        test_dir = new QLabel(Predict_Window);
        test_dir->setObjectName(QString::fromUtf8("test_dir"));
        test_dir->setGeometry(QRect(250, 370, 531, 31));
        test_dir->setText("../data/test.csv");
       
        retranslateUi(Predict_Window);
        QObject::connect(back_button, SIGNAL(clicked()), Predict_Window, SLOT(close()));

        QMetaObject::connectSlotsByName(Predict_Window);
    } // setupUi

    void retranslateUi(QDialog *Predict_Window)
    {
        Predict_Window->setWindowTitle(QApplication::translate("Predict", "Prediction mode", nullptr));
        label->setText(QApplication::translate("Predict", "Prediction mode", nullptr));
        back_button->setText(QApplication::translate("Predict", "< Back to mode selector", nullptr));
        predict_button->setText(QApplication::translate("Predict", "Run prediction >", nullptr));
        model_button->setText(QApplication::translate("Predict", "Model directory", nullptr));
        data_button->setText(QApplication::translate("Predict", "Prediction config directory", nullptr));
        test_button->setText(QApplication::translate("Predict", "Test csv directory", nullptr));
                
    } // retranslateUi

};

namespace Ui {
    class Predict_Window: public Ui_Predict_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREDICT_WINDOW_H
