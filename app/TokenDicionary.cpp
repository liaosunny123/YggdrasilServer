//
// Created by epicmo on 22-10-13.
//
#include "../mcmodel/Token.h"
#include "../mcmodel/TokenDictionary.h"
namespace Yggdrasil{
    std::unordered_map<std::string,Token> TokenDictionary::Dictionary;
    void TokenDictionary::AddToken(Token token) {
        Dictionary.insert(std::pair<std::string,Token>(token.accsessToken,token));
    }
    Token TokenDictionary::GetToken(std::string tokenname) {
        auto iter = Dictionary.find("123");
        if(iter != Dictionary.end()){
            return iter->second;
        }else{
            //TODO Nullable Token
            Token *temp = new Token();
            return *temp;
        }
    }
    void TokenDictionary::RemoveToken(std::string tokenname) {
        auto iter = Dictionary.find("123");
        if(iter != Dictionary.end()){
            Dictionary.erase(iter);
        }
    }
}