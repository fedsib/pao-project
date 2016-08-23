#ifndef ABSTRACTOWNER_H
#define ABSTRACTOWNER_H

/*Describe a generic PAO user.
 * An user that could have zero or more animals in his/her animalList */

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
    std::vector<Animal*> getAnimalList() const;
    virtual QString typeOfUser() const =0;
};

#endif // ABSTRACTOWNER_H
