/**
 * @file enum.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief some skills about enum
 * @version 0.1
 * @date 2022-10-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>


int main(int argc, char **argv)
{
    // can't pass compile
    /* enum egg {Small, Medium, Large, Jumbo};
    enum t_shirt {Small, Medium, Large, Xlarge}; */
    // use enum class
    enum egg {Small, Medium, Large, Jumbo};
    enum class t_shirt {Small, Medium, Large, Xlarge};
    // or
    /* enum struct egg {Small, Medium, Large, Jumbo};
    enum struct t_shirt {Small, Medium, Large, Xlarge}; */

    egg choice = Large;
    // or
    // egg choice = egg::Large;
    t_shirt floyd = t_shirt::Xlarge;
    // can explicit type conversion
    int32_t temp = int32_t(t_shirt::Medium);
    std::cout << "t_shirt::Medium to int32_t => " << temp << std::endl;

    // set the default type of enum class
    enum class pizza : uint8_t {Small, Medium, Large, Xlarge};

    return 0;
}