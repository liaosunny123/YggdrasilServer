//
// Created by epicmo on 22-10-2.
//

#ifndef YGGDRASILSERVER_PLAYER_H
#define YGGDRASILSERVER_PLAYER_H
#include <iostream>
#include "../mcmodel/Model.h"
namespace Yggdrasil{
    class Player{
    public:
        //用户信息的基本项
        std::string UUID;
        std::string name;
        texture texture;
    };
}
#endif //YGGDRASILSERVER_PLAYER_H
