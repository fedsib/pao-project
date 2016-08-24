#include "specializedvisit.h"

SpecializedVisit::SpecializedVisit(){}
SpecializedVisit::SpecializedVisit(const QJsonObject& js) : AbstractVisit(js){}

double SpecializedVisit::calcPrice(){
  return (basic_price*2)+(basic_price*2)*0.3;

}
QString SpecializedVisit::typeOfVisit() const{
  return "SpecializedVisit";
}

void SpecializedVisit::saveObj(QJsonObject& js){
  saveAbsVisit(js);
  js["type"] = this->typeOfVisit();
  js["complete_price"] = this->calcPrice();
}
