//
// Created by epicmo on 22-10-12.
//
#include <drogon/HttpController.h>
#include "../mcmodel/Token.h"
#include "../mcmodel/TokenDictionary.h"
#include "../utility/Utility.h"
namespace Yggdrasil{
    Token::Token() {
        this->generateAccessToken();
        this->generateClientToken();
        TokenDictionary::AddToken(*this);
        LOG_INFO << "Create new Token->AccessToken is " << this->accsessToken;
    }
    Token::Token(std::string token) {
        if (token != ""){
            this->clinetToken = token;
        } else{
            this->generateClientToken();
        }
        this->generateAccessToken();
        TokenDictionary::AddToken(*this);
    }
    Token::Token(bool isanonymous) {
        if (isanonymous){
            this->generateAccessToken();
            this->generateClientToken();
        }else{
            LOG_WARN << "Unexpected Token generating way";
        }
    }
    void Token::generateAccessToken(){
        this->accsessToken = Utility::CreateUnsignedUUID();
    }
    void Token::generateClientToken(){
        this->clinetToken = Utility::CreateUnsignedUUID();
    }

}