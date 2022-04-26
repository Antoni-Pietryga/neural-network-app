#ifndef UI_STATS_WINDOW_H
#define UI_STATS_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Stats_Window
{
public:
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *Stats_Window)
    {
        if (Stats_Window->objectName().isEmpty())
            Stats_Window->setObjectName(QString::fromUtf8("Stats"));
        Stats_Window->resize(800, 600);
        label = new QLabel(Stats_Window);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(210, 20, 341, 101));
        QFont font;
        font.setPointSize(28);
        font.setBold(true);
        label->setFont(font);
        label_2 = new QLabel(Stats_Window);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(150, 140, 481, 361));

        retranslateUi(Stats_Window);

        QMetaObject::connectSlotsByName(Stats_Window);
    } // setupUi

    void retranslateUi(QDialog *Stats_Window)
    {
        Stats_Window->setWindowTitle(QApplication::translate("Stats", "Dialog", nullptr));
        label->setText(QApplication::translate("Stats", "Training results", nullptr));
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Stats_Window: public Ui_Stats_Window{};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATS_H
