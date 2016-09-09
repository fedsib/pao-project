#include "owner.h"

Owner::Owner(const QString cf) : AbstractOwner(cf){}

Owner::Owner(const QString& cf, OwnerAccount* uac, OwnerData* ud) : AbstractOwner(cf,uac) , ownerInfo(ud) {}

Owner::Owner(const QJsonObject& js) :  AbstractOwner(js), ownerInfo(new OwnerData(js)){}

OwnerData* Owner::getOwnerInfo() const{
  return ownerInfo;
}

QString Owner::typeOfOwner() const {
  return "Owner";
}

void Owner::saveObj(QJsonObject& js){
  js["type"] = this->typeOfOwner();
  saveAbsOwner(js);
  ownerInfo->saveOwnerDataToFile(js);
}
