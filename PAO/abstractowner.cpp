#include "abstractowner.h"

AbstractOwner::AbstractOwner(){}

AbstractOwner::AbstractOwner(const QString& cf, const std::vector<Animal*>& aL) : fiscalCode(cf), animalList(aL){}

std::vector<Animal*> AbstractOwner::getAnimalList() const {
  return animalList;
}

QString AbstractOwner::getFiscalCode() const{
  return fiscalCode;
}



