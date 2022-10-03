//
// Created by epicmo on 22-10-2.
//

#ifndef YGGDRASILSERVER_USER_H
#define YGGDRASILSERVER_USER_H
#include <iostream>
class User{
    public:
        //用户基本信息
        std::string ID;
        std::string email;
        std::string password;
        //用户额外信息,本信息为BASE64加密后的信息，获取时需要将其序列化并且进行相关获取
        std::string Properties;
        //用户信息的序列化后储存的信息
        std::string UserInfor;
};
#endif //YGGDRASILSERVER_USER_H
