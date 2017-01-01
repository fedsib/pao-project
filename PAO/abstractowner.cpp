#include "abstractowner.h"

AbstractOwner::AbstractOwner(const QJsonObject& js) : fiscalCode(js["CF"].toString()), account(new OwnerAccount(js)){}

void AbstractOwner::saveAbsOwner(QJsonObject& js){
   js["CF"] = fiscalCode;
   account->saveOwnerAccountToFile(js);
}

AbstractOwner::AbstractOwner(){}

AbstractOwner::AbstractOwner(const QString& cf) : fiscalCode(cf){}
AbstractOwner::AbstractOwner(const QString& cf, OwnerAccount* uac ) : fiscalCode(cf), account(uac){}

QString AbstractOwner::getFiscalCode() const{
  return fiscalCode;
}

OwnerAccount* AbstractOwner::getOwnerAccount() const{
  return account;
}


