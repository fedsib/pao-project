#include "animal.h"

Animal::Animal(){}
Animal::Animal(const unsigned int, const AnimalData data, const PaoContainer&){} //TODO

unsigned int Animal::getAnimalID() const{
  return animalID;
}

QString Animal::getName() const{
  return animalInfo.getName();
}

QString Animal::getSize() const{
  return animalInfo.getSize();
}

QDate Animal::getDateOfBirth() const{
  return animalInfo.getDateofBirth();
}

QDate Animal::getLastMovement() const{
  return animalInfo.LastMovement();
}

QString Animal::getSex() const{
    return animalInfo.sex();
}

QDate Animal::getIDApplication() const{
    return animalInfo.IDApplication();
}

unsigned short int Animal::getWeight() const{
    return animalInfo.getWeight();
}

void Animal::setName(const QString& n){
  animalInfo.setName(n);
}

void Animal::setSize(const QString& s){
  animalInfo.setSize(s);
}

void Animal::setDateOfBirth(const QDate& dob){
  animalInfo.setDateOfBirth();
}

void Animal::setLastMovement(const QDate& lm){
  animalInfo.setLastMovement();
}

void Animal::setSex(const QString& s){
  animalInfo.setSex();
}

void Animal::setIDApplication(const QDate& ID){
  animalInfo.setIDApplication();
}

void Animal::setWeight(unsigned short int w){
  animalInfo.setWeight();
}
