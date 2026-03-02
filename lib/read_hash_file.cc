#include "../core/read_file.hpp"
#include <cstddef>
#include <fstream>
#include <sstream>
#include <string>


bool CatHash::hash256::hexcore::readFileTool::HashTargeFile(
    const std::stringstream& read_result ,const std::string& fileName , const std::string& filePath) {
        if (hash_obj_ptr) {
            std::fstream file_obj;
            const std::string hash_str = hash_obj_ptr -> fetchHash256(read_result.str());
            hash_obj_ptr -> setHashIteration(600000);
            const std::string salt = hash_obj_ptr -> generateSalt();
            const std::string hash_result = hash_obj_ptr ->getHashPasswordaddIteration(hash_str,salt);
            size_t newFileName_ops = fileName.find(".");
            if (newFileName_ops != std::string::npos)
            {
                CatHash::hash256::hexcore::readFileTool::newFileName = 
                fileName.substr(0,newFileName_ops);}else {CatHash::hash256::hexcore::readFileTool::newFileName = salt;}
            file_obj.open(filePath + newFileName+"_hash" ,  std::ios::out | std::ios::app);
            if (!file_obj) { std::cerr << "[ERROR] Open hash file failed file > \a" <<  
                filePath + newFileName +"_hash" << std::endl; return false;}
            file_obj << hash_result << std::endl;
            file_obj.close();
            return true;
        }else {
            std::cerr << "This 'hash_obj_ptr' is a null pointer" << std::endl;
            return false;
        }
    }