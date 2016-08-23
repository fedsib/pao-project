#include "userdata.h"

UserData::UserData(){}

UserData::UserData(const QString& n, const QString& s, const ContactInfo& ci) : name(n), surname(s), contacts(ci){}

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

