#ifndef OWNER_H
#define OWNER_H

#include <vector>
#include"userdata.h"
#include"pet.h"

class Owner : public AbstractOwner {
  private:
    UserData userInfo;
    std::vector<Pet> petList;

  public:
    Owner();
    Owner(const UserData&, const std::vector<Pet>&);
    Owner(const Owner&);
    Owner& operator=(const Owner&);
    ~Owner();

    UserData& getUserInfo() const;
    std::vector<Pet>& getPetList() const;

};

#endif // OWNER_H
