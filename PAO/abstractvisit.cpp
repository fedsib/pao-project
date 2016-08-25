#include "abstractvisit.h"

AbstractVisit::AbstractVisit(const QJsonObject& js) : IDVet(js["IDVet"].toString()), note(js["note"].toString()),
  AnimalID(static_cast<unsigned int>(js["animalID"].toInt())), basic_price(js["basic_price"].toDouble()){
  this->setDate(QDateTime::fromString(js["date"].toString(), "'M'M'd'd'y'yyhh:mm:ss"));
}

AbstractVisit::AbstractVisit() : basic_price(20) {}

AbstractVisit::AbstractVisit(const QDateTime& dt, const QString& ID, const QString& n, unsigned int aID, double bp) : date(dt), AnimalID(aID),
                                                                                                  IDVet(ID), basic_price(bp),note(n) {}

QDateTime AbstractVisit::getDate() const{
  return date;
}

QString AbstractVisit::getIDVet() const{
  return IDVet;
}

unsigned int AbstractVisit::getAnimalID() const{
  return AnimalID;
}

void AbstractVisit::setDate(const QDateTime& dt){
  date = dt;
}

void AbstractVisit::setIDVet(const QString& ID){
  IDVet = ID;
}

void AbstractVisit::setAnimalID(const unsigned int aID){
  AnimalID = aID;
}

void AbstractVisit::saveAbsVisit(QJsonObject& js) const{
  js["date"] = date.toString("'M'M'd'd'y'yyhh:mm:ss");
  js["IDVet"] = IDVet;
  js["note"] = note;
  js["animalID"] = static_cast<int>(AnimalID);
  js["basic_price"] = basic_price;
}
