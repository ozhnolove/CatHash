// MIT License
// 
// Copyright (c) 2026 CatHash Contributors
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
//  __   __   __   __   __   __   __   __   __   __   __   __   __   __   __
// /  \ /  \ /  \ /  \ /  \ /  \ /  \ /  \ /  \ /  \ /  \ /  \ /  \ /  \ /  \
// \__/ \__/ \__/ \__/ \__/ \__/ \__/ \__/ \__/ \__/ \__/ \__/ \__/ \__/ \__/
//   ╱╲      ╱╲      ╱╲      ╱╲      ╱╲      ╱╲      ╱╲      ╱╲      ╱╲
//  ( CatHash )    ( CatHash )    ( CatHash )    ( CatHash )    ( CatHash )
//   ╲╱      ╲╱      ╲╱      ╲╱      ╲╱      ╲╱      ╲╱      ╲╱      ╲╱
//  __   __   __   __   __   __   __   __   __   __   __   __   __   __   __
// /  \ /  \ /  \ /  \ /  \ /  \ /  \ /  \ /  \ /  \ /  \ /  \ /  \ /  \ /  \
// \__/ \__/ \__/ \__/ \__/ \__/ \__/ \__/ \__/ \__/ \__/ \__/ \__/ \__/ \__/
//
// 喵喵哈希 - 从零手写的SHA256
// 
// 作者: Nolove
// 时间: 2026.2.21
// 说明: 这是一个15岁的简单实用项目，小项目可用大项目慎用
//       包含: SHA256核心、十六进制转换、随机盐生成、密码哈希
//       警告: 未经安全审计，仅供学习，生产环境请用更成熟的库
//
// CatHash - SHA256 Written from Scratch
// 
// Author: Nolove
// Date: 2026.2.21
// Description: A simple but practical project written by a 15-year-old. 
//              Suitable for small projects, use with caution in large ones.
//              Includes: SHA256 core, hex conversion, random salt generation, password hashing
// Warning: Not security audited. For learning purposes only. 
//          For production, please use more mature libraries like OpenSSL.

/**
*@author Nolove
*@date 2026.2.21
*/


#include "../include/hash256.hpp"
#include <cstddef>
#include <cstdint>
#include <exception>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <utility>
#include <vector>


std::string CatHash::HASH256::generateSalt() const {
    static std::random_device rd;
    static std::mt19937_64 gen(rd());
    static std::uniform_int_distribution<uint64_t> dis;

    std::stringstream str_stream;
    uint64_t r1 = dis(gen);
    uint64_t r2 = dis(gen);

    for (int i = 0; i < 8; i++) { str_stream << static_cast<char>((r1 >> (i*8))& 0xFF);}
    for (int i = 0; i < 8; i++) { str_stream << static_cast<char>((r2 >> (i*8))& 0XFF);}

    const std::string salt_and_data = str_stream.str();
    return salt_and_data;
}

std::string CatHash::HASH256::fetchHash256(const std::string& _data)
{
    CatHash::HASH256::hash_obj -> create_hash_256(_data);
    const std::vector<uint8_t> hash_uint8 = CatHash::HASH256::hash_obj -> get_hash_unit8(); 
    const std::string hash_str = CatHash::HASH256::hash_obj -> bytes_uint8_to_hex(hash_uint8);
    return hash_str;
}

std::vector<uint8_t> CatHash::HASH256::hashStrtoUint8(const std::string& hash_str) {
    const std::vector<uint8_t> HASHUNIT8 = CatHash::HASH256::hash_obj
         -> hex_to_bytes_unit8(hash_str);
         return HASHUNIT8;   
}

std::string CatHash::HASH256::hashUint8toStr(const std::vector<uint8_t>& hash_uint8) {
    const std::string HASHSTRING = CatHash::HASH256::hash_obj 
        -> bytes_uint8_to_hex(hash_uint8);
        return HASHSTRING;
}

bool CatHash::HASH256::constantTimeCompare(const std::string& verifyPassword , const std::string& dataBasePassworld) {
    if (verifyPassword.length() != dataBasePassworld.length()) return false;
    volatile int result = 0;
    for (size_t i = 0; i < verifyPassword.length(); i++){
        result |= (static_cast<unsigned char>(verifyPassword[i])) ^
            static_cast<unsigned char>(dataBasePassworld[i]);
    }
    return result == 0;
}

bool CatHash::HASH256::verifyHashPassword(const std::string& verifyHash , const std::string& accountHash) {
    try {
        if (!hash_obj) {hash_obj = std::make_unique<CatHash::Hash256::hexcore::hashcore>();}
        auto [salt_hex , hash_hex] = 
        CatHash::HASH256::splitSaltAndHash(accountHash);
        if (salt_hex.empty() || hash_hex.empty()) {return false;}
        const std::vector<uint8_t> verify_password_hex_uint8 = hash_obj -> get_hash_unit8();
        const std::string verify_password_hex_str = hash_obj -> bytes_uint8_to_hex(verify_password_hex_uint8);
        return constantTimeCompare(verify_password_hex_str,hash_hex);
    }catch (std::exception& error)
    {std::cerr << "[x][ERROR]\a >" << error.what() << std::endl; return false;}
};
