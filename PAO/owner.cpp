#include "owner.h"

Owner::Owner(){}

Owner::Owner(const UserData& ud) : userInfo(ud) {}

UserData& Owner::getUserInfo() const{
  const_cast<UserData&>(this->userInfo);
}

void Owner::saveObj(QJsonObject& js){
  saveAbsOwner(js);
  userInfo.saveUserDataToFile(js);
}
