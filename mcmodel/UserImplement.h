//
// Created by epicmo on 22-10-12.
//

#ifndef MAIN_CC_USERIMPLEMENT_H
#define MAIN_CC_USERIMPLEMENT_H
#include <iostream>
#include <drogon/HttpController.h>
#include "../utility/UserUtility.h"
#include "entitymodel/User.h"

using namespace drogon;
namespace Yggdrasil{
    class UserControl{
    private:
        User user;
    public:
        UserControl(std::string,std::string);
        int GetUsablePlayerNumber();
        std::string GetUserInfor();
        std::string GetUserProperties();
        bool Login();
        Json::Value FetchUsablePlayer();//返回可用角色列表

    };
}
#endif //MAIN_CC_USERIMPLEMENT_H
