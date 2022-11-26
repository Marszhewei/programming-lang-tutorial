/**
 * @file inline.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief inline function
 * @version 0.1
 * @date 2022-10-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>

// here we use inline function
inline double square(double x) { return x * x; }
// here we use macro
#define SQUARE(x) \
        (x * x)

int main(int argc, char **argv)
{
    double x = 1.4;
    // use macro
    std::cout << square(x) << std::endl;
    // use inline function
    std::cout << SQUARE(x) << std::endl;

    return 0;
}

