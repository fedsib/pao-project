#include "abstractowner.h"

AbstractOwner::AbstractOwner(const QJsonObject& js) : fiscalCode(js["CF"].toString()){
account->setVet(js["isVet"].toBool());
account->setPwdH(js["hash"].toString());
}

void AbstractOwner::saveAbsOwner(QJsonObject& js){
   js["CF"] = fiscalCode;
   account->saveUserAccountToFile(js);
}

AbstractOwner::AbstractOwner(){}

AbstractOwner::AbstractOwner(const QString& cf) : fiscalCode(cf){}
AbstractOwner::AbstractOwner(const QString& cf, UserAccount* uac ) : fiscalCode(cf), account(uac){}

QString AbstractOwner::getFiscalCode() const{
  return fiscalCode;
}

UserAccount* AbstractOwner::getUserAccount() const{
  return account;
}


