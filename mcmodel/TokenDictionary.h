//
// Created by epicmo on 22-10-13.
//

#ifndef MAIN_CC_TOKENDICTIONARY_H
#define MAIN_CC_TOKENDICTIONARY_H
#include <iostream>
#include <unordered_map>
#include "Token.h"
namespace Yggdrasil{
    class TokenDictionary{
    private:
        static std::unordered_map<std::string,Token> Dictionary;
    public:
        static void AddToken(Token);
        static void RemoveToken(std::string);
        static Token GetToken(std::string);
    };
}
#endif //MAIN_CC_TOKENDICTIONARY_H
