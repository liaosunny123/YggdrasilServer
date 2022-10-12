//
// Created by epicmo on 22-10-3.
//

#ifndef YGGDRASILSERVER_TEXTURE_H
#define YGGDRASILSERVER_TEXTURE_H
#include <iostream>
#include "../mcmodel/Model.h"
namespace Yggdrasil{
    class Texture{
    public:
        std::string TimeStamp;
        std::string ProfileId;
        std::string ProfileName;
    };

    class TextureDetails{
    public:
        texture_module::type type;

    };
}

#endif //YGGDRASILSERVER_TEXTURE_H
