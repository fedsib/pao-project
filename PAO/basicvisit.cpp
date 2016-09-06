#include "basicvisit.h"

BasicVisit::BasicVisit(const QDate& dt, const QString& idv, const unsigned int aid, QString no, double bp) : AbstractVisit(dt,idv,aid,no,bp){}
BasicVisit::BasicVisit(const QJsonObject&js) : AbstractVisit(js){}

double BasicVisit::calcPrice() const{
  return basic_price;
}
QString BasicVisit::typeOfVisit() const{
  return "BasicVisit";
}

void BasicVisit::saveObj(QJsonObject& js) const {
  saveAbsVisit(js);
  js["type"] = this->typeOfVisit();
  js["complete_price"] = this->calcPrice();
}
