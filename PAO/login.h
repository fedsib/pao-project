#ifndef LOGIN_H
#define LOGIN_H

#include <QLabel>
#include <QPushButton>
#include <QDialog>
#include <QDialogButtonBox>
#include <QLineEdit>
#include <QComboBox>
#include <QStringList>
#include <QGridLayout>
#include <QDebug>

//#include<PaoUserController.h>
//#include "vetController.h"
#include "paodb.h"


class login : public QDialog{
  private:
    QLabel* fiscode_label;
    QLabel* pwd_label;
    QLabel* type_label;

    QLineEdit* insertLine_fiscode;
    QLineEdit* insertLine_pwd;

    QComboBox* combox_accounttype;

    QDialogButtonBox* buttonbox;

    //OwnerController ownControl;

    //VetController vetControl;

    void prepareGUI();
    void prepareConnections();

    PaoDB* db;

  public:
    explicit login(QWidget *parent = 0);

   signals:
    void LoginOK(const QString&, const QString&);

public slots:
    void slotLoginOK();
};

#endif // LOGIN_H
