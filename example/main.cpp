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

#include <iostream>
#include <string>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>
#include "../include/Cathash.hpp"

void testfilehash () {
    CatHash::HASH256 hash256_method_obj;
    hash256_method_obj.setReadTarge("./", "test.txt");
    if (hash256_method_obj.startHashFile()){
        std::cout << "Hash file success" << std::endl;
    }
    else {
        std::cout << "Hash file fail" << std::endl;
    }
}

int main () {
    std::string author_intorduction = ROSE"CatHash v1.0 | Nolove\r\n";
    author_intorduction += ROSE"Author > Nolov\r\n";
    author_intorduction += ROSE"Language > C++ | 20 !> 17\r\n";
    author_intorduction += ROSE"Github project link > https://github.com/ozhnolove/CatHash\r\n";
    std::cout << ROSE << "Start Testing CatHash!🐾 \n" << RESET << std::endl;
    std::cout << author_intorduction << std::endl;
    //Create cathash method object
    CatHash::HASH256 hash256_method_obj;
    const std::string testing_hash_str = hash256_method_obj.fetchHash256("Hello open source author!");
    //Print hash
    std::cout << YELLOW << testing_hash_str << RESET << std::endl;
    std::cout << ROSE << "Let's convert the hash to binary and take a look!" << ROSE << std::endl;
    //Convert it back to binary and take a look used 'hashStrtoUint8'
    const std::vector<uint8_t> testing_hash_binary = hash256_method_obj.hashStrtoUint8(testing_hash_str);
    //Print binary
    for (auto& binary_str : testing_hash_binary) {
        std::cout << YELLOW << binary_str << RESET << std::endl;
    }
    //Let's try converting it back to a string
    std::cout << YELLOW << "Let's try converting it back to a string" << RESET << std::endl;
    const std::string testing_binary_to_str = hash256_method_obj . hashUint8toStr(testing_hash_binary);
    //Print result
    std::cout << ROSE << "Testing Hash\a>\a" << testing_binary_to_str << ROSE << std::endl;
    //Verify similarity
    if (testing_hash_str == testing_binary_to_str) {
        std::cout << YELLOW << "Both are the same!" << RESET << std::endl;
    }else {
        std::cout << RED << "The two are not the same😭" << RED << std::endl;
    }
    /**
    Of course, this is a simple verification. If your password has salt protection 
    and you need it for personal project user password security, 
    you should use CatHash's password verification method. 
    This method uses time-constant comparison and automatic salt generation. Of course,
    the implementation is very simple; after all, I also feel it's quite basic. 
    At least it can prevent hackers since SHA-256 is irreversible, but it is not recommended for 
    large projects because my hash iteration count is very low. I will add more in the future. 
    Thank you for your support.
    */
    /**
    Method Example
    */
    std::cout << ROSE << "Start testing the password verification feature!" << ROSE << std::endl;
    const std::string databese_password = "P0xc200"; //User Passowrd
    std::cout << YELLOW << "Secretly telling you, the correct password is >\a" << databese_password << RESET << std::endl;
    const std::string salt_ = hash256_method_obj.generateSalt();
    const std::string database_hex = hash256_method_obj.fetchHash256(databese_password);
    /**My password verification method removes the ':' so you don't need to remove it yourself.*/
    const std::string database_hex_salt_password = salt_ + ":" + database_hex; //Add salt
    const std::string error_password = "Testingpassword"; //Error password
    //Hash error password
    const std::string error_password_hex = hash256_method_obj.fetchHash256(error_password);
    if (hash256_method_obj.verifyHashPassword(error_password_hex, database_hex_salt_password)){
        //Password under normal circumstances
        std::cout << YELLOW << "Password correct" << YELLOW << std::endl;
    }
    else {
        //Password In case of error
        std::cout << RED << "Password error" << RED << std::endl;
    }

    std::string try_password;
    std::cout << ROSE << "Please try entering the correct password > \a" << ROSE;
    std::getline(std::cin , try_password);

    const std::string try_password_hex = hash256_method_obj.fetchHash256(try_password);
    if (hash256_method_obj.verifyHashPassword(try_password_hex, database_hex_salt_password)){
        std::cout << YELLOW << "Password correct" << YELLOW << std::endl;
    }
    else {
        std::cout << RED << "Wrong password, try again!" << RED << std::endl;  
    }

    const std::string hex_var = hash256_method_obj.fetchHash256("xs9s9");
    hash256_method_obj.setHashIteration(700000);
    const std::string salt = hash256_method_obj.generateSalt();
    const std::string hash_password = hash256_method_obj.getHashPasswordaddIteration(hex_var , salt);
    std::cout << hash_password << std::endl;
    if (hash256_method_obj.verifyHashPasswordIteration("xs9s9", hash_password)){
        std::cout << "LOGIN SUCCESS!" << std::endl;
    }else {
        std::cout << "LOGIN FAIL!" << std::endl;
    }

    testfilehash();

    return 0;
}
