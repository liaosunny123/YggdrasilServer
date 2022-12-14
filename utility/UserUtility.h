//
// Created by epicmo on 22-10-2.
//

#ifndef YGGDRASILSERVER_USERUTILITY_H
#define YGGDRASILSERVER_USERUTILITY_H
//本类用于处理用户的基本信息的操作
#include <iostream>
#include "entitymodel/User.h"

namespace Yggdrasil{
    class User_Utility{
    public:
        //传入string表示想要获取的属性值，大小写敏感
        static std::string GetUserProperties(const User,const std::string);
        //根据传入的User的信息计算并赋予User的UserInfor（序列化信息）
        static void ComputeUserInfor(User &);
        static std::string GetUserUUID(User & conse);
        
    };
}

#endif //YGGDRASILSERVER_USERUTILITY_H
