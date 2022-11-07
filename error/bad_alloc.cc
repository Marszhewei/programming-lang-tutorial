/**
 * @file bad_alloc.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <new>
#include <iostream>
#include <cstdlib>


const uint32_t SIZE = 200000;

struct Big
{
    double stuff[SIZE];
};


int main(int argc, char **argv)
{
    Big *pb;
    try {
        std::cout << "trying to get a big block of memory:\n";
        pb = new Big[SIZE / 2];
        std::cout << "got past the new request:\n";
    } catch (std::bad_alloc &ba) {
        std::cout << "caught the exception!\n";
        std::cout << ba.what() << std::endl;
        exit(EXIT_FAILURE);
    }
    // or (use return nullptr if new error)
    pb = new (std::nothrow) Big[SIZE / 2];
    if (nullptr == pb) {
        std::cout << "could not allocate memory. bye.\n";
        exit(EXIT_FAILURE);
    }
     
    std::cout << "memory sucessfully allocated\n";
    pb[0].stuff[0] = 4;
    std::cout << pb[0].stuff[0] << std::endl;
    delete [] pb;

    return 0;
}