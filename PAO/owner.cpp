#include "owner.h"

Owner::Owner(){
}

Owner::Owner(const UserData& ud) : {}

UserData& Owner::getUserInfo() const{
    return userInfo;
}
