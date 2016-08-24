#include "abstractowner.h"

AbstractOwner::AbstractOwner(){}

AbstractOwner::AbstractOwner(const QString& cf) : fiscalCode(cf){}

QString AbstractOwner::getFiscalCode() const{
  return fiscalCode;
}



