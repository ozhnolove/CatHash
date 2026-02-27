# CatHash - MeowMeowHash EN VERSION README

![GitHub stars](https://img.shields.io/github/stars/ozhnolove/CatHash?style=social)

>  A SHA256 hash library written from scratch—simple, practical, perfect for learning and small projects!

---

## Introduction

CatHash v1.0 | Nolove  
Author: Nolov  
Language: C++20 (compatible with C++17. GCC must support C++17 or higher!)  
GitHub: [https://github.com/ozhnolove/CatHash](https://github.com/ozhnolove/CatHash)

This is a pure-from-scratch SHA256 implementation created by a 15-year-old developer. It features:
- OK Core SHA256 algorithm
- OK Hexadecimal conversion
- OK Random salt generation
- OK Password hashing
- OK Constant-time comparison (protection from timing attacks)

---

## Features & Notes

| Feature | Description |
|--------|-------------|
| Handwritten | Every line is written without referencing OpenSSL code |
| Security | Supports salt and constant-time comparison |
| Lightweight | No external dependencies, just include the header and use CMake |
| Simple | Clean API design, easy to learn and use |
| Note | Not security-audited; use OpenSSL for large projects |

---

## Quick Start

### 1. Clone the project
```bash
git clone https://github.com/ozhnolove/CatHash.git

cd CatHash
./UserGuide # Or check out the User Guide program!
```

### 2. Create a method object
```cpp
#include "Cathash.hpp"
// Create a CatHash method object
CatHash::HASH256 hash256_method_obj;
```

### 3. Use the object to get a hash value
```cpp
// Fetch the SHA256 hash; this returns a string by default
const std::string hash_str = hash256_method_obj.fetchHash256("Hello open source author!");
```

### 4. Convert hash string to binary
```cpp
// Use this if you need the binary form
const std::vector<uint8_t> testing_hash_binary = hash256_method_obj.hashStrtoUint8(testing_hash_str);
```

### 5. Convert binary back to string
```cpp
const std::string testing_binary_to_str = hash256_method_obj.hashUint8toStr(testing_hash_binary);
```

### 6. Store a salted password in your database
```cpp
// Example of adding a password
const std::string databese_password = "P0xc200"; // Your database password
const std::string salt_ = hash256_method_obj.generateSalt(); // Generate salt
const std::string database_hex = hash256_method_obj.fetchHash256(databese_password); // Get hash
/**!!! My password verification method removes the ':' for you, so you don’t need to do it manually.*/
const std::string database_hex_salt_password = salt_ + ":" + database_hex; // Add salt
// After this, your storage logic depends on your ORM/database tools
```

### 7. Password verification

Of course, this is a simple example. If your password system uses salt (for user security in your personal project),  
you should use CatHash’s password verification method. This uses constant-time comparison and automatic salt handling.  
The implementation is basic, but it prevents basic hacking attempts, since SHA-256 is irreversible—but please avoid using this for large projects;  
my hash iteration count is low, but I’ll improve it soon. Thanks for your support!

```cpp
// Password Verification Example
const std::string error_password_hex = hash256_method_obj.fetchHash256(error_password);
if (hash256_method_obj.verifyHashPassword(error_password_hex, database_hex_salt_password)){
    // Password correct
    std::cout << "Password correct" << std::endl;
}
else {
    // Password incorrect
    std::cout << RED << "Password error" << std::endl;
}
```

# CatHash - МяуМяуХэш РУССКАЯ ВЕРСИЯ README

![GitHub stars](https://img.shields.io/github/stars/ozhnolove/CatHash?style=social)

> Библиотека SHA256, написанная с нуля — простая, удобная, идеально подходит для изучения и маленьких проектов!

---

## Введение

CatHash v1.0 | Nolove  
Автор: Nolov  
Язык: C++20 (совместим с C++17. GCC должен поддерживать не ниже C++17!)  
GitHub: [https://github.com/ozhnolove/CatHash](https://github.com/ozhnolove/CatHash)

Это полностью мой собственный SHA256 от 15-летнего разработчика. Включает:
- OK Основной алгоритм SHA256
- OK Конвертация в шестнадцатеричный формат
- OK Генерация случайной соли
- OK Хеширование паролей
- OK Сравнение за постоянное время (защита от атак по времени выполнения)

---

## Особенности и замечания

| Особенность | Описание |
|------------|----------|
| Полностью ручная работа | Не используем код OpenSSL, каждая строчка написана мной |
| Безопасность | Поддержка соли и постоянного времени сравнения |
| Легкость | Нет внешних зависимостей, просто подключайте заголовок и используйте CMake |
| Простота | API максимально простой, освоить легко |
| Важно | Нет аудита безопасности, для больших проектов используйте OpenSSL |

---

## Быстрый старт

### 1. Клонируйте проект
```bash
git clone https://github.com/ozhnolove/CatHash.git

cd CatHash
./UserGuide # Или посмотрите программу User Guide!
```

### 2. Создайте объект метода
```cpp
#include "Cathash.hpp"
// Создайте объект метода CatHash
CatHash::HASH256 hash256_method_obj;
```

### 3. Получайте значение хэша через объект
```cpp
// Получить SHA256 хэш, возвращает строку по умолчанию
const std::string hash_str = hash256_method_obj.fetchHash256("Привет, open source автор!");
```

### 4. Конвертация хэша в бинарный вид
```cpp
// Используйте эту функцию для получения бинарного представления
const std::vector<uint8_t> testing_hash_binary = hash256_method_obj.hashStrtoUint8(testing_hash_str);
```

### 5. Конвертация из бинарного обратно в строку
```cpp
const std::string testing_binary_to_str = hash256_method_obj.hashUint8toStr(testing_hash_binary);
```

### 6. Сохраняйте пароль с солью в базе данных
```cpp
// Пример добавления пароля
const std::string databese_password = "P0xc200"; // Ваш пароль для базы данных
const std::string salt_ = hash256_method_obj.generateSalt(); // Генерация соли
const std::string database_hex = hash256_method_obj.fetchHash256(databese_password); // Получение хэша
/**!!! Мой способ проверки паролей автоматически убирает ':' — вам не нужно делать это вручную.*/
const std::string database_hex_salt_password = salt_ + ":" + database_hex; // Добавляем соль
// Далее — ваша логика добавления через ORM или вручную
```

### 7. Проверка пароля

Это простой пример. Если ваша система паролей использует соль (для безопасности пользователей в личном проекте),  
стоит воспользоваться методом CatHash для проверки паролей: применяется сравнение за постоянное время и автоматическое добавление соли.  
Реализация простая, но защищает от базовых хакерских атак, ведь SHA-256 необратим — но для больших проектов не советую:  
количество итераций небольшое, позже добавлю возможность увеличить. Спасибо за поддержку!

```cpp
// Пример проверки пароля
const std::string error_password_hex = hash256_method_obj.fetchHash256(error_password);
if (hash256_method_obj.verifyHashPassword(error_password_hex, database_hex_salt_password)){
    // Пароль верный
    std::cout << "Пароль верный" << std::endl;
}
else {
    // Пароль неверный
    std::cout << RED << "Пароль неверный" << std::endl;
}
```

#  CatHash - 喵喵哈希 CN VERSION README

![GitHub stars](https://img.shields.io/github/stars/ozhnolove/CatHash?style=social)

> 一个从零手写的 SHA256 哈希库，简单实用，适合学习和小型项目

---

## Intorduction

CatHash v1.0 | Nolove
Author: Nolov  
Language: C++20 (兼容 C++17 | GCC支持不可低于C++17!) 
GitHub: [https://github.com/ozhnolove/CatHash](https://github.com/ozhnolove/CatHash)

这是一个 15 岁开发者从零手写的 SHA256 实现，包含：
- OK SHA256 核心算法
- OK 十六进制转换
- OK 随机盐生成
- OK 密码哈希
- OK 常量时间比较（防时序攻击）

---

## 特性&说明

| 特性 | 说明 |
|------|------|
| 纯手写 | 没看 OpenSSL 源码，每一行都是自己写的 |
| 安全 | 支持盐值、常量时间比较 |
| 轻量 | 无外部依赖，直接包含头文件CMake连接即可使用 |
| 简单 | API 设计简洁，上手容易 |
| 注意 | 未经安全审计，大项目请用 OpenSSL |

---

## 见此快速开始

### 1. 克隆项目
```bash
git clone https://github.com/ozhnolove/CatHash.git

cd CatHash
./UserGuide | Look at user guide program!
```
### 2.创建方法对象
```cpp
#include "Cathash.hpp"
//Create cathash method object
CatHash::HASH256 hash256_method_obj;
```
### 3.使用对象获取哈希值
```cpp
//Note that getting the hash by default returns a string type
const std::string hash_str =  hash256_method_obj.fetchHash256("Hello open source author!")
```
### 4.字符哈希转二进制
```cpp
//Use this method if you need to convert back to binary
const std::vector<uint8_t> testing_hash_binary = hash256_method_obj.hashStrtoUint8(testing_hash_str);
```
### 5.二进制转回字符
```cpp
const std::string testing_binary_to_str = hash256_method_obj.hashUint8toStr(testing_hash_binary);
```
### 6.密码加盐存入数据库
```cpp
//This is how you add a password
const std::string databese_password = "P0xc200"; //Database passowrd
const std::string salt_ = hash256_method_obj.generateSalt(); //Get salt
const std::string database_hex = hash256_method_obj.fetchHash256(databese_password); //Convert Hash
/**!!! My password verification method removes the ':' so you don't need to remove it yourself.*/
const std::string database_hex_salt_password = salt_ + ":" + database_hex; //Add salt
//After this, your addition logic depends on your ORM methods
```
### 7.验证密码
##
    Of course, this is a simple verification. If your password has salt protection 
    and you need it for personal project user password security, 
    you should use CatHash's password verification method. 
    This method uses time-constant comparison and automatic salt generation. Of course,
    the implementation is very simple; after all, I also feel it's quite basic. 
    At least it can prevent hackers since SHA-256 is irreversible, but it is not recommended for 
    large projects because my hash iteration count is very low. I will add more in the future Thank you for your support
##
```cpp
//Explanation of Password Verification Methods
const std::string error_password_hex = hash256_method_obj.fetchHash256(error_password);
if (hash256_method_obj.verifyHashPassword(error_password_hex, database_hex_salt_password)){
    //Password under normal circumstances
    std::cout << "Password correct" << std::endl;
}
else {
    //Password In case of error
    std::cout << RED << "Password error" << std::endl;
}
```
