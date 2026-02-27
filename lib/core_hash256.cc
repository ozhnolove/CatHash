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

#include "../core/create_hash.hpp"
#include <cstddef>
#include <cstdint>
#include <exception>
#include <string>
#include <sys/types.h>
#include <vector>
 
void CatHash::Hash256::hexcore::hashcore::create_hash_256(const std::string& targe){
    std::vector<uint8_t> data(targe.begin() , targe.end());
    size_t bit_length = data.size() * 8;
    data.push_back(0x80);
    while ((data.size()*8) % 512 != 448) {data.push_back(0x00);}
    for (int i = 7; i >= 0; i--) {data.push_back((bit_length >> (i * 8))&0xFF);}
    uint32_t h[8];
    for (int i = 0; i < 8; i++) h[i] =  CatHash::Hash256::hexcore::hashcore::H0[i];
    for (size_t i = 0 ; i < data.size(); i += 64) {
        uint8_t w[64];
        for (int j = 0; j < 16; j++) 
        { w[j] = (data[i + j *4] << 24) |
                 (data[i + j *4 + 1] << 16) |
                 (data[i + j *4 + 2] << 8) |
                 (data[i + j *4 + 3]);
        }
        for (int j = 16; j < 64; j++) 
        {
            w[j] = CatHash::Hash256::hexcore::hashcore::small_sigma1(w[j-2]) +
                w[j-7] + CatHash::Hash256::hexcore::hashcore::small_sigma0
                (w[j-15]) + w[j - 16];
        }
        
        uint32_t a = h[0] , b = h[1] , c = h[2] , d = h[3];
        uint32_t e = h[4] , f = h[5] , g = h[6] , _h = h[7];

        for (int j = 0 ; j < 64; j++) { uint32_t s1 = CatHash::Hash256::hexcore::hashcore::big_sigma1(e);
                                    uint32_t ch_val = CatHash::Hash256::hexcore::hashcore::ch(e, f, g);
                                    uint32_t temp_1 = _h + s1 + ch_val + CatHash::Hash256::hexcore::hashcore::K[j] + w[j];
                                    uint32_t S0 = CatHash::Hash256::hexcore::hashcore::big_sigma0(a);
                                    uint32_t maj_val = CatHash::Hash256::hexcore::hashcore::maj(a, b, c);
                                    uint32_t temp_2 = S0 + maj_val;
                                    _h = g;
                                    g = f;
                                    f = e;
                                    e = d + temp_1;
                                    d = c;
                                    c = b;
                                    b = a;
                                    a = temp_1 + temp_2;

                                    h[0] += a ; h[1] += b; h[2] += c; h[3] += d;
                                    h[4] += e ; h[5] += f; h[6] += g; h[7] += _h;
                                }
        std::vector<uint8_t> result(32);
        for (int i = 0; i < 8; i++) { 
            result[i*4] = (h[i] >> 24) & 0xFF;
            result[i*4+1] = (h[i] >> 16) & 0xFF;
            result[i*4+2] = (h[i] >> 8) & 0xFF;
            result[i*4+3] = (h[i] & 0xFF);
        }
        CatHash::Hash256::hexcore::hashcore::hex_uint8 = result;
    }
}

std::vector<uint8_t> CatHash::Hash256::hexcore::hashcore::hex_to_bytes_unit8(const std::string& hex) const {
    std::vector<uint8_t> bytes_;
    try {
        for (size_t i = 0; i < hex.length(); i += 2) 
        { std::string bytes_str = hex.substr(i , 2); uint8_t byte = static_cast<uint8_t>
            (std::stoi(bytes_str , nullptr , 16));bytes_.push_back(byte);}
            return bytes_;
    } catch(std::exception& error){std::cerr << "[x][FAIL] \a > " 
        << error.what() << std::endl; return bytes_;}
}