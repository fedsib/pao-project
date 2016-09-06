#include "owner.h"

Owner::Owner(const QString cf) : AbstractOwner(cf){}

Owner::Owner(const QString& cf, UserAccount* uac, UserData* ud) : AbstractOwner(cf,uac) , userInfo(ud) {}

Owner::Owner(const QJsonObject& js) :  AbstractOwner(js){
  userInfo->setName(js["name"].toString());
  userInfo->setSurname(js["surname"].toString());
  userInfo->setContacts(js["address"].toString(),js["mail"].toString(),js["phone"].toString());
}

UserData* Owner::getUserInfo() const{
  return userInfo;
}

QString Owner::typeOfUser() const {
  return "Owner";
}

void Owner::saveObj(QJsonObject& js){
  js["type"] = this->typeOfUser();
  saveAbsOwner(js);
  userInfo->saveUserDataToFile(js);
}
