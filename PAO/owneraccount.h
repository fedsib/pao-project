#ifndef USERACCOUNT_H
#define USERACCOUNT_H

/*Represents an account */

#include<QString>
#include<QByteArray>
#include<QCryptographicHash>
#include<QJsonObject>

class OwnerAccount{
  private:
    QString pwdHash;            //It's the hash converted to QString, not the plain text pwd
    bool Vet;

  public:
    OwnerAccount();
    OwnerAccount(const QString&, bool=false);
    OwnerAccount(const QJsonObject&);

    QString getPwdHash() const;
    bool isVet() const;

    bool match(const QString&) const ;
    void setPwdH(QString);
    void setPwd(const QString&);
    void setVet(bool);

    void saveOwnerAccountToFile(QJsonObject&);
  //  bool operator==(const OwnerAccount&) const;
};

#endif // USERACCOUNT_H
