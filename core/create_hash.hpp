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

#ifndef _CREATE_HASH_HPP_
#define _CREATE_HASH_HPP_

#include <cstdint>
#include <exception>
#include <iostream>
#include <sys/types.h>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>

namespace CatHash {
        namespace Hash256::hexcore {
            class hashcore {
            public:
            static constexpr uint32_t H0[8] = {
                0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
                0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
            };

            static constexpr uint32_t K[64] = {
                0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
                0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
                0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
                0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
                0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
                0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
                0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
                0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
                0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
                0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
                0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
                0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
                0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
                0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
                0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
                0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
            };
                std::vector<uint8_t> hex_uint8;
                public:
                    hashcore() = default;
                    void create_hash_256(const std::string& targe);
                    inline std::vector<uint8_t> get_hash_unit8() {return hex_uint8;};
                    inline std::string bytes_uint8_to_hex (const std::vector<uint8_t>& bytes_uint8) const 
                    {
                        try {
                            std::ostringstream oss_str_stream;
                            for (uint8_t str : bytes_uint8){ 
                                oss_str_stream << std::hex << std::setw(2) << std::setfill('0') << (int)str;}
                                return oss_str_stream.str();
                        } catch(std::exception& to_err) {
                            std::cerr << "[x][FAIL]\a>" << to_err.what() << std::endl;
                            return to_err.what();
                        }
                    }
                    std::vector<uint8_t> hex_to_bytes_unit8 (const std::string& hex) const;
                    static inline uint32_t rotr (uint32_t x , int n){return (x >> n) | (x << (32 - n));}
                    static inline uint32_t shr (uint32_t x , int n){return x >> n;}
                    static inline uint32_t ch (uint32_t x , uint32_t y , uint32_t z) {return (x & y) ^ (~x & z);}
                    static inline uint32_t maj (uint32_t x , uint32_t y , uint32_t z) {return (x & y) ^ (x & z) ^ (y & z);}
                    static inline uint32_t big_sigma0(uint32_t x) {return rotr(x, 2) ^ rotr(x, 13) ^ rotr(x, 22);}
                    static inline uint32_t big_sigma1(uint32_t x) {return rotr(x, 6) ^ rotr(x, 11) ^ rotr(x, 25);}
                    static inline uint32_t small_sigma0(uint32_t x) {return rotr(x, 7) ^ rotr(x, 18) ^ shr(x, 3);}
                    static inline uint32_t small_sigma1(uint32_t x) {return rotr(x, 17) ^ rotr(x, 19) ^ shr(x, 10);}
                    bool verify_hex_password (const std::string& account_password , const std::string& stored); 
            };
        }
}

#endif