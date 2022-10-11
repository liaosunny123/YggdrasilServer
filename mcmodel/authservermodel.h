//
// Created by epicmo on 22-10-11.
//

#ifndef YGGDRASILSERVER_AUTHSERVERMODEL_H
#define YGGDRASILSERVER_AUTHSERVERMODEL_H
#include <iostream>
#include <drogon/HttpController.h>
using namespace drogon;

namespace authservermodel{
    struct authenticate{
        std::string username;
        std::string password;
        std::string clientToken;
        bool requestUser;
        std::string name;
        int version;
    };
}
#endif //YGGDRASILSERVER_AUTHSERVERMODEL_H
