#ifndef USERDATA_H
#define USERDATA_H

#include<QDate>
#include<QJsonObject>

#include"contactinfo.h"

/*Describe the basic data of a PAO user*/

class UserData{
  private:
    QString name;
    QString surname;
    ContactInfo contacts;

  public:
    UserData();
    UserData(const QString&, const QString&, const ContactInfo&);
    UserData(const QJsonObject&);

    QString getName() const;
    QString getSurname() const;
    ContactInfo getContacts() const;

    void setName(const QString&);
    void setSurname(const QString&);
    void setContacts(const ContactInfo&);

    void saveUserDataToFile(QJsonObject&);
};

#endif // USERDATA_H
