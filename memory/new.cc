/**
 * @file new.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <new>

const uint8_t BUF_SIZE = 0xff;
const uint8_t N = 5;
uint8_t buffer[BUF_SIZE];

/*1
*   new <=> new(std::size_t)
*   delete <=> delete(std::size_t)
*   void *operator new(std::size_t)
*   void *operator new[](std::size_t)
*   void *operator delete(std::size_t)
*   void *operator delete[](std::size_t)
*/


int main(int argc, char **argv)
{
    int32_t *p1 = new int32_t[N];
    int32_t *p2 = new (buffer) int32_t[N];
    for (int i = 0; i < N; ++i) {
        p1[i] = i + 1000;
        p2[i] = i + 1000;
    }
    std::cout << "The address of new memory in heap => " << p1 << std::endl;
    std::cout << "The address of new memory in static => " << p2 << std::endl;

    for (int i = 0; i < N; ++i) {
        std::cout << std::hex << (p1 + i) << " => " << std::dec << *(p1 + i) << '\t';
        std::cout << std::hex << (p2 + i) << " => " << std::dec << *(p2 + i) << std::endl;
    }

    p1 = new int32_t[N];
    p2 = new (buffer) int32_t[N];
    for (int i = 0; i < N; ++i) {
        p1[i] = i + 1000;
        p2[i] = i + 1000;
    }
    std::cout << "The address of new memory in heap => " << p1 << std::endl;
    std::cout << "The address of new memory in static => " << p2 << std::endl;

    for (int i = 0; i < N; ++i) {
        std::cout << std::hex << (p1 + i) << " => " << std::dec << *(p1 + i) << '\t';
        std::cout << std::hex << (p2 + i) << " => " << std::dec << *(p2 + i) << std::endl;
    }

    p1 = new int32_t[N];
    p2 = new (buffer + 0xf) int32_t[N];
    for (int i = 0; i < N; ++i) {
        p1[i] = i + 1000;
        p2[i] = i + 1000;
    }
    std::cout << "The address of new memory in heap => " << p1 << std::endl;
    std::cout << "The address of new memory in static => " << p2 << std::endl;

    for (int i = 0; i < N; ++i) {
        std::cout << std::hex << (p1 + i) << " => " << std::dec << *(p1 + i) << '\t';
        std::cout << std::hex << (p2 + i) << " => " << std::dec << *(p2 + i) << std::endl;
    }

    delete [] p1;
    p1 = nullptr;
    return 0;
}