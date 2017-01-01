#include "abstractvisit.h"

AbstractVisit::AbstractVisit(const QJsonObject& js) : IDVet(js["IDVet"].toString()), note(js["note"].toString()),
  AnimalID(static_cast<unsigned int>(js["animalID"].toInt())), basic_price(js["basic_price"].toDouble()){
  this->setDate(QDate::fromString(js["date"].toString(), "'M'M'd'd'y'yy"));
  setVisitCode();
}

AbstractVisit::AbstractVisit(const QDate& dt, const QString& ID, const unsigned int aID, QString n, double bp) : date(dt), AnimalID(aID),
                             IDVet(ID), basic_price(bp),note(n) {
  setVisitCode();
}

void AbstractVisit::setVisitCode(){
  visitCode = getDate().toString() + QString::number(AnimalID);
}

QString AbstractVisit::getVisitCode() const{
  return visitCode;
}

QDate AbstractVisit::getDate() const{
  return date;
}

QString AbstractVisit::getIDVet() const{
  return IDVet;
}

unsigned int AbstractVisit::getAnimalID() const{
  return AnimalID;
}

QString AbstractVisit::getNote() const{
  return note;
}

double AbstractVisit::getBasicPrice() const{
  return basic_price;
}

void AbstractVisit::editAbsVisit(QString vi,QString ne,double bprice){
  if (vi != "" && vi != IDVet)
    setIDVet(vi);
  if (ne != note)
    setNote(ne);
  if (bprice != basic_price && bprice >=20)
    setBasicPrice(bprice);
}

void AbstractVisit::setNote(QString n){
  note = n;
}

void AbstractVisit::setDate(const QDate& dt){
  date = dt;
}

void AbstractVisit::setIDVet(const QString& ID){
  IDVet = ID;
}

void AbstractVisit::setAnimalID(const unsigned int aID){
  AnimalID = aID;
}

void AbstractVisit::setBasicPrice(double p){
  basic_price = p;
}

void AbstractVisit::saveAbsVisit(QJsonObject& js) const{
  js["date"] = date.toString("'M'M'd'd'y'yy");
  js["IDVet"] = IDVet;
  js["note"] = note;
  js["animalID"] = static_cast<int>(AnimalID);
  js["basic_price"] = basic_price;
}
