#ifndef USERDATA_H
#define USERDATA_H

#include<QDate>

#include"contactinfo.h"

/*Describe the basic data of a PAO owner*/

class OwnerData{
  private:
    QString name;
    QString surname;
    ContactInfo contacts;

  public:
    OwnerData();
    OwnerData(const QString&, const QString&, const ContactInfo&);
    OwnerData(const QJsonObject&);

    QString getName() const;
    QString getSurname() const;
    ContactInfo getContacts() const;

    void setName(const QString&);
    void setSurname(const QString&);
    void setContacts(const QString&, const QString&, const QString&);

    void saveOwnerDataToFile(QJsonObject&);
};

#endif // USERDATA_H
