#ifndef UI_DATASET_WINDOW_H
#define UI_DATASET_WINDOW_H

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
#include <QtWidgets/QComboBox>

QT_BEGIN_NAMESPACE

class Ui_Dataset_Window
{
public:
    QLabel *title_label;
    QLabel *input_size_label;
    QLabel *output_size_label;
    QLabel *shift_label;
    QLabel *dataset_label;
    QLabel *data_directory_label;
    QLabel *column_name_label;

    QPushButton *data_directory_button;
    QPushButton *back_to_mode_selector_button;
    QPushButton *create_dataset_button;

    QLineEdit *input_size_line_edit;
    QLineEdit *output_size_line_edit;
    QLineEdit *shift_line_edit;
    QLineEdit *dataset_name_line_edit;
    
    QComboBox *column_name_combobox;
    /** 
    Create window and put all objects in right places
    */
    void setupUi(QDialog *Dataset_Window)
    {
        if (Dataset_Window->objectName().isEmpty())
            Dataset_Window->setObjectName(QString::fromUtf8("Create dataset"));
        Dataset_Window->resize(800, 600);

        QFont title_font;
        title_font.setPointSize(28);
        title_font.setBold(true);
        
		title_label = new QLabel(Dataset_Window);
        title_label->setObjectName(QString::fromUtf8("title_label"));
        title_label->setGeometry(QRect(270, 0, 261, 101));
		title_label->setFont(title_font);

		dataset_label = new QLabel(Dataset_Window);
        dataset_label->setObjectName(QString::fromUtf8("dataset_label"));
        dataset_label->setGeometry(QRect(40, 80, 201, 20));
        
        dataset_name_line_edit = new QLineEdit(Dataset_Window);
        dataset_name_line_edit->setObjectName(QString::fromUtf8("dataset_name_line_edit"));
        dataset_name_line_edit->setGeometry(QRect(230, 80, 113, 28));
        dataset_name_line_edit->setText("my_dataset");//
        
		input_size_label = new QLabel(Dataset_Window);
        input_size_label->setObjectName(QString::fromUtf8("input_size_label"));
        input_size_label->setGeometry(QRect(40, 130, 201, 20));

		input_size_line_edit = new QLineEdit(Dataset_Window);
        input_size_line_edit->setObjectName(QString::fromUtf8("input_size_line_edit"));
        input_size_line_edit->setGeometry(QRect(230, 130, 113, 28));
        input_size_line_edit->setText("6");
        
		output_size_label = new QLabel(Dataset_Window);
        output_size_label->setObjectName(QString::fromUtf8("output_size_label"));
        output_size_label->setGeometry(QRect(40, 170, 201, 20));
        
		output_size_line_edit = new QLineEdit(Dataset_Window);
        output_size_line_edit->setObjectName(QString::fromUtf8("output_size_line_edit"));
        output_size_line_edit->setGeometry(QRect(230, 170, 113, 28));
        output_size_line_edit->setText("1");
        
        shift_label = new QLabel(Dataset_Window);
        shift_label->setObjectName(QString::fromUtf8("shift_label"));
        shift_label->setGeometry(QRect(40, 210, 201, 20));
        
        shift_line_edit = new QLineEdit(Dataset_Window);
        shift_line_edit->setObjectName(QString::fromUtf8("shift_line_edit"));
        shift_line_edit->setGeometry(QRect(230, 210, 113, 28));
        shift_line_edit->setText("6");//        
        
        data_directory_button = new QPushButton(Dataset_Window);
        data_directory_button->setObjectName(QString::fromUtf8("data_directory_button"));
        data_directory_button->setGeometry(QRect(40, 260, 131, 41));

        data_directory_label = new QLabel(Dataset_Window);
        data_directory_label->setObjectName(QString::fromUtf8("data_directory_label"));
        data_directory_label->setGeometry(QRect(230, 260, 531, 31));
        data_directory_label->setText("../data/jena_climate_2009_2016_norm.csv");        

        column_name_combobox = new QComboBox(Dataset_Window);
        column_name_combobox->setObjectName(QString::fromUtf8("column_name_combobox"));
        column_name_combobox->setGeometry(QRect(230, 350, 150, 31));
        
		column_name_label = new QLabel(Dataset_Window);
        column_name_label->setObjectName(QString::fromUtf8("column_name_label"));
        column_name_label->setGeometry(QRect(40, 350, 201, 31));

        back_to_mode_selector_button = new QPushButton(Dataset_Window);
        back_to_mode_selector_button->setObjectName(QString::fromUtf8("back_to_mode_selector_button"));
        back_to_mode_selector_button->setGeometry(QRect(40, 520, 171, 71));

        create_dataset_button = new QPushButton(Dataset_Window);
        create_dataset_button->setObjectName(QString::fromUtf8("create_dataset_button"));
        create_dataset_button->setGeometry(QRect(580, 520, 171, 71));
        
        retranslateUi(Dataset_Window);
        QObject::connect(back_to_mode_selector_button, SIGNAL(clicked()), Dataset_Window, SLOT(close()));
        
        QMetaObject::connectSlotsByName(Dataset_Window);
    } // setupUi

    void retranslateUi(QDialog *Dataset_Window)
    {
        Dataset_Window->setWindowTitle(QApplication::translate("Dataset", "Create dataset mode", nullptr));
        title_label->setText(QApplication::translate("Dataset", "Create dataset mode", nullptr));
        dataset_label->setText(QApplication::translate("Dataset", "Dataset name", nullptr));
        input_size_label->setText(QApplication::translate("Dataset", "Input size", nullptr));
        output_size_label->setText(QApplication::translate("Dataset", "Output size", nullptr));
        shift_label->setText(QApplication::translate("Dataset", "Shift", nullptr));
		data_directory_button->setText(QApplication::translate("Dataset", "Data directory", nullptr));		
		data_directory_label->setText(QApplication::translate("Dataset", "", nullptr));
        column_name_label->setText(QApplication::translate("Dataset", "Column name", nullptr));
        
        back_to_mode_selector_button->setText(QApplication::translate("Dataset", "< Back to mode selector", nullptr));
        create_dataset_button->setText(QApplication::translate("Dataset", "Create dataset >", nullptr));
        
        
    } // retranslateUi

};

namespace Ui {
    class Dataset_Window: public Ui_Dataset_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATASET_WINDOW_H
