#include "paodb.h"

//PaoDB() : visits(new PaoContainer()){}

void PaoDB::readUsers(const QJsonObject& js){
  QJsonArray UserArray = js["Users"].toArray();

   int size = UserArray.size();

   for (int i = 0; i < size; i++){
     QJsonObject user_js = UserArray[i].toObject();
     if(user_js["type"].toString() == "Owner")
       insertUser(new Owner(user_js));
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

void PaoDB::writeUsers(QJsonObject& js) const{
  QJsonArray jsonUsers;

  QMap<QString, AbstractOwner*>::const_iterator itUsers;

  for (itUsers = users.constBegin(); itUsers != users.constEnd(); ++itUsers){
    QJsonObject userObj;

    (*itUsers)->saveObj(userObj);
    jsonUsers.append(userObj);
  }
  js["Users"] = jsonUsers;
}

void PaoDB::writeAnimals(QJsonObject& js) const{
  QJsonArray jsonAnimals;

  QMap<unsigned int, Animal*>::const_iterator itAnimals;

  for (itAnimals = animals.constBegin(); itAnimals != animals.constEnd(); ++itAnimals){
      QJsonObject animalObj;

      (*itAnimals)->saveObj(animalObj);
      jsonAnimals.append(animalObj);
    }
    js["Animals"] = jsonAnimals;
}

void PaoDB::writeVisits(QJsonObject& js) const{
  QJsonArray jsonVisits;

  for (PaoContainer::const_iterator itVisits = visits.const_begin(); itVisits != visits.const_end(); itVisits++){
    QJsonObject visitObj;

    itVisits->saveObj(visitObj);
    jsonVisits.append(visitObj);
  }
  js["Visits"] = jsonVisits;
}

bool PaoDB::saveUsers(){
  QFile userDB("users.json");

  if (!userDB.open(QIODevice::WriteOnly)){
    qWarning("Couldn't open userDB file.");
    return false;
  }

  QJsonObject userjs;
  writeUsers(userjs);
  QJsonDocument docSaveUsers(userjs);
  userDB.write(docSaveUsers.toJson());
  return true;
}

bool PaoDB::loadUsers(){
  QFile userDB("users.json");
  if (!userDB.open(QIODevice::ReadOnly))
    return false;

  QByteArray us_data = userDB.readAll();
  QJsonDocument docLoadUsers(QJsonDocument::fromJson(us_data));
  QString content = docLoadUsers.toJson(QJsonDocument::Indented);
  readUsers(docLoadUsers.object());
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
    QString content = docLoadanimals.toJson(QJsonDocument::Indented);
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
    QString content = docLoadvisits.toJson(QJsonDocument::Indented);
    readVisits(docLoadvisits.object());
    return true;
}

void PaoDB::insertUser(AbstractOwner* abso){
  users.insert(abso->getFiscalCode(),abso);
}

void PaoDB::insertAnimal(Animal* absa){
  animals.insert(absa->getAnimalID(),absa);
}

void PaoDB::insertVisitFront(AbstractVisit* absv){
  visits.push_front(absv);
}

void PaoDB::insertVisitBack(AbstractVisit* absv){
  visits.push_back(absv);
}

QMap<QString, AbstractOwner*> PaoDB::getUserList() const{
 return users;
}

QMap<unsigned int, Animal*> PaoDB::getAnimalList() const{
  return animals;
}

void PaoDB::removeUser(const QString& userID){
  users.remove(userID);
}

void PaoDB::removeAnimal(const unsigned int aID){
  animals.remove(aID);
}

void PaoDB::removeVisit(const QDateTime& d, const unsigned int aid){
  visits.remove(d,aid);
}
