//
// Created by epicmo on 22-10-3.
//

#ifndef YGGDRASILSERVER_TOKEN_H
#define YGGDRASILSERVER_TOKEN_H
#include <iostream>
namespace Yggdrasil{
    class Token{
        std::string accessToken;
        std::string clientToken;
        std::string bingingPlayer;
        std::string createdTime;
        bool tokenSate;
    };
}
#endif //YGGDRASILSERVER_TOKEN_H
