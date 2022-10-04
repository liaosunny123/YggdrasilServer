//
// Created by epicmo on 22-10-4.
//
#include "authserver.h"

// Add definition of your processing function here
void authserver::authenticate(const drogon::HttpRequestPtr &req,
                              std::function<void(const HttpResponsePtr &)> &&callback) {
    LOG_INFO << "Authserver authenticating:";
    
}