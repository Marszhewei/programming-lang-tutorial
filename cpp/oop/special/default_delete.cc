/**
 * @file default_delete.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief use default and delete
 * @version 0.1
 * @date 2022-11-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <iostream>


class C1
{
public:
    C1() = default;
    C1(const C1 &) = default;
    C1 &operator=(const C1 &) = default;
    void redo(double x) { std::cout << x << std::endl; }
};

class C2
{
public:
    void redo(double x) { std::cout << x << std::endl;}
    void redo(int x) = delete;
};

void C2::redo(int x) { std::cout << x << std::endl; }


int main(int argc, char **argv)
{
    C1 c1;
    c1.redo(5);

    C2 c2;
    c2.redo(5.0);
    // c2.redo(5); not allowed

    return 0;
}