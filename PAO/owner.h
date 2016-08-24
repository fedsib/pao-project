#ifndef OWNER_H
#define OWNER_H

/*Represent a private owner of animals. */

#include"userdata.h"
#include"abstractowner.h"

class Owner : public AbstractOwner {
  private:
    UserData userInfo;

  public:
    Owner();
    Owner(const UserData&);
    Owner(const QJsonObject&);

    UserData& getUserInfo() const;

    virtual void saveObj(QJsonObject&) override;
};

#endif // OWNER_H
