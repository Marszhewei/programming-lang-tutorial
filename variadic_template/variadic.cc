/**
 * @file variadic.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <string>

// definition for 0 paraments -- terminating call
void show_list() {}

template <typename T>
void show_list(const T& value)
{
    std::cout << value << std::endl;
}

template <typename T, typename... Args>
void show_list(T value, Args... args)
{
    std::cout << value << ", ";
    show_list(args...);
}


int main(int argc, char **argv)
{
    int n = 14;
    double x = 2.71828;
    std::string mr = "Mr. String objects!";
    show_list(n, x);
    show_list(x * x, '!', 7, mr);

    return 0;
}