#include "vaccinevisit.h"

VaccineVisit::VaccineVisit(){}
VaccineVisit::VaccineVisit(const QJsonObject& js) : AbstractVisit(js){}

double VaccineVisit::calcPrice(){
  return (basic_price*2)+(basic_price*2)*0.3;
}
QString VaccineVisit::typeOfVisit() const{
  return "VaccineVisit";
}

void VaccineVisit::saveObj(QJsonObject& js){
  saveAbsVisit(js);
  js["type"] = this->typeOfVisit();
  js["complete_price"] = this->calcPrice();
}
