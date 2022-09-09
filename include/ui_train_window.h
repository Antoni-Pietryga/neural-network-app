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
    QLabel *title_label;
    QLabel *subtitile_label;
    QLabel *lr_label;
    QLabel *epoch_num_label;
    QLabel *dataset_dir_label;
    QLabel *model_name_label;

    QPushButton *dataset_button;
    QPushButton *back_to_selector_mode_button;
    QPushButton *train_button;

    QLineEdit *lr_line_edit;
    QLineEdit *epoch_num_line_edit;
	QLineEdit *model_name_line_edit;

    QTextBrowser *text_browser;
    
    /** 
    Create window and put all objects in right places
    */
    void setupUi(QDialog *Train_Window)
    {
        if (Train_Window->objectName().isEmpty())
            Train_Window->setObjectName(QString::fromUtf8("Train"));
        Train_Window->resize(1200, 600);

        QFont title_font;
        title_font.setPointSize(28);
        title_font.setBold(true);

        title_label = new QLabel(Train_Window);
        title_label->setObjectName(QString::fromUtf8("title_label"));
        title_label->setGeometry(QRect(270, 0, 261, 101));
        title_label->setFont(title_font);

        QFont subtitle_font;
        subtitle_font.setPointSize(12);
        
        subtitile_label = new QLabel(Train_Window);
        subtitile_label->setObjectName(QString::fromUtf8("subtitile_label"));
        subtitile_label->setGeometry(QRect(30, 120, 381, 41));
		subtitile_label->setFont(subtitle_font);

        lr_label = new QLabel(Train_Window);
        lr_label->setObjectName(QString::fromUtf8("lr_label"));
        lr_label->setGeometry(QRect(40, 180, 251, 20));
        
		lr_line_edit = new QLineEdit(Train_Window);
        lr_line_edit->setObjectName(QString::fromUtf8("lr_line_edit"));
        lr_line_edit->setGeometry(QRect(200, 180, 150, 28));
        lr_line_edit->setText("0.0001");        

		epoch_num_label = new QLabel(Train_Window);
        epoch_num_label->setObjectName(QString::fromUtf8("epoch_num_label"));
        epoch_num_label->setGeometry(QRect(40, 230, 251, 20));
        
		epoch_num_line_edit = new QLineEdit(Train_Window);
        epoch_num_line_edit->setObjectName(QString::fromUtf8("epoch_num_line_edit"));
        epoch_num_line_edit->setGeometry(QRect(200, 230, 150, 28));
        epoch_num_line_edit->setText("30");   

		model_name_label = new QLabel(Train_Window);
        model_name_label->setObjectName(QString::fromUtf8("model_name_label"));
        model_name_label->setGeometry(QRect(40, 280, 251, 20));
        
		model_name_line_edit = new QLineEdit(Train_Window);
        model_name_line_edit->setObjectName(QString::fromUtf8("model_name_line_edit"));
        model_name_line_edit->setGeometry(QRect(200, 280, 150, 28));
        model_name_line_edit->setText("my_model_name");  

        dataset_button = new QPushButton(Train_Window);
        dataset_button->setObjectName(QString::fromUtf8("dataset_button"));
        dataset_button->setGeometry(QRect(40, 330, 131, 41));
        
		dataset_dir_label = new QLabel(Train_Window);
        dataset_dir_label->setObjectName(QString::fromUtf8("dataset_dir_label"));
        dataset_dir_label->setGeometry(QRect(190, 330, 531, 31));

        text_browser = new QTextBrowser(Train_Window);
        text_browser->setObjectName(QString::fromUtf8("text_browser"));
        text_browser->setGeometry(QRect(780, 50, 411, 541));

		back_to_selector_mode_button = new QPushButton(Train_Window);
        back_to_selector_mode_button->setObjectName(QString::fromUtf8("back_to_selector_mode_button"));
        back_to_selector_mode_button->setGeometry(QRect(40, 520, 171, 71));
        
		train_button = new QPushButton(Train_Window);
        train_button->setObjectName(QString::fromUtf8("train_button"));
        train_button->setGeometry(QRect(580, 520, 171, 71));
        
        retranslateUi(Train_Window);
        QObject::connect(back_to_selector_mode_button, SIGNAL(clicked()), Train_Window, SLOT(close()));
        
        QMetaObject::connectSlotsByName(Train_Window);
    } // setupUi

    void retranslateUi(QDialog *Train_Window)
    {
        Train_Window->setWindowTitle(QApplication::translate("Train", "Train mode", nullptr));
        title_label->setText(QApplication::translate("Train", "Train mode", nullptr));
        subtitile_label->setText(QApplication::translate("Train", "Traning parameters", nullptr));
        epoch_num_label->setText(QApplication::translate("Train", "Number of epochs:", nullptr));
		model_name_label->setText(QApplication::translate("Train", "Model name:", nullptr));
                
		lr_label->setText(QApplication::translate("Train", "Learning rate:", nullptr));
        dataset_dir_label->setText(QApplication::translate("Train", "../datasets/my_dataset.config", nullptr));
        dataset_button->setText(QApplication::translate("Train", "Dataset directory", nullptr));
		
		back_to_selector_mode_button->setText(QApplication::translate("Train", "< Back to mode selector", nullptr));
        train_button->setText(QApplication::translate("Train", "Train model >", nullptr));
        
    } // retranslateUi
private:
	void log_message(string message);
};

namespace Ui {
    class Train_Window: public Ui_Train_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAIN_WINDOW_H
