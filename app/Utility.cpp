//
// Created by epicmo on 22-10-12.
//
#include <iostream>
#include <algorithm>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include "../utility/Utility.h"

//解密BASE64加密，返回序列化的信息
namespace Yggdrasil{
    std::string Utility::ConvertBase64To(const std::string sourceData,int options){
        unsigned int buf = 0;
        int nbits = 0;
        std::string tmp;
        tmp.resize((sourceData.size() * 3) / 4);

        int offset = 0;
        for (int i = 0; i < sourceData.size(); ++i) {
            int ch = sourceData.at(i);
            int d;

            if (ch >= 'A' && ch <= 'Z')
                d = ch - 'A';
            else if (ch >= 'a' && ch <= 'z')
                d = ch - 'a' + 26;
            else if (ch >= '0' && ch <= '9')
                d = ch - '0' + 52;
            else if (ch == '+' && (options & Base64UrlEncoding) == 0)
                d = 62;
            else if (ch == '-' && (options & Base64UrlEncoding) != 0)
                d = 62;
            else if (ch == '/' && (options & Base64UrlEncoding) == 0)
                d = 63;
            else if (ch == '_' && (options & Base64UrlEncoding) != 0)
                d = 63;
            else
                d = -1;

            if (d != -1) {
                buf = (buf << 6) | d;
                nbits += 6;
                if (nbits >= 8) {
                    nbits -= 8;
                    tmp[offset++] = buf >> nbits;
                    buf &= (1 << nbits) - 1;
                }
            }
        }

        tmp.resize(offset);
        return tmp;

    }
//加密BASE64
    std::string Utility::ConvertToBase64(const std::string sourceData,int options){
        const char alphabet_base64[] = "ABCDEFGH" "IJKLMNOP" "QRSTUVWX" "YZabcdef"
                                       "ghijklmn" "opqrstuv" "wxyz0123" "456789+/";
        const char alphabet_base64url[] = "ABCDEFGH" "IJKLMNOP" "QRSTUVWX" "YZabcdef"
                                          "ghijklmn" "opqrstuv" "wxyz0123" "456789-_";
        const char *const alphabet = options & Base64UrlEncoding ? alphabet_base64url : alphabet_base64;
        const char padchar = '=';
        int padlen = 0;

        std::string tmp;
        tmp.resize((sourceData.size() + 2) / 3 * 4);

        int i = 0;
        char *out = &tmp[0];
        while (i < sourceData.size()) {
            // encode 3 bytes at a time
            int chunk = 0;
            chunk |= int((unsigned char)(sourceData.data()[i++])) << 16;
            if (i == sourceData.size()) {
                padlen = 2;
            } else {
                chunk |= int((unsigned char)(sourceData.data()[i++])) << 8;
                if (i == sourceData.size())
                    padlen = 1;
                else
                    chunk |= int((unsigned char)(sourceData.data()[i++]));
            }

            int j = (chunk & 0x00fc0000) >> 18;
            int k = (chunk & 0x0003f000) >> 12;
            int l = (chunk & 0x00000fc0) >> 6;
            int m = (chunk & 0x0000003f);
            *out++ = alphabet[j];
            *out++ = alphabet[k];

            if (padlen > 1) {
                if ((options & OmitTrailingEquals) == 0)
                    *out++ = padchar;
            } else {
                *out++ = alphabet[l];
            }
            if (padlen > 0) {
                if ((options & OmitTrailingEquals) == 0)
                    *out++ = padchar;
            } else {
                *out++ = alphabet[m];
            }
        }
        if (options & OmitTrailingEquals)
            tmp.resize(out - tmp.data());
        return tmp;

    }
//UUID生成方式：
    std::string Utility::CreateUUID(){
        boost::uuids::uuid uid = boost::uuids::random_generator()();
        const std::string uid_str = boost::uuids::to_string(uid);
        return uid_str;
    }//随机生成


    std::string Utility::CreateUUID(std::string){
        boost::uuids::uuid uid = boost::uuids::random_generator()();
        const std::string uid_str = boost::uuids::to_string(uid);
        return uid_str;
    }//根据角色名称生成以兼容原版角色的生成模式

    std::string Utility::CreateUnsignedUUID(){
        boost::uuids::uuid uid = boost::uuids::random_generator()();
        std::string stru0 = boost::uuids::to_string(uid);
        stru0.erase(std::remove(stru0.begin(), stru0.end(), '-'), stru0.end());
        return stru0;
    }
}
