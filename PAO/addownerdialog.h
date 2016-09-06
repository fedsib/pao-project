#ifndef ADDOWNERDIALOG_H
#define ADDOWNERDIALOG_H

#include <QDialog>
#include <QRadioButton>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QDialogButtonBox>
//#include <QVBoxLayout>
//#include <QHBoxLayout>
//#include <QFormLayout>

#include "owner.h"
#include "vetcontrol.h"

class VetControl;

class AddOwnerDialog : public QDialog {
  Q_OBJECT
  private:
    QGroupBox* basicInfoGroupBox;
    QGroupBox* contactsGroupBox;
    QGroupBox* accountGroupBox;
    QDialogButtonBox* buttonbox;

    void createBIGroupBox();
    void createCGroupBox();
    void createAGroupBox();
    void createButtonBox();

    void prepareGUI();
    void prepareConnections();

    QLineEdit* cf_le;
    QLineEdit* n_le;
    QLineEdit* sn_le;
    QLineEdit* addr_le;
    QLineEdit* m_le;
    QLineEdit* ph_le;
    QLineEdit* pw_le;
    QRadioButton* vetRB;

    VetControl* vetc;

  public:
    explicit AddOwnerDialog(QWidget* , VetControl*);

  public slots:
    void createOwnerAndExit();
};

#endif // ADDOWNERDIALOG_H
