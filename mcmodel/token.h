//
// Created by epicmo on 22-10-12.
//

#ifndef MAIN_CC_TOKEN_H
#define MAIN_CC_TOKEN_H
#include <iostream>
#include <ctime>
namespace User_Utility{
    class token{
    public:
        std::string accsessToken;
        std::string clinetToken;
        std::string BindingPlayer;
        time_t generateTime;

    };
    enum state{
        Admitted,
        Banned,
        Pause
    };
}
#endif //MAIN_CC_TOKEN_H
