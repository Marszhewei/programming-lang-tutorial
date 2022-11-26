/**
 * @file ref.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief something about reference
 * @version 0.1
 * @date 2022-10-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <cstdint>
#include <iostream>
#include <string>


struct free_throws
{
    std::string name;
    int32_t made;
    int32_t attempts;
    _Float32 percent;
};

void test_reference(int32_t &n);
void test_const_reference(const int32_t &pn); 
void swapv(int32_t &a, int32_t &b);
void test_rval_reference(int32_t &&n);

void display(const free_throws &ft);
void set_pc(free_throws &ft);
free_throws &accumulate(free_throws &target, const free_throws &source);


int main(int argc, char **argv)
{
    int vala = 10;
    int &valb = vala;
    std::cout << "vala => " << vala << ',' << "valb => " << valb << std::endl;
    valb += 2;
    std::cout << "vala => " << vala << ',' << "valb => " << valb << std::endl;
    // check vala and valb address
    std::cout << "vala ptr => " << &vala << ',' << "valb ptr => " << &valb << std::endl;
    /*
    * the reference like const ptr
    */
  
    // reference in function
    int32_t n = 100;
    std::cout << "n: " << n << std::endl;
    test_reference(n);
    std::cout << "n: " << n << std::endl;

    int32_t a = 10, b = 20;
    std::cout << a << ' ' << b << std::endl;
    swapv(a, b);
    std::cout << a << ' ' << b << std::endl;

    // const reference
    test_const_reference(n + 100);
    std::cout << n << std::endl;

    // rvalue reference is used to move semantics
    test_rval_reference(n + 1000);
    std::cout << n << std::endl;

    // use reference in struct
    free_throws one = {"Ifelsa Branch", 13, 14};
    free_throws two = {"Andor Knott", 10, 16};
    free_throws three = {"Minnie Max", 7, 9};
    free_throws four = {"Whily Looper", 5, 9};
    free_throws five = {"Long Long", 6, 14};
    free_throws team = {"Throwgoods", 0, 0};
    // no initialization
    free_throws dup;

    set_pc(one);
    display(one);
    accumulate(team, one);
    display(team);
    // use return value as argument
    display(accumulate(team, two));
    accumulate(accumulate(team, three), four);
    display(team);
    // use return value in assignment
    dup = accumulate(team, five);
    std::cout << "displaying team:" << std::endl;
    display(team);
    std::cout << "displaying dup after assignment:" << std::endl;
    display(dup);
    set_pc(four);
    // ill-advised assigment
    accumulate(dup, five) = four;
    std::cout << "displaying dup after ill-advised assigment:" << std::endl;
    display(dup);

    return 0;
}


void test_reference(int32_t &n)
{
    --n;
}


void test_const_reference(const int32_t &pn)
{
    // pn++;
    std::cout << pn << std::endl;
}


void swapv(int32_t &a, int32_t &b)
{
    int32_t t = a;
    a = b;
    b = t;
}


void test_rval_reference(int32_t &&n)
{
    std::cout << n << std::endl;
    n++; // it doesn't work, the n in main is not changed
}


void display(const free_throws &ft)
{
    std::cout << "Name: " << ft.name << std::endl;
    std::cout << "  Made: " << ft.made << '\t';
    std::cout << "Attempts: " << ft.attempts << '\t';
    std::cout << "Precent: " << ft.percent << std::endl;
}


void set_pc(free_throws &ft)
{
    if (0 != ft.attempts)
        ft.percent = 100.0f * _Float32(ft.made) / _Float32(ft.attempts);
    else
        ft.percent = 0;
}


free_throws &accumulate(free_throws &target, const free_throws &source)
{
    target.attempts += source.attempts;
    target.made += source.made;
    set_pc(target);
    return target;
}
