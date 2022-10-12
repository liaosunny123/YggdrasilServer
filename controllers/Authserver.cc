//
// Created by epicmo on 22-10-4.
//
#include "Authserver.h"
#include "../mcmodel/UserImplement.h"
#include "../utility/Utility.h"
using namespace Yggdrasil;
// Add definition of your processing function here
void Authserver::authenticate(Yggdrasil::authenticate &&pAuthenticate,
                              std::function<void(const HttpResponsePtr &)> &&callback) const{
    LOG_INFO << "Authserver authenticating:";
    Json::Value json;
    UserControl *user = new UserControl(pAuthenticate.username,pAuthenticate.password);
    if (user->Login()){
        json["accessToken"] = Utility::CreateUUID();
        if(pAuthenticate.clientToken == ""){
            json["clientToken"]  = Utility::CreateUUID();
        } else{
            json["clientToken"]  = pAuthenticate.password;
        }

    }else{
        json["error"] = 403;
        json["errorMessage"] = "E10001#未经允许的异常登录";
        json["cause"] = "错误的账号与密码";
    }

    auto resp = HttpResponse::newHttpJsonResponse(json);
    callback(resp);
}