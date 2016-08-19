#ifndef CONTACTINFO_H
#define CONTACTINFO_H

/*Describe the contact information for PAO's users.
 * This type is used in the UserData class.
 * Address is formatted as described below */

#include<QString>

class ContactInfo{
  private:
    QString address;       //Format as: street, postalcode, city, province, state
    QString Mail;
    QString phone;

  public:
    ContactInfo();
    ContactInfo(const ContactInfo&);
    ContactInfo& operator=(const ContactInfo&);
    ~ContactInfo();

    QString getAddress() const;
    QString getMail() const;
    QString getPhone() const;

    void setAddress(const QString&);
    void setMail(const QString&);
    void setPhone(const QString&);
};

#endif // CONTACTINFO_H
