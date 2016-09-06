#ifndef OWNER_H
#define OWNER_H

/*Represent a private owner of animals. */

#include"userdata.h"
#include"abstractowner.h"

class Owner : public AbstractOwner {
  private:
    UserData* userInfo;

  public:
    Owner(const QString);
    Owner(const QString&, UserAccount*, UserData*);
    Owner(const QJsonObject&);

    UserData* getUserInfo() const;

    virtual QString typeOfUser() const;
    virtual void saveObj(QJsonObject&);
};

#endif // OWNER_H
