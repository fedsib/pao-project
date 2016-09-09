#include "ownerdata.h"

OwnerData::OwnerData(){}

OwnerData::OwnerData(const QString& n, const QString& s, const ContactInfo& ci) : name(n), surname(s), contacts(ci){}

OwnerData::OwnerData(const QJsonObject& js) : name(js["name"].toString()), surname(js["surname"].toString()){
  contacts.setAddress(js["address"].toString());
  contacts.setMail(js["mail"].toString());
  contacts.setPhone(js["phone"].toString());
}

QString OwnerData::getName() const{
  return name;
}

QString OwnerData::getSurname() const{
  return surname;
}

ContactInfo OwnerData::getContacts() const{
  return contacts;
}

void OwnerData::setName(const QString& n){
  name = n;
}

void OwnerData::setSurname(const QString& s){
  surname = s;
}

void OwnerData::setContacts(const QString& a, const QString& m, const QString& p){
  contacts.setAddress(a);
  contacts.setMail(m);
  contacts.setPhone(p);
}

void OwnerData::saveOwnerDataToFile(QJsonObject& js){
  js["name"] = name;
  js["surname"] = surname;
  this->contacts.ContactInfo::saveContactToFile(js);
}
