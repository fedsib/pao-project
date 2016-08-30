#include "owner.h"

Owner::Owner(){}

Owner::Owner(const UserData& ud) : userInfo(ud) {}

Owner::Owner(const QJsonObject& js) :  AbstractOwner(js), userInfo(UserData(js)){}

UserData& Owner::getUserInfo() const{
  return const_cast<UserData&>(this->userInfo);
}

QString Owner::typeOfUser() const {
  return "Owner";
}

void Owner::saveObj(QJsonObject& js){
  js["type"] = this->typeOfUser();
  saveAbsOwner(js);
  userInfo.saveUserDataToFile(js);
}
