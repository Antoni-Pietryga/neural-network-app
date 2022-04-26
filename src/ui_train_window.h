#ifndef UI_TRAIN_WINDOW_H
#define UI_TRAIN_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Train_Window
{
public:
    QLabel *label;
    QPushButton *data_button;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *pred_dir;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QProgressBar *progressBar;
    QSlider *horizontalSlider;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QTextBrowser *textBrowser;

    void setupUi(QDialog *Train_Window)
    {
        if (Train_Window->objectName().isEmpty())
            Train_Window->setObjectName(QString::fromUtf8("Train"));
        Train_Window->resize(1200, 600);
        label = new QLabel(Train_Window);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(270, 0, 261, 101));
        QFont font;
        font.setPointSize(28);
        font.setBold(true);
        label->setFont(font);
        data_button = new QPushButton(Train_Window);
        data_button->setObjectName(QString::fromUtf8("data_button"));
        data_button->setGeometry(QRect(40, 450, 131, 41));
        pushButton = new QPushButton(Train_Window);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(40, 520, 171, 71));
        pushButton_2 = new QPushButton(Train_Window);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(580, 520, 171, 71));
        pred_dir = new QLabel(Train_Window);
        pred_dir->setObjectName(QString::fromUtf8("pred_dir"));
        pred_dir->setGeometry(QRect(190, 450, 531, 31));
        layoutWidget = new QWidget(Train_Window);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 300, 711, 55));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        progressBar = new QProgressBar(layoutWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(24);

        verticalLayout->addWidget(progressBar);

        horizontalSlider = new QSlider(layoutWidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setCursor(QCursor(Qt::ClosedHandCursor));
        horizontalSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalSlider);

        label_4 = new QLabel(Train_Window);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 230, 381, 41));
        QFont font1;
        font1.setPointSize(12);
        label_4->setFont(font1);
        label_5 = new QLabel(Train_Window);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(40, 400, 201, 20));
        label_6 = new QLabel(Train_Window);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(40, 270, 201, 20));
        label_7 = new QLabel(Train_Window);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(30, 90, 381, 41));
        label_7->setFont(font1);
        label_8 = new QLabel(Train_Window);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(40, 130, 201, 20));
        label_9 = new QLabel(Train_Window);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(40, 170, 201, 20));
        lineEdit = new QLineEdit(Train_Window);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(160, 400, 113, 28));
        lineEdit_2 = new QLineEdit(Train_Window);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(230, 130, 113, 28));
        lineEdit_3 = new QLineEdit(Train_Window);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(230, 170, 113, 28));
        textBrowser = new QTextBrowser(Train_Window);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(780, 50, 411, 541));

        retranslateUi(Train_Window);
        QObject::connect(pushButton, SIGNAL(clicked()), Train_Window, SLOT(close()));
        QObject::connect(progressBar, SIGNAL(valueChanged(int)), horizontalSlider, SLOT(setValue(int)));
        QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), progressBar, SLOT(setValue(int)));

        QMetaObject::connectSlotsByName(Train_Window);
    } // setupUi

    void retranslateUi(QDialog *Train_Window)
    {
        Train_Window->setWindowTitle(QApplication::translate("Train", "Train mode", nullptr));
        label->setText(QApplication::translate("Train", "Train mode", nullptr));
        data_button->setText(QApplication::translate("Train", "Dataset directory", nullptr));
        pushButton->setText(QApplication::translate("Train", "< Back to mode selector", nullptr));
        pushButton_2->setText(QApplication::translate("Train", "Train model >", nullptr));
        pred_dir->setText(QApplication::translate("Train", "None", nullptr));
        label_4->setText(QApplication::translate("Train", "Traning parameters", nullptr));
        label_5->setText(QApplication::translate("Train", "Learning rate:", nullptr));
        label_6->setText(QApplication::translate("Train", "Number of epochs:", nullptr));
        label_7->setText(QApplication::translate("Train", "Network parameters", nullptr));
        label_8->setText(QApplication::translate("Train", "Neurons on first layer", nullptr));
        label_9->setText(QApplication::translate("Train", "Neurons on second layer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Train_Window: public Ui_Train_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAIN_H
