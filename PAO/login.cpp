#include "login.h"

login::login(QWidget *parent) : QDialog(parent), fiscode_label(new QLabel("Codice Fiscale")),pwd_label(new QLabel("Password")), type_label(new QLabel("Accedi come")),
                                insertLine_fiscode(new QLineEdit(this)),insertLine_pwd(new QLineEdit(this)),combox_accounttype(new QComboBox(this)),
                                buttonbox(new QDialogButtonBox(this)), db(new PaoDB()){

    prepareGUI();
    prepareConnections();

    //model->loadData();

    //Panel = new AdminPanel(this,model);
    //userPanel = new UserPanel(this,model);
}

void login::prepareGUI(){

  setWindowTitle("Login");
  setFixedSize(300,150);

  QGridLayout* LoginGrid = new QGridLayout(this);

  combox_accounttype->addItem("Owner");
  combox_accounttype->addItem("Vet");

 // fiscode_label->setBuddy(insertLine_fiscode);
 // pwd_label->setBuddy(insertLine_pwd);

  buttonbox->addButton(QDialogButtonBox::Ok);
  buttonbox->addButton(QDialogButtonBox::Cancel);
  buttonbox->button(QDialogButtonBox::Ok)->setText("Login");
  buttonbox->button(QDialogButtonBox::Cancel)->setText("Quit");

  LoginGrid ->addWidget(fiscode_label, 0,0,1,1);
  LoginGrid ->addWidget(insertLine_fiscode, 0,1,1,1);
  LoginGrid ->addWidget(pwd_label, 1,0,1,1);
  LoginGrid ->addWidget(insertLine_pwd, 1,1,1,1);
  LoginGrid ->addWidget(type_label, 2,0,1,1);
  LoginGrid ->addWidget(combox_accounttype,2,1,1,1);
  LoginGrid ->addWidget(buttonbox, 3, 0, 1, 2);
  setLayout(LoginGrid);

}

void login::prepareConnections(){
  connect(buttonbox->button(QDialogButtonBox::Cancel),SIGNAL(clicked()),
               this, SLOT(close()));
  connect( buttonbox->button(QDialogButtonBox::Ok),SIGNAL(clicked()),
               this,SLOT(slotLoginOK()));
}
