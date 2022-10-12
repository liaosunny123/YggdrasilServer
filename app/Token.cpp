//
// Created by epicmo on 22-10-12.
//
#include "../mcmodel/Token.h"
#include "utility/Utility.h"
namespace Yggdrasil{
    Token::Token() {
        //this->generateTime = time(0);
        //this->generateAccessToken();
    }
    void Token::generateAccessToken(){
        this->accsessToken = Utility::CreateUnsignedUUID();
    }
    void Token::generateClientToken(){
        this->clinetToken = Utility::CreateUnsignedUUID();
    }

}