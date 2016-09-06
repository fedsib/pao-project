#include "vaccinevisit.h"

VaccineVisit::VaccineVisit(const QDate& dt, const QString& idv, const unsigned int aid, QString no, double bp) : AbstractVisit(dt,idv,aid,no,bp){}
VaccineVisit::VaccineVisit(const QJsonObject& js) : AbstractVisit(js){}

double VaccineVisit::calcPrice() const{
  return (basic_price*2)+(basic_price*2)*0.3;
}
QString VaccineVisit::typeOfVisit() const{
  return "VaccineVisit";
}

void VaccineVisit::saveObj(QJsonObject& js) const {
  saveAbsVisit(js);
  js["type"] = this->typeOfVisit();
  js["complete_price"] = this->calcPrice();
}
