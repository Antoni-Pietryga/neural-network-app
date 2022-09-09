#include <torch/torch.h>
#include "dataset_window.h"
#include "ui_dataset_window.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <iostream>
#include "dataset.h"
#include <tuple>
#include <vector>

using namespace QtCharts;

vector<string> read_csv(string fname){
  	vector<string> row;
	string line, word;

	fstream file (fname, ios::in);
	if(file.is_open()){
		getline(file, line);
		stringstream str(line);

		while(getline(str, word, ','))
				row.push_back(word);

	}
	else
		cout<<"Could not open the file\n";

	return row;
}

Dataset_Window::Dataset_Window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dataset_Window){
    ui->setupUi(this);
}

Dataset_Window::~Dataset_Window()
{
    delete ui;
}


void Dataset_Window::on_data_directory_button_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "Choose data", "C://");
    ui->data_directory_label->setText(filename);

    vector<string> column_names = read_csv(filename.toStdString());
    ui->column_name_combobox->clear();

    for(auto column_name: column_names)
    	ui->column_name_combobox->addItem(QString::fromStdString(column_name));

}

void Dataset_Window::on_create_dataset_button_clicked(){
	ofstream ConfigFile("../datasets/"+ui->dataset_name_line_edit->text().toStdString()+".config");

  	ConfigFile << ui->input_size_line_edit->text().toStdString()<<endl;
  	ConfigFile << ui->output_size_line_edit->text().toStdString()<<endl;
  	ConfigFile << ui->shift_line_edit->text().toStdString()<<endl;
  	ConfigFile << ui->column_name_combobox->currentText().toStdString()<<endl;
  	ConfigFile << ui->data_directory_label->text().toStdString()<<endl;

  	ConfigFile.close();
    string save_path = "../datasets/"+ui->dataset_name_line_edit->text().toStdString()+".config";
    QMessageBox messageBox;
		QString mess =  QString::fromStdString("Dataset created. Saved config file to  " + save_path);
		messageBox.information(0,"Finished",  mess);
		messageBox.setFixedSize(500,200);

}
