#ifndef USERDATA_H
#define USERDATA_H

#include<QString>
#include<QDate>

/*Define the basic data of an user*/

class userData{
  private:
    QString CF;
    QString name;
    QString surname;
    QDate dateOfBirth;
    QString placeofBirth;
    QString sex;
    QString address;       //Format as: street, postalcode, city, province, state
    QString email;
    QString phone;

  public:
    userData();
    userData(const QString&, const QString&, const QString&, const QDate&,
             const QString&, const QString&, const QString&, const QString&, const QString&);
    userData(const userData&);
    userData& operator=(const userData&);
    ~userData();

    QString getCF() const;
    QString getName() const;
    QString getSurname() const;
    QDate getDateOfBirth() const;
    QString getPlaceOfBirth() const;
    QString getSex() const;
    QString getAddress() const;
    QString getEmail()const;
    QString getPhone() const;

    void setName(const QString&);
    void setSurname(const QString&);
    void setDateofBirth(const QDate);
    void setPlaceOfBirth(const QString&);
    void setSex(const QString&);
    void setAddress(const QString&);
    void setEmail(const QString&);
    void setPhone(const QString&);
};

#endif // USERDATA_H
