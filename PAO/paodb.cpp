#include "paodb.h"



PaoDB::PaoDB() : visits(new PaoContainer()){

}

void PaoDB::readOwners(const QJsonObject& js){
  QJsonArray OwnerArray = js["Owners"].toArray();

   int size = OwnerArray.size();

   for (int i = 0; i < size; i++){
     QJsonObject owner_js = OwnerArray[i].toObject();
     if(owner_js["type"].toString() == "Owner")
       insertOwner(new Owner(owner_js));
   }
}

void PaoDB::readAnimals(const QJsonObject& js){
  QJsonArray AnimalArray = js["Animals"].toArray();

  int size = AnimalArray.size();

  for (int i = 0; i < size; i++){
    QJsonObject animal_js = AnimalArray[i].toObject();

    if(animal_js["type"].toString() == "Pet")
      insertAnimal(new Pet(animal_js));
  }
}

AbstractVisit* PaoDB::obtainVisit(int i){
  for (PaoContainer::iterator it = visits->begin(); it != visits->end() && i >=0; it++, i--)
    if (i == 0)
      return (*(visits))[it];
}

void PaoDB::readVisits(const QJsonObject& js){

  QJsonArray VisitArray = js["Visits"].toArray();

  int size = VisitArray.size();

  for (int i = 0; i < size; i++){

    QJsonObject visit_js = VisitArray[i].toObject();

    if(visit_js["type"].toString() == "BasicVisit")
      insertVisitBack(new BasicVisit(visit_js));

    else if(visit_js["type"].toString() == "VaccineVisit")
      insertVisitBack(new VaccineVisit(visit_js));

    else
      insertVisitBack(new SpecializedVisit(visit_js));
  }
}

void PaoDB::writeOwners(QJsonObject& js) const{
  QJsonArray jsonOwners;

  QMap<QString, AbstractOwner*>::const_iterator itOwners;

  for (itOwners = owners.constBegin(); itOwners != owners.constEnd(); ++itOwners){
    QJsonObject ownerObj;

    (*itOwners)->saveObj(ownerObj);
    jsonOwners.append(ownerObj);
  }
  js["Owners"] = jsonOwners;
}

void PaoDB::writeAnimals(QJsonObject& js) const{
  QJsonArray jsonAnimals;

  QMap<QString, Animal*>::const_iterator itAnimals;

  for (itAnimals = animals.constBegin(); itAnimals != animals.constEnd(); ++itAnimals){
      QJsonObject animalObj;

      (*itAnimals)->saveObj(animalObj);
      jsonAnimals.append(animalObj);
    }
    js["Animals"] = jsonAnimals;
}

void PaoDB::writeVisits(QJsonObject& js) const{
  QJsonArray jsonVisits;

  for (PaoContainer::const_iterator itVisits = visits->const_begin(); itVisits != visits->const_end(); itVisits++){
    QJsonObject visitObj;

    itVisits->saveObj(visitObj);
    jsonVisits.append(visitObj);
  }
  js["Visits"] = jsonVisits;
}

bool PaoDB::saveOwners(){
  QFile ownerDB("owners.json");

  if (!ownerDB.open(QIODevice::WriteOnly)){
    qWarning("Couldn't open ownerDB file.");
    return false;
  }

  QJsonObject ownerjs;
  writeOwners(ownerjs);
  QJsonDocument docSaveOwners(ownerjs);
  ownerDB.write(docSaveOwners.toJson());
  return true;
}

bool PaoDB::loadOwners(){
  QFile ownerDB("owners.json");
  if (!ownerDB.open(QIODevice::ReadOnly))
    return false;

  QByteArray us_data = ownerDB.readAll();
  QJsonDocument docLoadOwners(QJsonDocument::fromJson(us_data));
  readOwners(docLoadOwners.object());
  return true;
}

bool PaoDB::saveAnimals(){
  QFile animalDB("animals.json");

    if (!animalDB.open(QIODevice::WriteOnly)){
      qWarning("Couldn't open animalDB file.");
      return false;
    }

    QJsonObject animaljs;
    writeAnimals(animaljs);
    QJsonDocument docSaveanimals(animaljs);
    animalDB.write(docSaveanimals.toJson());
    return true;
}

bool PaoDB::loadAnimals(){
  QFile animalDB("animals.json");
    if (!animalDB.open(QIODevice::ReadOnly))
      return false;

    QByteArray an_data = animalDB.readAll();
    QJsonDocument docLoadanimals(QJsonDocument::fromJson(an_data));
    readAnimals(docLoadanimals.object());
    return true;
}

bool PaoDB::saveVisits(){
  QFile visitDB("visits.json");

    if (!visitDB.open(QIODevice::WriteOnly)){
      qWarning("Couldn't open visitDB file.");
      return false;
    }

    QJsonObject visitjs;
    writeVisits(visitjs);
    QJsonDocument docSavevisits(visitjs);
    visitDB.write(docSavevisits.toJson());
    return true;
}

bool PaoDB::loadVisits(){
  QFile visitDB("visits.json");
    if (!visitDB.open(QIODevice::ReadOnly))
      return false;

    QByteArray vs_data = visitDB.readAll();
    QJsonDocument docLoadvisits(QJsonDocument::fromJson(vs_data));
    readVisits(docLoadvisits.object());
    return true;
}

void PaoDB::insertOwner(AbstractOwner* abso){
  QString fC = abso->getFiscalCode();
  owners.insert(fC,abso);
}

void PaoDB::insertAnimal(Animal* absa){
  animals.insert(absa->getAnimalCode(),absa);
}

void PaoDB::insertVisitFront(AbstractVisit* absv){
  visits->push_front(absv);
}

void PaoDB::insertVisitBack(AbstractVisit* absv){
  visits->push_back(absv);
}

QMap<QString, AbstractOwner*> PaoDB::getOwnerList(){
 return owners;
}

QMap<QString, Animal*> PaoDB::getAnimalList() const{
  return animals;
}

PaoContainer* PaoDB::getVisitList() const{
  return visits;
}

bool PaoDB::containVisit(QString k) const{
  return visits->contains(k);
}

void PaoDB::editVisit(const QString visitC, QString cv, QString n, double p){
  bool trovato = false;
  for (PaoContainer::iterator it = visits->begin(); it != visits->end() && !trovato; it++){
    if (it->getVisitCode() == visitC ){
      it->editAbsVisit(cv,n,p);
       trovato = true;
     }
   }
}

void PaoDB::removeOwner(const QString& ownerID){
  owners.remove(ownerID);
}

void PaoDB::removeAnimal(QString aID){
  animals.remove(aID);
}

void PaoDB::removeVisit(QString vtr){
  visits->remove(vtr);
}
