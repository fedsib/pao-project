#include "specializedvisit.h"

SpecializedVisit::SpecializedVisit(const QDate& dt, const QString& idv, const unsigned int aid, QString no, double bp) : AbstractVisit(dt,idv,aid,no,bp){}
SpecializedVisit::SpecializedVisit(const QJsonObject& js) : AbstractVisit(js){}

double SpecializedVisit::calcPrice() const{
  return (basic_price*2)+(basic_price*2)*0.3;

}
QString SpecializedVisit::typeOfVisit() const{
  return "SpecializedVisit";
}

void SpecializedVisit::saveObj(QJsonObject& js) const {
  saveAbsVisit(js);
  js["type"] = this->typeOfVisit();
  js["complete_price"] = this->calcPrice();
}
