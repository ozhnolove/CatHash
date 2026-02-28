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

#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define ROSE    "\033[38;5;206m"

/**
*@author Nolove
*@date 2026.2.21
*/


#include "../include/hash256.hpp"
#include <cstddef>
#include <cstdint>
#include <exception>
#include <iostream>
#include <ostream>
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
    return CatHash::HASH256::binToHex(salt_and_data);
}

std::string CatHash::HASH256::fetchHash256(const std::string& _data)
{
    const size_t MAX_INPUT_SIZE = 1024 * 1024;
    if (_data.empty() || _data.length() > MAX_INPUT_SIZE) {return "";}
    for (char str_c : _data) {if(str_c == '\0'){return "";}}
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


std::string CatHash::HASH256::binToHex(const std::string& binary) {
    std::stringstream str_stream;
    for (unsigned char c : binary) {
        str_stream << std::hex << std::setw(2) << std::setfill('0') << (int)c;
    }
    return str_stream.str();
}

bool CatHash::HASH256::verifyHashPasswordIteration (const std::string& verifyPassword , 
    const std::string& dataBasePassworld) {
    auto [salt , hex_password] = CatHash::HASH256::splitSaltAndHash(dataBasePassworld);
    const std::string salt_add_input_password = CatHash::HASH256::getHashPasswordaddIteration
    (CatHash::HASH256::fetchHash256(verifyPassword) , salt);
    return constantTimeCompare(salt_add_input_password, dataBasePassworld);
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

std::string CatHash::HASH256::getHashPasswordaddIteration(const std::string& hex_password 
    , const std::string& salt) {
    std::string result_hex;
    const std::string hex_targe = salt + hex_password;
    for (int i = 0; i < hash_iterations_numbers; i ++) 
    {result_hex = fetchHash256(result_hex);}
    const std::string result_add_salt = salt + ":" + result_hex;
    return result_add_salt;
}