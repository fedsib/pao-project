#ifndef ADDVISITDIALOG_H
#define ADDVISITDIALOG_H

//#include <QDialog>
//#include <QGroupBox>
#include <QRadioButton>
#include <QLabel>
//#include <QLineEdit>
#include <QPushButton>
//#include <QDialogButtonBox>
//#include <QVBoxLayout>
//#include <QHBoxLayout>
//#include <QFormLayout>

#include "basicvisit.h"
#include "specializedvisit.h"
#include "vaccinevisit.h"
#include "vetcontrol.h"

class AddVisitDialog : public QDialog {
  Q_OBJECT

  private:
    VetControl* vetc;

    QGroupBox* IDGroupBox;
    QGroupBox* VisitCoreGroupBox;
    QGroupBox* RBGroupBox;
    QDialogButtonBox* buttonbox;

    QLineEdit* cfv_led;
    QLineEdit* animalID_led;
    QLineEdit* basicPrice_led;
    QDateEdit* date_ded;
    QLineEdit* note_led;    //maybe a QTextEdit?

    QRadioButton* basicRB;
    QRadioButton* vaccineRB;
    QRadioButton* specializedRB;

    void createIDGroupBox();
    void createVCGroupBox();
    void createRBGroupBox();
    void createButtonBox();

    void prepareGUI();
    void prepareConnections();

  public:
    explicit AddVisitDialog(QWidget* , VetControl*);

  public slots:
    void createVisitAndExit();
};

#endif // ADDVISITDIALOG_H
