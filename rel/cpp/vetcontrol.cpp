#include "vetcontrol.h"

VetControl::VetControl(VetView* parent, PaoDB* pdb, QTableWidget* mainTable) : vv(parent), db(pdb), tbl(mainTable){}

void VetControl::loadOwners(){
  db->loadOwners();
  putOwnersOnTable();
}

void VetControl::loadAs(){
  db->loadAnimals();
  putAnimalsOnTable();
}

void VetControl::loadVisits(){
  db->loadVisits();
  putVisitsOnTable();
}

void VetControl::saveWhenExit(){
  db->saveOwners();
  db->saveAnimals();
  db->saveVisits();
}

void VetControl::showOwnersInTable(){
  tbl->clearContents();
  putOwnersOnTable();
}

void VetControl::showAnimalsInTable(){
  tbl->clearContents();
  putAnimalsOnTable();
}

void VetControl::showVisitsInTable(){
  tbl->clearContents();
  putVisitsOnTable();
}

void VetControl::insertOwnerOnDB(Owner* absoToAdd){
  addOwnerDialog->close();
  delete addOwnerDialog;

  db->insertOwner(absoToAdd);
  vv->chooseBehaviour(0);
}

void VetControl::insertAnimalOnDB(Animal* aToAdd){
  addAnimalDialog->close();
  delete addAnimalDialog;

  db->insertAnimal(aToAdd);
  vv->chooseBehaviour(1);
}

void VetControl::insertVisitOnDB(AbstractVisit* avToAdd){
  addVisitDialog->close();
  delete addVisitDialog;

  db->insertVisitBack(avToAdd);
  vv->chooseBehaviour(2);
}

void VetControl::editVisitOnDB(QString code, QString c,QString n,double p){
  editVisitDialog->close();
  delete editVisitDialog;
  db->editVisit(code, c,n,p);
  vv->chooseBehaviour(2);
}

void VetControl::deleteOwner(){
  QItemSelectionModel* os = tbl->selectionModel();
  if (os->hasSelection()){
    QModelIndexList indexes = os->selectedRows();

    QString ocf = indexes[0].data().toString();
    db->removeOwner(ocf);
  }
  vv->chooseBehaviour(0);
}

void VetControl::deleteAnimal(){
  QItemSelectionModel* as = tbl->selectionModel();
  if (as->hasSelection()){
    QModelIndexList indexes = as->selectedRows();

    QString aiD = indexes[0].data().toString();
    db->removeAnimal(aiD);
  }
  vv->chooseBehaviour(1);
}

void VetControl::deleteVisit(){
  QItemSelectionModel* vs = tbl->selectionModel();
  if (vs->hasSelection()){
    QModelIndexList indexes = vs->selectedRows();

    QString visitCd = indexes[0].data().toString();
    db->removeVisit(visitCd);
  }
  vv->chooseBehaviour(2);
}

void VetControl::openAddOwnerDialog(){
  addOwnerDialog = new AddOwnerDialog(vv,this);
  addOwnerDialog->exec();
}

void VetControl::openAddAnimalDialog(){
  addAnimalDialog = new AddAnimalDialog(vv,this);
  addAnimalDialog->exec();
}

void VetControl::openAddVisitDialog(){
  addVisitDialog = new AddVisitDialog(vv,this);
  addVisitDialog->exec();
}

void VetControl::putOwnersOnTable() {
  QMap<QString, AbstractOwner*> us = db->getOwnerList();
  foreach (AbstractOwner* abso, us){
    Owner *own_ptr = dynamic_cast<Owner*>(abso);
    QString tmpCF = own_ptr->getFiscalCode();
    QString tmpName = own_ptr->getOwnerInfo()->getName();
    QString tmpSur = own_ptr->getOwnerInfo()->getSurname();
    QString tmpAddr = own_ptr->getOwnerInfo()->getContacts().getAddress();
    QString tmpMail = own_ptr->getOwnerInfo()->getContacts().getMail();
    QString tmpPh = own_ptr->getOwnerInfo()->getContacts().getPhone();
    QStringList nh;
    nh << tmpCF << tmpName << tmpSur << tmpAddr << tmpMail << tmpPh;
    putInTable(nh);
  }
    tbl->resizeRowsToContents();
}
void VetControl::putAnimalsOnTable() {
  foreach (Animal* absa, db->getAnimalList()){
          Pet *anim_ptr = dynamic_cast<Pet*>(absa);

          QString tmpAID = anim_ptr->getAnimalCode();
          QString tmpCF = anim_ptr->getOwnerID();
          QString tmpName = anim_ptr->getAnimalData().getName();
          QString tmpDoB = anim_ptr->getAnimalData().getDateOfBirth().toString();
          QString tmpSex = anim_ptr->getAnimalData().getSex();
          QString tmpIDAPP = anim_ptr->getAnimalData().getIDApplication().toString();
          QString tmpW = QString::number(anim_ptr->getAnimalData().getWeight());
          QString tmpBr = anim_ptr->getBreed();
          QString tmpFu = anim_ptr->getFur();
          QString tmpCat= anim_ptr->getCategory();
          QStringList nh;
          nh << tmpAID << tmpCF << tmpName << tmpDoB << tmpSex << tmpW << tmpBr  << tmpCat << tmpIDAPP  <<  tmpFu;
          putInTable(nh);
  }
    tbl->resizeRowsToContents();
}

void VetControl::putVisitsOnTable() {
  PaoContainer* visitsList = db->getVisitList();
  for (PaoContainer::iterator itVisits = visitsList->begin(); itVisits != visitsList->end(); itVisits++){
    AbstractVisit* absv = &(*itVisits);
    QString tmpVCode = absv->getVisitCode();
    QString tmpDate = absv->getDate().toString();
    QString tmpCFVet = absv->getIDVet();
    QString tmpAID = QString::number(absv->getAnimalID());
    QString tmpNote = absv->getNote();
    QString tmpBP = QString::number(absv->getBasicPrice());
    QString tmpType;
    QString tmpFinalPrice;

    BasicVisit* b_ptr = dynamic_cast<BasicVisit*>(absv);
    VaccineVisit* v_ptr = dynamic_cast<VaccineVisit*>(absv);
    SpecializedVisit* sp_ptr = dynamic_cast<SpecializedVisit*>(absv);

    if(b_ptr){
      tmpType = b_ptr->typeOfVisit();
      tmpFinalPrice = QString::number(b_ptr->calcPrice());
    }
    else if(v_ptr){
      tmpType = v_ptr->typeOfVisit();
      tmpFinalPrice = QString::number(v_ptr->calcPrice());
    }
    else if(sp_ptr){
      tmpType = sp_ptr->typeOfVisit();
      tmpFinalPrice = QString::number(sp_ptr->calcPrice());
    }
    else qWarning("Can't convert Visit.");

    QStringList nh;
    nh << tmpVCode << tmpDate << tmpType <<tmpCFVet << tmpAID << tmpNote << tmpBP << tmpFinalPrice;
    putInTable(nh);
    }
  tbl->resizeRowsToContents();
}

void VetControl::putInTable(const QStringList& NH){
  int r = tbl->rowCount();
  tbl->setRowCount(r+1);
  for (int c = 0; c < NH.size(); c++){
    QTableWidgetItem* toPut = new QTableWidgetItem(NH[c]);
    toPut->setTextAlignment(Qt::AlignCenter);
    tbl->setItem(r,c,toPut);
  }
}

void VetControl::openEditVisitDialog(){
  QItemSelectionModel* vs = tbl->selectionModel();
  if (vs->hasSelection()){
    QModelIndexList indexes = vs->selectedRows();
    QString visitCd = indexes[0].data().toString();

    bool trovato = false;
    for (int i = 0; i < db->getVisitList()->size() && !trovato; i++){
      AbstractVisit* vis = db->obtainVisit(i);
      if (vis->getVisitCode() == visitCd){
        editVisitDialog = new EditVisitDialog(vv,this,vis);
        editVisitDialog->show();
        trovato = true;
      }
     }
  }
}

void VetControl::openEditOwnerDialog(){
  QMessageBox msgB;
  msgB.setText("Al momento è possibile modificare i prprietari cliccando su Aggiungi Proprietario, usando lo stesso CF di uno già presente");
  msgB.exec();
}

void VetControl::openEditAnimalDialog(){
  QMessageBox msgBox;
  msgBox.setText("Al momento è possibile modificare gli animali cliccando su Aggiungi Animale, usando lo stesso ID di uno già presente");
  msgBox.exec();
}
