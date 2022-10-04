//
// Created by epicmo on 22-10-4.
//

#ifndef YGGDRASILSERVER_AUTHSERVER_H
#define YGGDRASILSERVER_AUTHSERVER_H
#pragma once

#include <drogon/HttpController.h>

using namespace drogon;

class authserver : public drogon::HttpController<authserver>
{
public:
    METHOD_LIST_BEGIN
        METHOD_ADD(authserver::authenticate,"/authenticate",Post);
    METHOD_LIST_END

    void authenticate(const HttpRequestPtr &req , std::function<void (const HttpResponsePtr &)> &&callback
        );
};
#endif //YGGDRASILSERVER_AUTHSERVER_H
