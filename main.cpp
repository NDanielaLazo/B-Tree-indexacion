#include <QApplication>
#include <QLabel>
#include <QPixmap>
#include <QPushButton>
#include <QGridLayout>
#include <QHBoxLayout> //horizontal box layout
#include <QVBoxLayout> //vertical box layout
#include <QGroupBox> //group radio buttons
#include <QRadioButton>
#include <QSlider>
#include <QSpinBox>
#include <QString>
#include <QLineEdit>
#include <QFontMetrics>
#include "mainwindow.h"
#include "btree.h"
#include <iostream>
#include <stdlib.h> //for rand()

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
