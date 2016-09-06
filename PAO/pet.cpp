#include "pet.h"

Pet::Pet(const QString& oID, const unsigned int aID) : Animal(oID,aID){}

Pet::Pet(const QString& oID, const unsigned int aID, const AnimalData& aData) : Animal(oID,aID,aData) {}

Pet::Pet(const QString& oID, const unsigned int aID, const AnimalData& aData, const QString& b,
         const QString& f, const QString& c) : Animal(oID,aID,aData), breed(b), fur(f), category(c) {}

Pet::Pet(const QJsonObject& js) : Animal(js), breed(js["breed"].toString()), fur(js["fur"].toString()), category(js["category"].toString()){}

QString Pet::getBreed() const{
  return breed;
}

QString Pet::getFur() const{
  return fur;
}

QString Pet::getCategory() const{
  return category;
}

void Pet::setBreed(const QString& b){
 breed = b;
}

void Pet::setFur(const QString& f){
  fur = f;
}

void Pet::setCategory(const QString& c){
  category = c;
}

QString Pet::typeOfAnimal() const{
  return "Pet";
}

void Pet::saveObj(QJsonObject& js){
  saveAbsAnimal(js);
  js["type"] = this->typeOfAnimal();
  js["breed"] = breed;
  js["fur"] = fur;
  js["category"] = category;
}
