#include "animal.h"

Animal::Animal(const QString& oID, const unsigned int aid) : ownerID(oID), animalID(aid){
  setAnimalCode();
}

Animal::Animal(const QString& oID, const unsigned int aid, const AnimalData& data) : ownerID(oID), animalID(aid), animalInfo(data){
  setAnimalCode();
}

Animal::Animal(const QJsonObject& js) : ownerID(js["owner"].toString()), animalID(static_cast<unsigned int>(js["animalID"].toInt())){
  animalInfo.setName(js["name"].toString());
  animalInfo.setDateOfBirth(QDate::fromString(js["birth"].toString(),"d'MM'MMcaryyyy"));
  animalInfo.setSex(js["sex"].toString());
  animalInfo.setIDApplication(QDate::fromString(js["IDApplication"].toString(),"d'MM'MMcaryyyy"));
  animalInfo.setWeight(static_cast<unsigned short int>(js["weight"].toInt()));
  setAnimalCode();
}

void Animal::setAnimalCode(){
  animalCode = QString::number(animalID);
}

QString Animal::getAnimalCode() const{
  return animalCode;
}

void Animal::saveAbsAnimal(QJsonObject& js){
  js["owner"] = ownerID;
  js["animalID"] = static_cast<int>(animalID);
  animalInfo.saveAnimalDataToFile(js);
}

QString Animal::getOwnerID() const{
  return ownerID;
}

unsigned int Animal::getAnimalID() const{
  return animalID;
}

AnimalData& Animal::getAnimalData() const{
  return const_cast<AnimalData&>(this->animalInfo);
}

void Animal::setOwnerID(const QString& oid){
  ownerID = oid;
}

void Animal::setAnimalID(const unsigned int aid){
  animalID = aid;
}

void Animal::setAnimalData(const AnimalData& ad){
  animalInfo = ad;
}
