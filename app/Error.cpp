//
// Created by epicmo on 22-10-14.
//
#include "mcmodel/Error.h"
namespace Yggdrasil{
    std::shared_ptr<drogon::HttpResponse> Error::JsonRespError(int code, std::string errormsg, std::string cause) {
        Json::Value json;
        json["error"] = code;
        json["errorMessage"] = errormsg;
        json["cause"] = cause;
        auto resp = drogon::HttpResponse::newHttpJsonResponse(json);
        return resp;
    }

}