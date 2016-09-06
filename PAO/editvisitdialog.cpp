#include "editvisitdialog.h"

#include "addvisitdialog.h"

EditVisitDialog::EditVisitDialog(QWidget* parent , VetControl* vc, AbstractVisit* vte) : QDialog(parent), vetc(vc),editVis(vte){
  if(editVis){
  prepareGUI();
  prepareConnections();
  }
}

void EditVisitDialog::createIDGroupBox(){
  IDGroupBox = new QGroupBox(tr("Codici Identificativi"));
  QFormLayout* IDlayout = new QFormLayout;
  IDlayout->addRow(new QLabel(tr("CF Veterinario:")), cfv_led);
  IDlayout->addRow(new QLabel(tr("ID Animale:")), animalID_led);
  IDGroupBox->setLayout(IDlayout);
}

void EditVisitDialog::createVCGroupBox(){
   VisitCoreGroupBox = new QGroupBox(tr("Info"));
   QFormLayout* VClayout = new QFormLayout;
   VClayout->addRow(new QLabel(tr("Prezzo Base:")), basicPrice_led);
   VClayout->addRow(new QLabel(tr("Data:")), date_ded);
   VClayout->addRow(new QLabel(tr("Note:")), note_led);
   VisitCoreGroupBox->setLayout(VClayout);
}

void EditVisitDialog::createButtonBox(){
  QHBoxLayout *buttonslayout = new QHBoxLayout;

  buttonbox = new QDialogButtonBox;
  buttonbox->addButton(QDialogButtonBox::Save);
  buttonbox->addButton(QDialogButtonBox::Discard);
  buttonbox->button(QDialogButtonBox::Save)->setText("Salva");
  buttonbox->button(QDialogButtonBox::Discard)->setText("Annulla");

  buttonslayout->addWidget(buttonbox);
}

void EditVisitDialog::prepareGUI(){
  cfv_led = new QLineEdit;
  animalID_led = new QLineEdit;
  basicPrice_led = new QLineEdit;
  date_ded = new QDateEdit;
  note_led = new QLineEdit;

  cfv_led->setText(editVis->getIDVet());
  animalID_led->setText(QString::number(editVis->getAnimalID()));
  animalID_led->setReadOnly(true);
  date_ded->setReadOnly(true);
  animalID_led->setEnabled(false);
  date_ded->setEnabled(false);
  basicPrice_led->setText(QString::number(editVis->getBasicPrice()));
  note_led->setText(editVis->getNote());

  createIDGroupBox();
  createVCGroupBox();
  createButtonBox();

  QVBoxLayout* mainLayout = new QVBoxLayout();
  mainLayout->addWidget(IDGroupBox);
  mainLayout->addWidget(VisitCoreGroupBox);
  mainLayout->addWidget(buttonbox);

  setLayout(mainLayout);
  setWindowTitle(tr("Aggiungi nuova visita"));
  setFixedSize(400,500);
}

void EditVisitDialog::prepareConnections(){
  connect(buttonbox->button(QDialogButtonBox::Discard),SIGNAL(clicked()),
          this, SLOT(close()));
  connect(buttonbox->button(QDialogButtonBox::Save),SIGNAL(clicked()),
          this, SLOT(editVisitAndExit()));
}

void EditVisitDialog::editVisitAndExit(){
  QString vID = cfv_led->text();
  QString nt = note_led->text();

  double bp = basicPrice_led->text().toDouble();
  if(bp <20)
    bp = 20;

  vetc->editVisitOnDB(editVis->getVisitCode(),vID,nt,bp);

}
