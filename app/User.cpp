//
// Created by epicmo on 22-10-12.
//
#include "../mcmodel/UserImplement.h"
//TODO Unfinished Fuction List
namespace Yggdrasil{
    UserControl::UserControl(std::string mail, std::string passwd) {
        this->user.email = mail;
        this->user.password = passwd;
    }

    bool UserControl::Login() {

        return true;
    }
    int UserControl::GetUsablePlayerNumber(){
        return 2;
    }
    std::string UserControl::GetUserInfor(){
        return "None";
    }
    std::string UserControl::GetUserProperties(){
        return "None";
    }
    Json::Value UserControl::FetchUsablePlayer(){
        Json::Value result;
        result["Test"] = 1;
        return result;
    }
}