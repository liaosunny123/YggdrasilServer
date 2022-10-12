//
// Created by epicmo on 22-10-12.
//
#include "../mcmodel/UserImplement.h"
namespace Yggdrasil{
    UserControl::UserControl(std::string mail, std::string passwd) {
        this->user.email = mail;
        this->user.password = passwd;
    }

    bool UserControl::Login() {
        return true;
    }
}