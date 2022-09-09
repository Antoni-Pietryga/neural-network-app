#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <array>
#include <sstream>
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <cstring>
#include <iostream>
#include <iomanip>
#include "train.h"
#include "predict.h"
#include "train_params.h"
#include "main_window.h"

#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QApplication>

using namespace std;

int main(int argc, char *argv[])
{

	QApplication a(argc, argv);
	Main_Window w;
	w.show();
	return a.exec();
}
