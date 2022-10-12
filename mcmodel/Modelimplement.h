//
// Created by epicmo on 22-10-11.
//

#ifndef YGGDRASILSERVER_MODELIMPLEMENT_H
#define YGGDRASILSERVER_MODELIMPLEMENT_H
#include <drogon/HttpController.h>
#include "Authservermodel.h"
namespace drogon{
    template <>
    inline Yggdrasil::authenticate fromRequest(const HttpRequest &req){
        auto json = req.getJsonObject();
        Yggdrasil::authenticate authenticate;
        if (json){
            authenticate.username = (*json)["username"].asString();
            authenticate.password = (*json)["password"].asString();
            authenticate.clientToken = (*json)["clientToken"].asString();
            authenticate.requestUser = (*json)["requestUser"].asBool();
            authenticate.name = (*json)["agent"]["name"].asString();
            authenticate.version = (*json)["agent"]["version"].asInt();
        }
        return authenticate;
    }
}
#endif //YGGDRASILSERVER_MODELIMPLEMENT_H
