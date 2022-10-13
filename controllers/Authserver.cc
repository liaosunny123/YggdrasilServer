//
// Created by epicmo on 22-10-4.
//
#include "Authserver.h"
#include "../mcmodel/UserImplement.h"
#include "../mcmodel/TokenDictionary.h"
#include "../utility/Utility.h"
using namespace Yggdrasil;
// Add definition of your processing function here
void Authserver::authenticate(Yggdrasil::authenticate &&pAuthenticate,
                              std::function<void(const HttpResponsePtr &)> &&callback) const{
    LOG_DEBUG << "User " << pAuthenticate.username << " is authenticating...";
    Json::Value json;
    UserControl *user = new UserControl(pAuthenticate.username,pAuthenticate.password);
    if (user->Login()){
        if(user->GetUsablePlayerNumber() == 0){
            LOG_INFO << "E10002#ERROR(Expected) Authenticate Error[Unkown PlayerBinding] as User " << pAuthenticate.username;
            json["error"] = 403;
            json["errorMessage"] = "E10002#未经允许的异常登录";
            json["cause"] = "未创建角色或角色拉取异常";
            auto resp = HttpResponse::newHttpJsonResponse(json);
            callback(resp);
            return;
        }
        //TODO Token Implemtion

        Token *token = new Token(pAuthenticate.clientToken);
        json["accessToken"] = token->accsessToken;
        json["clientToken"]  = token->clinetToken;


        json["availableProfiles"] = user->FetchUsablePlayer();
        Json::Value selectedProfile;
        if (user->GetUsablePlayerNumber() == 1){
            selectedProfile = user->FetchUsablePlayer();
        }
        json["selectedProfile"] = selectedProfile;
        Json::Value UserInfor;
        if (pAuthenticate.requestUser){
            UserInfor = user->GetUserInfor();
        }
        json["user"] = UserInfor;
    }else{
        LOG_INFO << "E10001#ERROR(Expected) Authenticate Error[Password && Username] as User " << pAuthenticate.username;
        json["error"] = 403;
        json["errorMessage"] = "E10001#未经允许的异常登录";
        json["cause"] = "错误的账号与密码";
    }
    auto resp = HttpResponse::newHttpJsonResponse(json);
    callback(resp);
}