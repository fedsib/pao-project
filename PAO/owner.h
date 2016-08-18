#ifndef OWNER_H
#define OWNER_H

#include"userdata.h"

class Owner : public AbstractOwner {
  private:
    UserData userInfo;


  public:
    Owner();
    Owner(const UserData&);
    Owner(const Owner&);
    Owner& operator=(const Owner&);
    ~Owner();

    UserData& getUserInfo() const;


};

#endif // OWNER_H
