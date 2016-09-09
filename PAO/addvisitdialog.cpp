#include "addvisitdialog.h"

AddVisitDialog::AddVisitDialog(QWidget* parent , VetControl* vc) : QDialog(parent), vetc(vc){
  prepareGUI();
  prepareConnections();
}

void AddVisitDialog::createIDGroupBox(){
  IDGroupBox = new QGroupBox(tr("Codici Identificativi"));
  QFormLayout* IDlayout = new QFormLayout;
  IDlayout->addRow(new QLabel(tr("CF Veterinario:")), cfv_led);
  IDlayout->addRow(new QLabel(tr("ID Animale:")), animalID_led);
  IDGroupBox->setLayout(IDlayout);
}

void AddVisitDialog::createVCGroupBox(){
   VisitCoreGroupBox = new QGroupBox(tr("Info"));
   QFormLayout* VClayout = new QFormLayout;
   VClayout->addRow(new QLabel(tr("Prezzo Base:")), basicPrice_led);
   VClayout->addRow(new QLabel(tr("Data:")), date_ded);
   VClayout->addRow(new QLabel(tr("Note:")), note_led);
   VisitCoreGroupBox->setLayout(VClayout);
}

void AddVisitDialog::createRBGroupBox(){
  RBGroupBox = new QGroupBox(tr("Tipo Visita"));
  QVBoxLayout *vRBbox = new QVBoxLayout;
  vRBbox->addWidget(basicRB);
  vRBbox->addWidget(vaccineRB);
  vRBbox->addWidget(specializedRB);

  basicRB->setChecked(true);

  RBGroupBox->setLayout(vRBbox);
}

void AddVisitDialog::createButtonBox(){
  QHBoxLayout *buttonslayout = new QHBoxLayout;

  buttonbox = new QDialogButtonBox;
  buttonbox->addButton(QDialogButtonBox::Save);
  buttonbox->addButton(QDialogButtonBox::Discard);
  buttonbox->button(QDialogButtonBox::Save)->setText("Salva");
  buttonbox->button(QDialogButtonBox::Discard)->setText("Annulla");

  buttonslayout->addWidget(buttonbox);
}

void AddVisitDialog::prepareGUI(){
  cfv_led = new QLineEdit;
  animalID_led = new QLineEdit;
  basicPrice_led = new QLineEdit;
  date_ded = new QDateEdit;
  note_led = new QLineEdit;

  basicRB = new QRadioButton(tr("&Visita Base"));
  vaccineRB = new QRadioButton(tr("&Vaccino"));
  specializedRB = new QRadioButton(tr("&Visita Specialistica"));

  createIDGroupBox();
  createVCGroupBox();
  createRBGroupBox();
  createButtonBox();

  QVBoxLayout* mainLayout = new QVBoxLayout();
  mainLayout->addWidget(IDGroupBox);
  mainLayout->addWidget(VisitCoreGroupBox);
  mainLayout->addWidget(RBGroupBox);
  mainLayout->addWidget(buttonbox);

  setLayout(mainLayout);
  setWindowTitle(tr("Aggiungi nuova visita"));
  setFixedSize(400,500);
}

void AddVisitDialog::prepareConnections(){
  connect(buttonbox->button(QDialogButtonBox::Discard),SIGNAL(clicked()),
          this, SLOT(close()));
  connect(buttonbox->button(QDialogButtonBox::Save),SIGNAL(clicked()),
          this, SLOT(createVisitAndExit()));
}

void AddVisitDialog::createVisitAndExit(){
  QDate dt = date_ded->date();
  QString vID = cfv_led->text();
  QString nt = note_led->text();
  unsigned int aID = static_cast<unsigned int>(animalID_led->text().toInt());

  double bp = basicPrice_led->text().toDouble();
  if(bp <20)
    bp = 20;

  if(vID == "")
    cfv_led->setStyleSheet("QLineEdit { border : 2px solid red;}");
  else cfv_led->setStyleSheet("QLineEdit { border: 1px solid grey; border-style: inset;}");

  if(animalID_led->text() == "")
    animalID_led->setStyleSheet("QLineEdit { border : 2px solid red;}");
  else animalID_led->setStyleSheet("QLineEdit { border: 1px solid grey; border-style: inset;}");

  if(vID != "" && aID != 0){
    if(basicRB->isChecked()){
      vetc->insertVisitOnDB(new BasicVisit(dt,vID,aID,nt,bp));
    }
    else if(vaccineRB->isChecked()){
      vetc->insertVisitOnDB(new VaccineVisit(dt,vID,aID,nt,bp));
    }
    else {
      vetc->insertVisitOnDB(new SpecializedVisit(dt,vID,aID,nt,bp));
    }
   }
}
