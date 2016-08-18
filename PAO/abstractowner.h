#ifndef ABSTRACTOWNER_H
#define ABSTRACTOWNER_H

#include<QString>

class AbstractOwner{
  private:
    QString fiscalCode;

  public:
    AbstractOwner();
    AbstractOwner(const QString&);
    AbstractOwner(const AbstractOwner&);
    AbstractOwner& operator=(const AbstractOwner&);
    virtual ~AbstractOwner()=0;

    QString getFiscalCode() const;
};

#endif // ABSTRACTOWNER_H
