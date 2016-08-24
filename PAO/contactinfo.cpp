#include "contactinfo.h"

ContactInfo::ContactInfo(QString addr, QString ml, QString ph) : address(addr), mail(ml), phone(ph){}

ContactInfo::ContactInfo(const QJsonObject& js): address(js["address"].toString()), mail(js["mail"].toString()),
                                    phone(js["phone"].toString()){}

QString ContactInfo::getAddress() const{
  return address;
}

QString ContactInfo::getMail() const{
  return mail;
}

QString ContactInfo::getPhone() const{
  return phone;
}

void ContactInfo::setAddress(const QString& addr){
  address = addr;
};

void ContactInfo::setMail(const QString& ml){
  mail= ml;
};

void ContactInfo::setPhone(const QString& ph){
 phone = ph;
}

void ContactInfo::saveContactToFile(QJsonObject& js){
  js["address"] = address;
  js["mail"] = mail;
  js["phone"] = phone;
}
