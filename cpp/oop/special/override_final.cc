/**
 * @file override_final.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief manage virtual methods
 * @version 0.1
 * @date 2022-11-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>


class Action
{
private:
    int a;
public:
    Action(int i = 0) : a(i) {}
    int val() const { return a; }
    virtual void f(char ch) const final { std::cout << val() << ch << '\n'; }
};

class Bingo : public Action
{
public:
    Bingo(int i = 0) : Action(i) {}
    // virtual void f(char ch) const override { std::cout << val() << ch << "\n"; }
    virtual void f(char *ch) const { std::cout << val() << ch << "!\n"; }
};


int main(int argc, char **argv)
{
    Bingo b(10);
    // b.f('a');
    b.f("A");

    return 0;
}