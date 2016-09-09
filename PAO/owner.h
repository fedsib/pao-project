#ifndef OWNER_H
#define OWNER_H

/*Represent a private owner of animals. */

#include"ownerdata.h"
#include"abstractowner.h"

class Owner : public AbstractOwner {
  private:
    OwnerData* ownerInfo;

  public:
    Owner(const QString);
    Owner(const QString&, OwnerAccount*, OwnerData*);
    Owner(const QJsonObject&);

    OwnerData* getOwnerInfo() const;

    virtual QString typeOfOwner() const;
    virtual void saveObj(QJsonObject&);
};

#endif // OWNER_H
