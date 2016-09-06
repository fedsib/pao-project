#include "addownerdialog.h"

AddOwnerDialog::AddOwnerDialog(QWidget *parent, VetControl* vc) : QDialog(parent), vetc(vc){
  prepareGUI();
  prepareConnections();
}


void AddOwnerDialog::createButtonBox(){
  QHBoxLayout *buttonslayout = new QHBoxLayout;

  buttonbox = new QDialogButtonBox;
  buttonbox->addButton(QDialogButtonBox::Save);
  buttonbox->addButton(QDialogButtonBox::Discard);
  buttonbox->button(QDialogButtonBox::Save)->setText("Salva");
  buttonbox->button(QDialogButtonBox::Discard)->setText("Annulla");

  buttonslayout->addWidget(buttonbox);
}

void AddOwnerDialog::createBIGroupBox(){
     basicInfoGroupBox = new QGroupBox(tr("Infomazioni Generali"));
     QFormLayout* BIlayout = new QFormLayout;
     BIlayout->addRow(new QLabel(tr("Codice Fiscale:")), cf_le);
     BIlayout->addRow(new QLabel(tr("Nome:")), n_le);
     BIlayout->addRow(new QLabel(tr("Cognome:")), sn_le);
     basicInfoGroupBox->setLayout(BIlayout);
 }

 void AddOwnerDialog::createCGroupBox(){
     contactsGroupBox = new QGroupBox(tr("Contatti"));
     QFormLayout* Clayout = new QFormLayout;
     Clayout->addRow(new QLabel(tr("Indirizzo:")), addr_le);
     Clayout->addRow(new QLabel(tr("Mail:")), m_le);
     Clayout->addRow(new QLabel(tr("Telefono:")), ph_le);
     contactsGroupBox->setLayout(Clayout);
 }

 void AddOwnerDialog::createAGroupBox(){
     accountGroupBox = new QGroupBox(tr("Account"));
     QFormLayout* Alayout = new QFormLayout;
     Alayout->addRow(new QLabel(tr("Veterinario:")), vetRB);
     Alayout->addRow(new QLabel(tr("Password:")), pw_le);
     accountGroupBox->setLayout(Alayout);
 }

void AddOwnerDialog::prepareGUI(){

  vetRB = new QRadioButton("Veterinario");
  cf_le = new QLineEdit;
  n_le = new QLineEdit;
  sn_le = new QLineEdit;
  addr_le = new QLineEdit;
  m_le = new QLineEdit;
  ph_le = new QLineEdit;
  pw_le = new QLineEdit;

  createBIGroupBox();
  createCGroupBox();
  createAGroupBox();
  createButtonBox();

  QVBoxLayout* mainLayout = new QVBoxLayout();

  mainLayout->addWidget(basicInfoGroupBox);
  mainLayout->addWidget(contactsGroupBox);
  mainLayout->addWidget(accountGroupBox);
  mainLayout->addWidget(buttonbox);

  setLayout(mainLayout);
  setWindowTitle(tr("Aggiungi nuovo proprietario"));
  setFixedSize(400,500);
}

void AddOwnerDialog::prepareConnections(){
  connect(buttonbox->button(QDialogButtonBox::Discard),SIGNAL(clicked()),
          this, SLOT(close()));
  connect(buttonbox->button(QDialogButtonBox::Save),SIGNAL(clicked()),
          this, SLOT(createOwnerAndExit()));

}

void AddOwnerDialog::createOwnerAndExit(){
QString cod = cf_le->text();
QString nm = n_le->text();
QString sur = sn_le->text();
QString addre = addr_le->text();
QString mai = m_le->text();
QString pho = ph_le->text();
bool isVeter = vetRB->isChecked();
QString pw = pw_le->text();

ContactInfo ci(addre,mai,pho);
vetc->insertOwnerOnDB(new Owner(cod, (new UserAccount(pw,isVeter)), new UserData(nm,sur,ci)));     //may cause dangling pointer
}
