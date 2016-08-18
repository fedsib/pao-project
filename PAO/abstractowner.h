#ifndef ABSTRACTOWNER_H
#define ABSTRACTOWNER_H

#include<QString>
#include"animal.h"

class AbstractOwner{
  private:
    QString fiscalCode;
    std::vector<Animal*> animalList;

  public:
    AbstractOwner();
    AbstractOwner(const QString&, const std::vector<Animal*>&);
    AbstractOwner(const AbstractOwner&);
    AbstractOwner& operator=(const AbstractOwner&);
    virtual ~AbstractOwner()=0;

    QString getFiscalCode() const;
    std::vector<Animal*>& getAnimalList() const;
};

#endif // ABSTRACTOWNER_H
