/**
 * @file const_pointer.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief const ptr and ptr const
 * @version 0.1
 * @date 2022-10-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */
 
#include <iostream>

int main(int argc, char **argv)
{
    // we can change the value of ptr, but can't change the value of *ptr
    int a = 10, b = 20;
    const int *pa = &a;
    pa = &b;
    // *pa = b;
    std::cout << std::hex << pa << ' ' << std::dec << *pa << std::endl;

    // we can change the value of *ptr, but can't change the value of ptr
    int * const cp = new int;
    // cp = &a;
    *cp = a;
    std::cout << std::hex << cp << ' ' << std::dec << *cp << std::endl;
    delete cp;
    // cp = nullptr;

    // we can't change the value of *ptr and ptr
    const int * const p = new int;
    // p = &a;
    // *p = b;
    std::cout << std::hex << p << ' ' << std::dec << *p << std::endl;

    return 0;
}