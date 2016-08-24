#ifndef ABSTRACTOWNER_H
#define ABSTRACTOWNER_H

/*Describe a generic PAO user.*/

#include<QString>
#include"animal.h"

class AbstractOwner{
  private:
    QString fiscalCode;

  public:
    AbstractOwner();
    AbstractOwner(const QString&);

    QString getFiscalCode() const;
    virtual QString typeOfUser() const =0;
};

#endif // ABSTRACTOWNER_H
