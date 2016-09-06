#include "useraccount.h"

UserAccount::UserAccount() : Vet(false){}

UserAccount::UserAccount(const QString& p, bool b) : Vet(b){
  this->setPwd(p);
}

QString UserAccount::getPwdHash() const{
  return pwdHash;
}

bool UserAccount::isVet() const{
  return Vet;
}

bool UserAccount::match(const QString& password)const{
  QByteArray hashArray = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Md5);
  QString h(hashArray.toHex().constData());

  if(! (h == pwdHash)) {
    return false;
  }
  return true;
}

void UserAccount::setPwdH(QString ph){
  pwdHash = ph;
}

void UserAccount::setPwd(const QString& password){
  QByteArray arrhash = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Md5);
  pwdHash = (arrhash.toHex().constData());
}

void UserAccount::setVet(bool v){
  Vet = v;
}

void UserAccount::saveUserAccountToFile(QJsonObject& js){
  js["hash"] = pwdHash;
  js["isVet"] = Vet;
}

bool UserAccount::operator==(const UserAccount& ua) const{
   return this->getPwdHash() == ua.getPwdHash();
}
