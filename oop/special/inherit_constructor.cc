/**
 * @file inherit_constructor.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>

namespace Box
{
    int fn(int x) {}
    int fn(double x) {}
    int fn(const char *) {}   
}
using Box::fn;      // we can use three fn


class C1
{
public:
    int fn(int x) {}
    double fn(double x) { std::cout << "c1\n"; }
    void fn(const char *) {}
};

class C2 : public C1
{
public:
    using C1::fn;
    double fn(double x) { std::cout << "c2\n"; }
};


int main(int argc, char **argv)
{
    C2 c2;
    c2.fn(3.4);

    return 0;
}