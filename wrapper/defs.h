/**
 * @file defs.h
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief some defs
 * @version 0.1
 * @date 2022-11-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef DEFS_H_
#define DEFS_H_

#include <iostream>
#include <functional>

template <typename T, typename F>
T use_f(T v, F f)
{
    static int cnt = 0;
    ++cnt;
    std::cout << " use_f cnt = " << cnt << ", &cnt = " << &cnt << std::endl;
    return f(v);
}
// or a nice way
template <typename T>
T use_f(T v, std::function<T(T)> f)
{
    static int cnt = 0;
    ++cnt;
    std::cout << " use_f cnt = " << cnt << ", &cnt = " << &cnt << std::endl;
    return f(v);
}
// and we can use it by fallows
/* std::cout << use_f<double>(y, dub) << std::endl; */


class Fp
{
private:
    double z_;
public:
    Fp(double x = 1.0) : z_(x) {}
    double operator()(double x) { return x * z_; }
};

class Fq
{
private:
    double z_;
public:
    Fq(double x = 1.0) : z_(x) {}
    double operator()(double x) { return x + z_; }
};

#endif

