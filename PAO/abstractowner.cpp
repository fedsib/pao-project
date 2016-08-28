#include "abstractowner.h"

AbstractOwner::AbstractOwner(const QJsonObject& js) : fiscalCode(js["CF"].toString()), account(js){}

void AbstractOwner::saveAbsOwner(QJsonObject& js){
   js["CF"] = fiscalCode;
   account.saveUserAccountToFile(js);
}

AbstractOwner::AbstractOwner(){}

AbstractOwner::AbstractOwner(const QString& cf) : fiscalCode(cf){}

QString AbstractOwner::getFiscalCode() const{
  return fiscalCode;
}

UserAccount& AbstractOwner::getUserAccount() const{
  return const_cast<UserAccount&>(this->account);
}


