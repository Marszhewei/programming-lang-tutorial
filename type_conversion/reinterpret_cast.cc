/**
 * @file reinterpret_cast.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief reinterpret cast
 * @version 0.1
 * @date 2022-11-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <iostream>


int main(int argc, char **argv)
{
    struct dat { short a; short b; };
    long value = 0xa224b118;
    dat *pd = reinterpret_cast<dat *>(&value);
    std::cout << std::hex << pd->a << std::endl;

    return 0;
}