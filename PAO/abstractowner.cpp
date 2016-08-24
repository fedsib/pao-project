#include "abstractowner.h"

AbstractOwner::AbstractOwner(const QJsonObject& js) : fiscalCode(js["CF"].toString()){}

void AbstractOwner::saveAbsOwner(QJsonObject& js){
   js["CF"] = fiscalCode;
}

AbstractOwner::AbstractOwner(){}

AbstractOwner::AbstractOwner(const QString& cf) : fiscalCode(cf){}

QString AbstractOwner::getFiscalCode() const{
  return fiscalCode;
}

