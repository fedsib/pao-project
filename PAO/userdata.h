#ifndef USERDATA_H
#define USERDATA_H

#include<QString>
#include<QDate>
#include"contactinfo.h"

/*Describe the basic data of a PAO user*/

class UserData{
  private:
   // QString CF;
    QString name;
    QString surname;
    QDate dateOfBirth;
    QString sex;
    ContactInfo contacts;

  public:
    UserData();
    UserData(const QString&, const QString&, const QDate&,
             const QString&, const ContactInfo&);
    UserData(const UserData&);
    UserData& operator=(const UserData&);
    ~UserData();

    //QString getCF() const;
    QString getName() const;
    QString getSurname() const;
    QDate getDateOfBirth() const;
    QString getSex() const;
    ContactInfo getContacts() const;

    void setName(const QString&);
    void setSurname(const QString&);
    void setDateofBirth(const QDate);
    void setSex(const QString&);
    void setContacts(const ContactInfo&);
};

#endif // USERDATA_H
