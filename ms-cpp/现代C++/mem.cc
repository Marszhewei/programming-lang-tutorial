/**
 * @file mem.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 内存对齐
 * @version 0.1
 * @date 2022-12-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>

extern constexpr int x = 10;
struct alignas(8) x_ { // sum = 16 bytes
    alignas(1) char a; // 1 byte
    // alignas(4) int b; // 4 bytes
    alignas(2) short c; // 2 bytes
    alignas(1) char d; // 1 byte
};

struct x__ {// sum = 12 bytes
    char a; // 1 byte
    char _pad0[3]; // padding 3 bytes
    int b; // 4 bytes
    short c; // 2 bytes
    char d; // 1 byte
    char _pad1[1]; // padding 1 byte
};

struct y_ { // sum = 8 bytes
    char a; // 1 byte
    char d; // 1 byte
    short c; // 2 byte
    int b; // 4 bytes
};

int main(int argc, char **argv)
{
    std::cout << sizeof(x_) << std::endl;
    std::cout << "=> " << alignof(x_) << std::endl;
    // std::cout << "=> " << alignof(char) << std::endl;
    // std::cout << "=> " << alignof(short) << std::endl;
    // std::cout << "=> " << alignof(int) << std::endl;
    std::cout << sizeof(x__) << std::endl;
    std::cout << "=> " << alignof(x__) << std::endl;
    std::cout << sizeof(y_) << std::endl;
    std::cout << "=> " << alignof(y_) << std::endl;
    std::cout << x << std::endl;

    return 0;
}