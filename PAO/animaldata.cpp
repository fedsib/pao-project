#include "animaldata.h"

AnimalData::AnimalData(){}

AnimalData::AnimalData(const QString& n, const QDate& dob, const QDate& lm, const QString& s,
                       const QDate& idapp, unsigned short int w) : name(n),
                       dateofBirth(dob), lastMovement(lm), sex(s), IDApplication(idapp), weight(w){}

AnimalData::AnimalData(const QJsonObject& js) : name(js["name"].toString()), sex(js["sex"].toString()),
                      weight(static_cast<unsigned short int>(js["weight"].toInt())) {
  this->setDateOfBirth(QDate::fromString(js["birth"].toString(),"d'MM'MMcaryyyy"));
  this->setLastMovement(QDate::fromString(js["last_movement"].toString(),"d'MM'MMcaryyyy"));
  this->setIDApplication(QDate::fromString(js["IDApplication"].toString(),"d'MM'MMcaryyyy"));
}

QString AnimalData::getName() const{
  return name;
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

void AnimalData::saveAnimalDataToFile(QJsonObject& js){
  js["name"] = name;
  js["birth"] = dateofBirth.toString("d'MM'MMcaryyyy");
  js["last_movement"] = lastMovement.toString("d'MM'MMcaryyyy");
  js["sex"] = sex;
  js["IDApplication"] = IDApplication.toString("d'MM'MMcaryyyy");
  js["weight"] = weight;
}
