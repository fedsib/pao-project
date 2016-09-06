#include "addanimaldialog.h"

AddAnimalDialog::AddAnimalDialog(QWidget *parent, VetControl* vc): QDialog(parent), vetc(vc){
  prepareGUI();
  prepareConnections();
}

void AddAnimalDialog::createBIGroupBox(){
  basicInfoGroupBox = new QGroupBox(tr("Identificativi"));
  QFormLayout* BIlayout = new QFormLayout;
  BIlayout->addRow(new QLabel(tr("CF Proprietario:")), ownerID_led);
  BIlayout->addRow(new QLabel(tr("AnimalID:")), animalID_led);
  basicInfoGroupBox->setLayout(BIlayout);
}

void AddAnimalDialog::createADGroupBox(){
  animalDataGroupBox = new QGroupBox(tr("Informazioni Generali"));
  QFormLayout* ADlayout = new QFormLayout;
  ADlayout->addRow(new QLabel(tr("Nome:")), name_led);
  ADlayout->addRow(new QLabel(tr("Data di Nascita:")), dateofBirth_ded);
  ADlayout->addRow(new QLabel(tr("Sesso:")), sex_combo);
  ADlayout->addRow(new QLabel(tr("Data Applicazione Chip:")), IDApplication_ded);
  ADlayout->addRow(new QLabel(tr("Peso in Kg:")), weight_led);
  animalDataGroupBox->setLayout(ADlayout);
}

void AddAnimalDialog::createPetGroupBox(){
  petGroupBox = new QGroupBox(tr("Contatti"));
  QFormLayout* petlayout = new QFormLayout;
  petlayout->addRow(new QLabel(tr("Razza:")), breed_led);
  petlayout->addRow(new QLabel(tr("Pelo:")), fur_led);
  petlayout->addRow(new QLabel(tr("Tipo:")), category_combo);
  petGroupBox->setLayout(petlayout);
}

void AddAnimalDialog::createButtonBox(){
  QHBoxLayout *buttonslayout = new QHBoxLayout;

  buttonbox = new QDialogButtonBox;
  buttonbox->addButton(QDialogButtonBox::Save);
  buttonbox->addButton(QDialogButtonBox::Discard);
  buttonbox->button(QDialogButtonBox::Save)->setText("Salva");
  buttonbox->button(QDialogButtonBox::Discard)->setText("Annulla");

  buttonslayout->addWidget(buttonbox);
}

void AddAnimalDialog::prepareGUI(){

  ownerID_led = new QLineEdit;
  animalID_led = new QLineEdit;
  name_led = new QLineEdit;
  dateofBirth_ded = new QDateEdit;
  sex_combo = new QComboBox;
  IDApplication_ded = new QDateEdit;
  weight_led = new QLineEdit;
  breed_led = new QLineEdit;
  fur_led = new QLineEdit;
  category_combo = new QComboBox;

  sex_combo->addItem("Maschio");
  sex_combo->addItem("Femmina");

  category_combo->addItem("Cane");
  category_combo->addItem("Gatto");
  category_combo->addItem("Volatile");
  category_combo->addItem("Altro");

  createBIGroupBox();
  createADGroupBox();
  createPetGroupBox();
  createButtonBox();

  QVBoxLayout* mainLayout = new QVBoxLayout();

  mainLayout->addWidget(basicInfoGroupBox);
  mainLayout->addWidget(animalDataGroupBox);
  mainLayout->addWidget(petGroupBox);
  mainLayout->addWidget(buttonbox);

  setLayout(mainLayout);
  setWindowTitle(tr("Aggiungi nuovo animale"));
  setFixedSize(400,500);
}

void AddAnimalDialog::prepareConnections(){
  connect(buttonbox->button(QDialogButtonBox::Discard),SIGNAL(clicked()),
          this, SLOT(close()));
    connect(buttonbox->button(QDialogButtonBox::Save),SIGNAL(clicked()),
            this, SLOT(createAnimalAndExit()));
}

void AddAnimalDialog::createAnimalAndExit(){
  QString owneID = ownerID_led->text();
  unsigned int anID = static_cast<unsigned int>(animalID_led->text().toInt());
  QString nm = name_led->text();
  QDate dob = dateofBirth_ded->date();
  QString sx = sex_combo->currentText();
  QDate idDate = IDApplication_ded->date();
  unsigned short int w = static_cast<unsigned short int>(weight_led->text().toShort());
  QString br = breed_led->text();
  QString fu = fur_led->text();
  QString atype = category_combo->currentText();

  AnimalData* ad = new AnimalData(nm,dob,sx,idDate,w);

  vetc->insertAnimalOnDB(new Pet(owneID,anID,*ad,br,fu,atype));
}
