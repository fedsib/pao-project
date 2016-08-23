#include "abstractvisit.h"

AbstractVisit::AbstractVisit(){}

AbstractVisit::AbstractVisit(const QDateTime& dt, const QString& ID, unsigned int aID) : date(dt), AnimalID(aID), IDVet(ID){}

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
