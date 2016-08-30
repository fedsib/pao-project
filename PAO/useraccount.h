#ifndef USERACCOUNT_H
#define USERACCOUNT_H

/*Represents an account */

#include<QString>
#include<QByteArray>
#include<QCryptographicHash>
#include<QJsonObject>

class UserAccount{
  private:
    QString pwdHash;            //Is the hash converted to QString, not the plain text pwd
    bool Vet;
  public:
    UserAccount();
    UserAccount(const QString&, bool=false);
    UserAccount(const QJsonObject&);

    QString getPwdHash() const;
    bool isVet() const;

    bool match(const QString&)const ;
    void setPwd(const QString&);
    void setVet(bool);

    void saveUserAccountToFile(QJsonObject&);
    bool operator==(const UserAccount&) const;
};

#endif // USERACCOUNT_H
