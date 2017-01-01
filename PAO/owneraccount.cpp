#include "owneraccount.h"

OwnerAccount::OwnerAccount() : Vet(false){}

OwnerAccount::OwnerAccount(const QString& p, bool b) : Vet(b){
  this->setPwd(p);
}

OwnerAccount::OwnerAccount(const QJsonObject& js) : pwdHash(js["hash"].toString()), Vet(js["isVet"].toBool()){}

QString OwnerAccount::getPwdHash() const{
  return pwdHash;
}

bool OwnerAccount::isVet() const{
  return Vet;
}

bool OwnerAccount::match(const QString& password)const{
  QByteArray hashArray = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Md5);
  QString h(hashArray.toHex().constData());

  if(! (h == pwdHash)) {
    return false;
  }
  return true;
}

void OwnerAccount::setPwdH(QString ph){
  pwdHash = ph;
}

void OwnerAccount::setPwd(const QString& password){
  QByteArray arrhash = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Md5);
  pwdHash = (arrhash.toHex().constData());
}

void OwnerAccount::setVet(bool v){
  Vet = v;
}

void OwnerAccount::saveOwnerAccountToFile(QJsonObject& js){
  js["hash"] = pwdHash;
  js["isVet"] = Vet;
}
