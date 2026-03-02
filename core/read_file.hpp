#ifndef _READ_FILE_HPP_
#define _READ_FILE_HPP_

#include <memory>
#include <sstream>
#include "../include/Cathash.hpp"

namespace CatHash {
    namespace hash256::hexcore {
        class readFileTool {
            public:
            std::string newFileName;
            std::unique_ptr<CatHash::HASH256> hash_obj_ptr;
            readFileTool(){hash_obj_ptr = std::make_unique<CatHash::HASH256>();};
            bool HashTargeFile(const std::stringstream& read_result ,
                const std::string& fileName , const std::string& filePath);
        };
    }
}

#endif