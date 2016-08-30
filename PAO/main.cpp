#include <QApplication>

#include "login.h"

int main(int argc, char *argv[]){
    QApplication pao(argc, argv);

    login log;
    log.show();

    return pao.exec();
}
