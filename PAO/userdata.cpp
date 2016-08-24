#include "userdata.h"

UserData::UserData(){}

UserData::UserData(const QString& n, const QString& s, const ContactInfo& ci) : name(n), surname(s), contacts(ci){}

UserData::UserData(const QJsonObject& js) : name(js["name"].toString()), surname(js["surname"].toString()){
  contacts.setAddress(js["address"].toString());
  contacts.setMail(js["mail"].toString());
  contacts.setPhone(js["phone"].toString());
}

QString UserData::getName() const{
  return name;
}

QString UserData::getSurname() const{
  return surname;
}

ContactInfo UserData::getContacts() const{
  return contacts;
}

void UserData::setName(const QString& n){
  name = n;
}

void UserData::setSurname(const QString& s){
  surname = s;
}

void UserData::setContacts(const ContactInfo& ci){
  contacts = ci;
}

void UserData::saveUserDataToFile(QJsonObject& js){
  js["name"] = name;
  js["surname"] = surname;
  this->contacts.ContactInfo::saveContactToFile(js);
}
