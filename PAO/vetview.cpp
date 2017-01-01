#include "vetview.h"

VetView::VetView(QWidget* parent) : QMainWindow(parent){
  setMinimumSize(1650,700);
  prepareGUI();
  db = new PaoDB();
  db->loadOwners();
  db->loadAnimals();
  db->loadVisits();
  contr = new VetControl(this,db,Base_tb);
  prepareConnections();
}

VetView::~VetView(){
  delete db;
}

void VetView::prepareGUI(){

  setWindowTitle("Amministrazione DB Veterinario");
  fakeView = new QWidget(this);
  exitButton = new QPushButton(tr("Esci"));

  view_combo = new QComboBox;
  Base_tb = new QTableWidget;

  view_combo->addItem("Cerca proprietari");
  view_combo->addItem("Cerca animali");
  view_combo->addItem("Cerca visite");

  createADDGroupBox();
  createCentralGroupBox();
  createOwnerGroupBox();
  createAnimalGroupBox();
  createVisitGroupBox();
  AnimalGroupBox->hide();
  VisitGroupBox->hide();
  prepareOwnerTable();

  QHBoxLayout* wrapper = new QHBoxLayout;

  wrapper->addWidget(addGroupBox);
  wrapper->addWidget(centralGroupBox);
  wrapper->addWidget(OwnerGroupBox);
  wrapper->addWidget(AnimalGroupBox);
  wrapper->addWidget(VisitGroupBox);
  fakeView->setLayout(wrapper);

  setCentralWidget(fakeView);
}

void VetView::prepareConnections(){
  connect(addOwnerButton, SIGNAL(clicked()), contr, SLOT(openAddOwnerDialog()));
  connect(addAnimalButton, SIGNAL(clicked()), contr, SLOT(openAddAnimalDialog()));
  connect(addVisitButton, SIGNAL(clicked()), contr, SLOT(openAddVisitDialog()));

  connect(editOwnerButton, SIGNAL(clicked()), contr, SLOT(openEditOwnerDialog()));
  connect(editAnimalButton, SIGNAL(clicked()), contr, SLOT(openEditAnimalDialog()));
  connect(editVisitButton, SIGNAL(clicked()), contr, SLOT(openEditVisitDialog()));

  connect(view_combo,SIGNAL(currentIndexChanged(int)), this, SLOT(chooseBehaviour(int)));

  connect(removeOwnerButton, SIGNAL(clicked()), contr, SLOT(deleteOwner()));
  connect(removeAnimalButton, SIGNAL(clicked()), contr, SLOT(deleteAnimal()));
  connect(removeVisitButton, SIGNAL(clicked()), contr, SLOT(deleteVisit()));

  connect(exitButton, SIGNAL(clicked()), this, SLOT(saveOnExit()));
}

void VetView::createADDGroupBox(){

  addGroupBox  = new QGroupBox(tr("Aggiungi"));
  addGroupBox->setMaximumWidth(180);

  addOwnerButton = new QPushButton(tr("&Aggiungi Proprietario"));
  addAnimalButton = new QPushButton(tr("&Aggiungi Animale"));
  addVisitButton = new QPushButton(tr("&Aggiungi Visita"));

  QVBoxLayout* Addlayout = new QVBoxLayout;
  Addlayout->addWidget(addOwnerButton);
  Addlayout->addWidget(addAnimalButton);
  Addlayout->addWidget(addVisitButton);
  addGroupBox->setLayout(Addlayout);
}

void VetView::createOwnerGroupBox(){
  OwnerGroupBox  = new QGroupBox(tr("Operazioni su utente"));
  OwnerGroupBox->setMaximumWidth(180);

  QVBoxLayout* Ownerlayout = new QVBoxLayout;

  editOwnerButton = new QPushButton(tr("&Modifica Proprietario"));
  removeOwnerButton = new QPushButton(tr("&Rimuovi Proprietario"));

  Ownerlayout->addWidget(editOwnerButton);
  Ownerlayout->addWidget(removeOwnerButton);
  OwnerGroupBox->setLayout(Ownerlayout);
}

void VetView::createAnimalGroupBox(){
  AnimalGroupBox  = new QGroupBox(tr("Operazioni su animale"));
  AnimalGroupBox->setMaximumWidth(180);
  QVBoxLayout* Animallayout = new QVBoxLayout;

  editAnimalButton = new QPushButton(tr("&Modifica Animale"));
  removeAnimalButton = new QPushButton(tr("&Rimuovi Animale"));

  Animallayout->addWidget(editAnimalButton);
  Animallayout->addWidget(removeAnimalButton);
  AnimalGroupBox->setLayout(Animallayout);
}

void VetView::createVisitGroupBox(){
  VisitGroupBox  = new QGroupBox(tr("Operazioni su visita"));
  VisitGroupBox->setMaximumWidth(180);
  QVBoxLayout* Visitlayout = new QVBoxLayout;

  editVisitButton = new QPushButton(tr("&Modifica Visita"));
  removeVisitButton = new QPushButton(tr("&Rimuovi Visita"));

  Visitlayout->addWidget(editVisitButton);
  Visitlayout->addWidget(removeVisitButton);
  VisitGroupBox->setLayout(Visitlayout);
}

void VetView::createCentralGroupBox(){
  centralGroupBox  = new QGroupBox(tr("Ricerca"));

  QGridLayout* centralGrid = new QGridLayout();

  centralGrid->addWidget(view_combo, 0,0,1,2);
  centralGrid->addWidget(Base_tb, 2,0,7,6);
  centralGrid->addWidget(exitButton, 9, 1, 2, 4);
  centralGroupBox->setLayout(centralGrid);
}

void VetView::showOwnerGroupBox(){
  AnimalGroupBox->hide();
  VisitGroupBox->hide();
  OwnerGroupBox->show();
}

void VetView::showAnimalGroupBox(){
  OwnerGroupBox->hide();
  VisitGroupBox->hide();
  AnimalGroupBox->show();
}

void VetView::showVisitGroupBox(){
  OwnerGroupBox->hide();
  AnimalGroupBox->hide();
  VisitGroupBox->show();
}

void VetView::prepareOwnerTable(){
  QStringList h;
  h << "Codice Fiscale" << "Nome" << "Cognome" << "Indirizzo" << "Mail" << "Telefono";

  Base_tb->setColumnCount(6);
  Base_tb->setHorizontalHeaderLabels(h);
  prepareTable();
}

void VetView::prepareAnimalTable(){
  QStringList h;
  h << "Chip" << "CF Proprietario" << "Nome" << "Data di Nascita" << "Sesso" << "Peso in Kg" << "Razza" << "Tipo" << "Applicazione ID" << "Pelo";

  Base_tb->setColumnCount(10);
  Base_tb->setHorizontalHeaderLabels(h);
  prepareTable();
}

void VetView::prepareVisitTable(){
  QStringList h;
  h << "Codice Visita"<< "Data" << "Tipo" << "CF Veterinario" << "Chip Animale" << "Note" << "Prezzo Base €" << "Costo totale in €";

  Base_tb->setColumnCount(8);
  Base_tb->setHorizontalHeaderLabels(h);
  prepareTable();
}

void VetView::prepareTable(){
  Base_tb->setRowCount(0);
  Base_tb->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
  Base_tb->setSelectionBehavior(QAbstractItemView::SelectRows);
  Base_tb->setEditTriggers(QTableWidget::NoEditTriggers);
}

void VetView::saveOnExit(){
  contr->saveWhenExit();
  close();
}

void VetView::OwnerSearchBehaviour(){
  view_combo->setCurrentIndex(0);
  prepareOwnerTable();
  showOwnerGroupBox();
  contr->showOwnersInTable();
}

void VetView::AnimalSearchBehaviour(){
  view_combo->setCurrentIndex(1);
  prepareAnimalTable();
  showAnimalGroupBox();
  contr->showAnimalsInTable();
}

void VetView::VisitSearchBehaviour(){
  view_combo->setCurrentIndex(2);
  prepareVisitTable();
  showVisitGroupBox();
  contr->showVisitsInTable();
}

//slots

void VetView::chooseBehaviour(int i){
  switch (i) {
    case 0:
      OwnerSearchBehaviour();
      break;
    case 1:
      AnimalSearchBehaviour();
      break;
    case 2:
      VisitSearchBehaviour();
      break;
    default:
      OwnerSearchBehaviour();
      break;
  }
}

