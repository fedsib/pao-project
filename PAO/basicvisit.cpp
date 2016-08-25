#include "basicvisit.h"

BasicVisit::BasicVisit(){}
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
