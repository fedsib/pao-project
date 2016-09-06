#ifndef ADDANIMALDIALOG_H
#define ADDANIMALDIALOG_H

//#include <QDialog>
#include <QDateEdit>
#include <QComboBox>

#include "pet.h"
#include "vetcontrol.h"

class VetControl;
class AddAnimalDialog : public QDialog {
  Q_OBJECT

  private:
    VetControl* vetc;

    QGroupBox* basicInfoGroupBox;
    QGroupBox* animalDataGroupBox;
    QGroupBox* petGroupBox;
    QDialogButtonBox* buttonbox;

    QLineEdit* ownerID_led;
    QLineEdit* animalID_led;

    QLineEdit* name_led;
    QDateEdit* dateofBirth_ded;
    QComboBox* sex_combo;
    QDateEdit* IDApplication_ded;
    QLineEdit* weight_led;

    QLineEdit* breed_led;
    QLineEdit* fur_led;
    QComboBox* category_combo;

    void createBIGroupBox();
    void createADGroupBox();
    void createPetGroupBox();
    void createButtonBox();

    void prepareGUI();
    void prepareConnections();

  public:
    explicit AddAnimalDialog(QWidget*, VetControl*);

  public slots:
    void createAnimalAndExit();
};

#endif // ADDANIMALDIALOG_H
