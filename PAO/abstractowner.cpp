#include "abstractowner.h"

AbstractOwner::AbstractOwner(const QJsonObject& js){

}

void AbstractOwner::saveAbsOwner(QJsonObject&){

}

AbstractOwner::AbstractOwner(){}

AbstractOwner::AbstractOwner(const QString& cf) : fiscalCode(cf){}

QString AbstractOwner::getFiscalCode() const{
  return fiscalCode;
}

