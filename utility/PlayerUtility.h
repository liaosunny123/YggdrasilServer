//
// Created by epicmo on 22-10-3.
//

#ifndef YGGDRASILSERVER_PLAYERUTILITY_H
#define YGGDRASILSERVER_PLAYERUTILITY_H
//本类用于处理玩家的基本信息的操作
#include <iostream>
#include "../user/Player.h"
#include "../mcmodel/Model.h"
class Player_Utility{
public:
    //传入string表示想要获取的属性值，大小写敏感
    std::string GetUserProperties(const Player,const std::string);
    //根据传入的User的信息计算并赋予Player的PlayerInfor（序列化信息）
    void ComputePlayerInfor(Player &);
    //计算Texture的metadata数据
    void ComputeMetadataInfor(texture &);
    //计算Texture的Texture数据
    void ComputeTextureInfor(texture &);
};
#endif //YGGDRASILSERVER_PLAYERUTILITY_H
