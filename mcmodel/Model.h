//
// Created by epicmo on 22-10-3.
//

#ifndef YGGDRASILSERVER_MODEL_H
#define YGGDRASILSERVER_MODEL_H
#include <iostream>

class texture_module{
public:
    enum type{
        Default,
        Slim,
    };
};

class texture{
public:
    enum key{
        skin,
        cape,
    };
    texture_module::type type;
    std::string url;
    key key;
    //根据剩下的属性生成metadata
    std::string metadata;
    std::string ModelInfor;
};
#endif //YGGDRASILSERVER_MODEL_H
