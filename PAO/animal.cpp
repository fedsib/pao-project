#include "animal.h"

Animal::Animal(){}
Animal::Animal(const unsigned int id, const AnimalData& data) : animalID(id), animalInfo(data){}

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
  animalInfo = ad; //assegnazione standard di AnimalData
}
