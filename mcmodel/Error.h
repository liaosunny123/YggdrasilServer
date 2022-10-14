//
// Created by epicmo on 22-10-14.
//

#ifndef MAIN_CC_ERROR_H
#define MAIN_CC_ERROR_H
#include <iostream>
#include <drogon/HttpController.h>

namespace Yggdrasil{
    class Error{
    public:
        static std::shared_ptr<drogon::HttpResponse> JsonRespError(int, std::string, std::string);
    };
}
#endif //MAIN_CC_ERROR_H
