//
// Created by epicmo on 22-10-4.
//

#ifndef YGGDRASILSERVER_AUTHSERVER_H
#define YGGDRASILSERVER_AUTHSERVER_H
#pragma once

#include <drogon/HttpController.h>
#include "../mcmodel/Authservermodel.h"
#include "../mcmodel/Modelimplement.h"
using namespace drogon;
using namespace Yggdrasil;
class Authserver : public drogon::HttpController<Authserver>
{
public:
    METHOD_LIST_BEGIN
        METHOD_ADD(Authserver::authenticate, "/authenticate", Post);
    METHOD_LIST_END

    void authenticate(Yggdrasil::authenticate &&pAuthenticate , std::function<void (const HttpResponsePtr &)> &&callback
        ) const;
};
#endif //YGGDRASILSERVER_AUTHSERVER_H
