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


class BS
{
private:
    int q;
    double w;
public:
    BS() : q(0), w(0) {}
    BS(int k) : q(k), w(100) {}
    BS(double x) : q(-1), w(x) {}
    BS(int k, double x) : q(k), w(x) {}
    void show() const { std::cout << q << ", " << w << '\n'; }
};

class DR : public BS
{
private:
    short j;
public:
    using BS::BS;
    DR() : j(-100) {}
    DR(double x) : BS(2 * x), j(int(x)) {}
    DR(int i) : j(-2), BS(i, 0.5 * i) {}
    void show() const { std::cout << j << ", "; BS::show(); }
};



int main(int argc, char **argv)
{
    C2 c2;
    c2.fn(3.4);


    DR o1;              // use DR()
    DR o2(18.81);       // use DR(double) instead of BS(double)
    DR o3(10, 1.8);     // use BS(int, double)

    return 0;
}