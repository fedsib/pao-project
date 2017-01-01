//#include "mainwindow.h"
#include "vetview.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication pao(argc, argv);
    VetView w;
    w.show();

    return pao.exec();
}
