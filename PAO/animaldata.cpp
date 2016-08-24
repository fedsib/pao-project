#include "animaldata.h"

AnimalData::AnimalData(){}

AnimalData::AnimalData(const QString& n, const QString& sz, const QDate& dob, const QDate& lm,
        const QString& s, const QDate& idapp, unsigned short int w) : name(n),
        dateofBirth(dob), lastMovement(lm), sex(s), IDApplication(idapp), weight(w){}

QString AnimalData::getName() const{
  return name;
}

QString AnimalData::getSize() const{
  return size;
}

QDate AnimalData::getDateOfBirth() const{
  return dateofBirth;
}

QDate AnimalData::getLastMovement() const{
  return lastMovement;
}

QString AnimalData::getSex() const{
  return sex;
}

QDate AnimalData::getIDApplication() const{
  return IDApplication;
}

unsigned short int AnimalData::getWeight() const{
    return weight;
}

void AnimalData::setName(const QString& n){
  name = n;
}

void AnimalData::setSize(const QString& s){
  size = s;
}

void AnimalData::setDateOfBirth(const QDate& dob){
  dateofBirth = dob;
}

void AnimalData::setLastMovement(const QDate& lm){
  lastMovement = lm;
}

void AnimalData::setSex(const QString& sx){
  sex = sx;
}

void AnimalData::setIDApplication(const QDate& ida){
  IDApplication = ida;
}

void AnimalData::setWeight(unsigned short int g){
  weight = g;
}
