#ifndef ABSTRACTOWNER_H
#define ABSTRACTOWNER_H

/*Describe a generic PAO user.*/

#include<QString>
#include <QJsonObject>
#include"animal.h"
#include"useraccount.h"

class AbstractOwner{
  private:
    QString fiscalCode;
    UserAccount account;

  protected:
    AbstractOwner(const QJsonObject&);
    void saveAbsOwner(QJsonObject&);

  public:
    AbstractOwner();
    AbstractOwner(const QString&);

    QString getFiscalCode() const;
    UserAccount& getUserAccount() const;

    virtual QString typeOfUser() const =0;
    virtual void saveObj(QJsonObject&) = 0;
};

#endif // ABSTRACTOWNER_H
