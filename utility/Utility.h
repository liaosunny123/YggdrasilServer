//
// Created by epicmo on 22-10-3.
//

#ifndef YGGDRASILSERVER_UTILITY_H
#define YGGDRASILSERVER_UTILITY_H
#include <iostream>
namespace Yggdrasil{
    class Utility{
    public:
        //解密BASE64加密，返回序列化的信息
        static std::string ConvertBase64To(const std::string,int options = Base64Encoding);
        //加密BASE64
        static std::string ConvertToBase64(const std::string,int options = Base64Encoding);
        //UUID生成方式：
        static std::string CreateUUID();//随机生成
        static std::string CreateUUID(std::string);//根据角色名称生成以兼容原版角色的生成模式
        static std::string CreateUnsignedUUID();//生成无符号的UUID
        enum Base64Option {
            Base64Encoding = 0,
            Base64UrlEncoding = 1,
            KeepTrailingEquals = 0,
            OmitTrailingEquals = 2
        };
    };
}


#endif //YGGDRASILSERVER_UTILITY_H
