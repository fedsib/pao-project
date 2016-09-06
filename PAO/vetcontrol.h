#ifndef VETCONTROL_H
#define VETCONTROL_H

#include <QObject>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include "addownerdialog.h"
#include "addanimaldialog.h"
#include "addvisitdialog.h"
#include "editvisitdialog.h"
#include "paodb.h"
#include "vetview.h"

class AddOwnerDialog;
class AddAnimalDialog;
class AddVisitDialog;
class EditVisitDialog;
class VetView;

class VetControl : public QObject{
  Q_OBJECT

  private:

    VetView* vv;
    PaoDB* db;
    QTableWidget* tbl;
    QComboBox* s_combo;
    QLineEdit* s_led;
    QDateEdit* s_ded;
    AddOwnerDialog* addOwnerDialog;
    AddAnimalDialog* addAnimalDialog;
    AddVisitDialog* addVisitDialog;
    EditVisitDialog* editVisitDialog;

    void loadUsers();
    void loadAs();
    void loadVisits();

    void putOwnersOnTable();
    void putAnimalsOnTable();
    void putVisitsOnTable();
    void putInTable(const QStringList& NH);

  public:
    VetControl(VetView*, PaoDB*, QTableWidget*,QComboBox*, QLineEdit*, QDateEdit*);
    void saveWhenExit();
    void showOwnersInTable();
    void showAnimalsInTable();
    void showVisitsInTable();

  public slots:
    void insertOwnerOnDB(Owner*);
    void insertAnimalOnDB(Animal*);
    void insertVisitOnDB(AbstractVisit*);

    void editVisitOnDB(QString,QString,QString,double);

    void deleteOwner();
    void deleteAnimal();
    void deleteVisit();

    void openAddOwnerDialog();
    void openAddAnimalDialog();
    void openAddVisitDialog();

    void openEditOwnerDialog();
    void openEditAnimalDialog();
    void openEditVisitDialog();
};

#endif // VETCONTROL_H
