//
// Created by epicmo on 22-10-4.
//
#include "authserver.h"

// Add definition of your processing function here
void authserver::authenticate(authservermodel::authenticate &&pAuthenticate,
                              std::function<void(const HttpResponsePtr &)> &&callback) const{
    LOG_INFO << "Authserver authenticating:";
    Json::Value json;
    json["code"] = 0;
    auto resp = HttpResponse::newHttpJsonResponse(json);
    callback(resp);
}