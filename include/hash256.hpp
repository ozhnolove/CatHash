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

#ifndef _HASH256_HPP_
#define _HASH256_HPP_

#include <cstdint>
#include <memory>
#include <string>
#include <sys/types.h>
#include <vector>
#include "../core/create_hash.hpp"

namespace CatHash {
        class HASH256 {
            std::unique_ptr<CatHash::Hash256::hexcore::hashcore> hash_obj;
            std::string data;
            std::string result_hex;
            public:
            HASH256(){
            CatHash::HASH256::hash_obj = std::make_unique<
            CatHash::Hash256::hexcore::hashcore>();};
            std::string fetchHash256 (const std::string& _data);
            std::string generateSalt () const;
            std::string hashUint8toStr (const std::vector<uint8_t>& hash_uint8);
            bool constantTimeCompare (const std::string&verifyPassword , const std::string& dataBasePassworld);
            bool verifyHashPassword (const std::string& verifyHash , const std::string& accountHash);
            std::vector<uint8_t> hashStrtoUint8 (const std::string& hash_str);
            std::pair<std::string, std::string> splitSaltAndHash (const std::string& dataBasePassworld) {
                size_t colon = dataBasePassworld.find(":");
                if (colon == std::string::npos) return {"" , ""};
                return {dataBasePassworld.substr(0,colon) , dataBasePassworld.substr(colon + 1)};
            }
        };
}


#endif