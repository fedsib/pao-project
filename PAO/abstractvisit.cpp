#include "abstractvisit.h"

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
