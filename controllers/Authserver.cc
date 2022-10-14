//
// Created by epicmo on 22-10-4.
//
#include "Authserver.h"
#include "../mcmodel/UserImplement.h"
#include "../mcmodel/TokenDictionary.h"
#include "../utility/Utility.h"
#include "../mcmodel/Error.h"
using namespace Yggdrasil;
// Add definition of your processing function here
void Authserver::authenticate(Yggdrasil::authenticate &&pAuthenticate,
                              std::function<void(const HttpResponsePtr &)> &&callback) const{
    LOG_DEBUG << "User " << pAuthenticate.username << " is authenticating";
    Json::Value json;
    UserControl *user = new UserControl(pAuthenticate.username,pAuthenticate.password);
    if (user->Login()){
        if(user->GetUsablePlayerNumber() == 0){
            LOG_INFO << "E10002#ERROR(UnExpected) Authenticate Error[Unkown PlayerBinding] as User " << pAuthenticate.username;
            delete user;
            callback(Error::JsonRespError(403,"E10002#非预期的角色列表","未创建角色或角色列表拉取异常"));
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
        json["UserInfor"] = UserInfor;
    }else{
        LOG_INFO << "E10001#ERROR(Expected) Authenticate Error[Password && Username] as User " << pAuthenticate.username;
        callback(Error::JsonRespError(403,"E10001#未经允许的异常登录","错误的账号与密码"));
    }
    auto resp = HttpResponse::newHttpJsonResponse(json);
    delete user;
    callback(resp);
}