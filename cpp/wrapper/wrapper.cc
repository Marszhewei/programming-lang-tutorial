/**
 * @file wrapper.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief wrapper (adapter)
 * @version 0.1
 * @date 2022-11-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "defs.h"

#include <functional>


double dub(double x) { return x * 2.0; }
double square(double x) { return x * x; }

int main(int argc, char **argv)
{
    double y = 1.2;
    std::function<double(double)> ef1 = dub;
    std::function<double(double)> ef2 = square;
    std::function<double(double)> ef3 = Fp(10.0);
    std::function<double(double)> ef4 = Fq(10.0);
    std::function<double(double)> ef5 = [](double x) -> double { return x * x; };
    std::function<double(double)> ef6 = [](double x) -> double { return x + x / 2.0; };
    std::cout << "function pointer dub:\n";
    std::cout << ' ' << use_f(y, ef1) << std::endl;
    std::cout << "function pointer square:\n";
    std::cout << ' ' << use_f(y, ef2) << std::endl;
    std::cout << "function object Fp:\n";
    std::cout << ' ' << use_f(y, ef3) << std::endl;
    std::cout << "function object Fq:\n";
    std::cout << ' ' << use_f(y, ef4) << std::endl;
    std::cout << "lambda expression 1:\n";
    std::cout << ' ' << use_f(y, ef5) << std::endl;
    std::cout << "lambda expression 2:\n";
    std::cout << ' ' << use_f(y, ef6) << std::endl;

    return 0;
}