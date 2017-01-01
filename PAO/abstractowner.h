#ifndef ABSTRACTOWNER_H
#define ABSTRACTOWNER_H

/*Describe a generic PAO owner.*/

#include"owneraccount.h"

class AbstractOwner{
  private:
    QString fiscalCode;
    OwnerAccount* account;

  protected:
    AbstractOwner(const QJsonObject&);
    void saveAbsOwner(QJsonObject&);

  public:
    AbstractOwner();
    AbstractOwner(const QString&);
    AbstractOwner(const QString&, OwnerAccount*);

    QString getFiscalCode() const;
    OwnerAccount* getOwnerAccount() const;

    virtual QString typeOfOwner() const =0;
    virtual void saveObj(QJsonObject&) = 0;
};

#endif // ABSTRACTOWNER_H
