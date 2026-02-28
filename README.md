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

### 7. Password Verification
##
I evolved from simple verification to combining salts and hashes. While this is still relatively basic, it's hard to measure its true complexity; at least the core part is most important. For me, it works well enough—and I would use it myself.
##
```cpp
// Explanation of Password Verification Methods
const std::string error_password_hex = hash256_method_obj.fetchHash256(error_password);
if (hash256_method_obj.verifyHashPassword(error_password_hex, database_hex_salt_password)) {
    // Password is correct
    std::cout << "Password correct" << std::endl;
}
else {
    // Password is incorrect
    std::cout << RED << "Password error" << std::endl;
}
```

### 8. Password Iteration

```cpp
// Obtain a hashed password
const std::string hex_var = hash256_method_obj.fetchHash256("xs9s9");
// Now, apply iterations
/**
 * @note The more iterations you set here, the slower the computation and the more server resources are consumed. 
 * This is your own decision—as an adult 🌚
 */
hash256_method_obj.setHashIteration(111111); 
// Recommend one million to balance user experience
// Of course, this is also very secure

// When generating a random salt
const std::string salt = hash256_method_obj.generateSalt();
// Now you have a password that has been hashed multiple times along with a salt.
// You can store it in your database as 'salt : hashed'
const std::string hash_password = hash256_method_obj.getHashPasswordaddIteration(hex_var, salt);
// For reference: I use 'salt' combined with a repeatedly iterated hashed password,
// using 'salt iterated (salt hashed)' for passwords. This is very secure—well, I'm not totally sure, 
// but at least ordinary hackers can't crack it. If your project is huge, I don't recommend you use this.
```

### 9. Verifying an Iterated Password
##
It’s worth mentioning that this time, verification is done by comparing the combination of salt and hash, which is much safer than basic checks. Also, this verification does not require you to hash the password first; you can directly insert the string.
##
```cpp
// The right side is the value provided by the user, and the left side should be fetched from the database—the one you stored.
// Then, proceed with verification. Rest assured, it works just like regular verification,
// using constant-time operations and additional byte checks to prevent DDoS and excessive memory usage (must not exceed 1024*1024).
// Of course, storing also performs verification.
if (hash256_method_obj.verifyHashPasswordIteration("xs9s9", hash_password)) {
    std::cout << "LOGIN SUCCESS!" << std::endl;
} else {
    std::cout << "LOGIN FAIL!" << std::endl;
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
##
Я начал с простой проверки и постепенно перешёл к проверке с использованием соли и хэша. Это по-прежнему относительно просто, сложно судить о реальной сложности; по крайней мере, главное — это основная часть, и для меня этого более чем достаточно, я сам бы это использовал.
##
```cpp
// Объяснение методов проверки пароля
const std::string error_password_hex = hash256_method_obj.fetchHash256(error_password);
if (hash256_method_obj.verifyHashPassword(error_password_hex, database_hex_salt_password)) {
    // Пароль верный
    std::cout << "Пароль верный" << std::endl;
}
else {
    // Неверный пароль
    std::cout << RED << "Ошибка пароля" << std::endl;
}
```

### 8. Итерация пароля

```cpp
// Получение хэшированного пароля
const std::string hex_var = hash256_method_obj.fetchHash256("xs9s9");
// Теперь сделаем несколько итераций
/**
 * @note Чем больше итераций, тем медленнее вычисления и больше нагрузка на сервер.
 * Решайте сами, ведь вы взрослый человек 🌚
 */
hash256_method_obj.setHashIteration(111111); 
// Рекомендуется миллион, чтобы сбалансировать пользовательский опыт
// Конечно, это также очень безопасно

// При генерации случайной соли
const std::string salt = hash256_method_obj.generateSalt();
// Теперь у вас есть пароль, прошедший хэширование и итерации вместе с солью.
// Его можно хранить в базе данных в формате "соль : хэш"
const std::string hash_password = hash256_method_obj.getHashPasswordaddIteration(hex_var, salt);
// К слову: я использую 'соль' в сочетании с многократно итерированным хэшем пароля,
// то есть 'итерации соли (соль + хэш)' для пароля. Это очень безопасно, хотя я не уверен на 100%,
// но обычный хакер это не взломает. Если у вас крупный проект — не советую использовать такой способ.
```

### 9. Проверка многократно итерированного пароля
##
Стоит отметить: в этот раз я сравниваю сочетание соли и хэша — это намного безопаснее стандартной проверки. Причём для этой проверки не нужно сначала хэшировать пароль, можно сразу вставить строку.
##
```cpp
// Справа значение, введённое пользователем, слева — то, что хранится в базе данных (то, что вы сохранили).
// Только после этого выполняется проверка. Можете не беспокоиться: она работает так же, как обычная проверка,
// использует сравнение в постоянное время и добавленные байтовые проверки для предотвращения DDoS и лишней нагрузки на память (не более 1024*1024).
// Конечно, при сохранении тоже идёт проверка.
if (hash256_method_obj.verifyHashPasswordIteration("xs9s9", hash_password)) {
    std::cout << "ВХОД УСПЕШЕН!" << std::endl;
} else {
    std::cout << "ОШИБКА ВХОДА!" << std::endl;
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
我从简单的验证发展到结合盐值和哈希一起验证，但这仍然相对简单，很难说有多复杂；
至少核心部分是最重要的，至少这真的够用了，而且我自己也会使用它。
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

### 8.给你的密码迭代

```cpp
//Obtain a hashed password
const std::string hex_var = hash256_method_obj.fetchHash256("xs9s9");
//Now iterate for him
/**
*@note Note that the more iterations here, the slower the computation and the higher the server consumption. This is your own choice because you are an adult 🌚
*/
hash256_method_obj.setHashIteration(111111); 
//Recommend one million to balance your user experience
//Of course, it is also very safe

//When obtaining a random salt
const std::string salt = hash256_method_obj.generateSalt();
//Okay, now you have a password that has been hashed multiple times with a hash and random salt, and you can store it in your database in the format 'salt : hashed'
const std::string hash_password = hash256_method_obj.getHashPasswordaddIteration(hex_var , salt);
//Also, a reminder: I am using 'stal' combined with a hashed password iterated multiple times, using 'stal iterated('stal' hashed)' for the password. This is very secure, okay, I'm not sure, but at least ordinary hackers can't break it. If your project is huge, I don't recommend you use this
```
### 9.给迭代多次的密码进行验证
##
It is worth mentioning that this time I am verifying by comparing the salt plus hash value, which is much safer than ordinary verification. Note that this verification does not require you to hash it once before verifying directly insert the string
##
```cpp
//The right side is the value requested by the user, and the left side needs to pass in the real correct value from the database, that is, the one you stored, and then perform verification. Rest assured, it is the same as the regular verification method, using constant-time and adding byte verification to prevent DDoS and excessive memory pressure, which must not exceed 1024*1024 of course, depositing also verifies
if (hash256_method_obj.verifyHashPasswordIteration("xs9s9", hash_password)){
    std::cout << "LOGIN SUCCESS!" << std::endl;
}else {
    std::cout << "LOGIN FAIL!" << std::endl;
}
```