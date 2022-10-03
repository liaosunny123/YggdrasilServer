//
// Created by epicmo on 22-10-3.
//

#ifndef YGGDRASILSERVER_UTILITY_H
#define YGGDRASILSERVER_UTILITY_H
#include <iostream>
class Utility{
public:
    //解密BASE64加密，返回序列化的信息
    std::string ConvertBase64To(const std::string);
    //加密BASE64
    std::string ConvertToBase64(const std::string);
    //UUID生成方式：
    std::string CreateUUID();//随机生成
    std::string CreateUUID(std::string);//根据角色名称生成以兼容原版角色的生成模式
    
};

#endif //YGGDRASILSERVER_UTILITY_H
