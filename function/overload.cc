/**
 * @file overload.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief function overload
 * @version 0.1
 * @date 2022-10-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <string>

// use default parameters
int add(int a, int b = 0);
double add(double a, double b);
std::string add(std::string s1, std::string s2);

// overload reference function
void sink(double &r);       // matches modifiable lvalue
void sink(const double &r); // matches modifiable or const lvalue, rvalue
void sink(double &&r);      // matches rvalue
/* call the best matching version */


int main(int argc, char **argv)
{
    int a = 10, b = 20;
    std::cout << add(a, b) << std::endl;
    std::cout << add(a) << std::endl;

    double a1 = 3.14, b1 = 20.0;
    std::cout << add(a1, b1) << std::endl;

    std::string s1 = "hello", s2 = ", fetch150zy";
    std::cout << add(s1, s2) << std::endl;

    return 0;
}


int add(int a,int b)
{
    return a + b;
}


double add(double a, double b)
{
    return a + b;
}


std::string add(std::string s1, std::string s2)
{
    return s1 + s2;
}
