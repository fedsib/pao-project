#include "basicvisit.h"

BasicVisit::BasicVisit(){}
BasicVisit::BasicVisit(const QJsonObject&js) : AbstractVisit(js){}

double BasicVisit::calcPrice(){
  return basic_price;
}
QString BasicVisit::typeOfVisit() const{
  return "BasicVisit";
}

void BasicVisit::saveObj(QJsonObject& js){
  saveAbsVisit(js);
  js["type"] = this->typeOfVisit();
  js["complete_price"] = this->calcPrice();
}
