#ifndef EDITVISITDIALOG_H
#define EDITVISITDIALOG_H

#include <QDialog>
//#include <QGroupBox>
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

class EditVisitDialog : public QDialog {
  Q_OBJECT

  private:
    VetControl* vetc;
    AbstractVisit* editVis;

    QGroupBox* IDGroupBox;
    QGroupBox* VisitCoreGroupBox;
    QDialogButtonBox* buttonbox;

    QLineEdit* cfv_led;
    QLineEdit* animalID_led;
    QLineEdit* basicPrice_led;
    QDateEdit* date_ded;
    QLineEdit* note_led;    //maybe a QTextEdit?

    void createIDGroupBox();
    void createVCGroupBox();
    void createButtonBox();

    void prepareGUI();
    void prepareConnections();

  public:
    explicit EditVisitDialog(QWidget* , VetControl*, AbstractVisit*);

  public slots:
    void editVisitAndExit();
};

#endif // EDITVISITDIALOG_H
