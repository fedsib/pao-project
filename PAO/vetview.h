#ifndef VetView_H
#define VetView_H

//#include <QLabel>
#include <QHeaderView>
#include <QLineEdit>
#include <QTableWidget>
#include <QGridLayout>
//#include <QVBoxLayout>
//#include <QHBoxLayout>
//#include <QPushButton>
#include <QGroupBox>
#include <QStringList>
#include <QMessageBox>
#include <QMainWindow>

#include "paodb.h"
#include "vetcontrol.h"

class VetControl;
class AddOwnerDialog;
class AddAnimalDialog;
class AddVisitDialog;

class VetView : public QMainWindow{
  Q_OBJECT

  private:
    PaoDB* db;
    VetControl* contr;

    QWidget* fakeView;
    QGroupBox* addGroupBox;
    QGroupBox* OwnerGroupBox;
    QGroupBox* AnimalGroupBox;
    QGroupBox* VisitGroupBox;
    QGroupBox* centralGroupBox;

    QPushButton* addOwnerButton;
    QPushButton* addAnimalButton;
    QPushButton* addVisitButton;
    QPushButton* editOwnerButton;
    QPushButton* editAnimalButton;
    QPushButton* editVisitButton;
    QPushButton* removeOwnerButton;
    QPushButton* removeAnimalButton;
    QPushButton* removeVisitButton;
    QPushButton* exitButton;

    QComboBox* search_combo;
    QLineEdit* search_led;
    QDateEdit* search_ded;

    QTableWidget* Base_tb;

    void createADDGroupBox();
    void createOwnerGroupBox();
    void createAnimalGroupBox();
    void createVisitGroupBox();
    void createCentralGroupBox();

    void showOwnerGroupBox();
    void showAnimalGroupBox();
    void showVisitGroupBox();

    void prepareOwnerTable();
    void prepareAnimalTable();
    void prepareVisitTable();

    void OwnerSearchBehaviour();
    void AnimalSearchBehaviour();
    void VisitSearchBehaviour();

    void prepareGUI();
    void prepareConnections();
    void prepareTable();

  protected:
    void showOnOpening(QShowEvent*);

  public:
    explicit VetView(QWidget* = 0);
    ~VetView();

  public slots:
    void chooseBehaviour(int);
    void saveOnExit();
};

#endif // VetView_H
