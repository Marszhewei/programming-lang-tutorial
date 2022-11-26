/**
 * @file try_catch.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "error.h"

#include <iostream>
#include <cmath>


double hmean(double a, double b);
double gmean(double a, double b);
// ensure the function will not cause error(exception)
double add(double a, double b) noexcept;
// noexcept(expression) check if the expression causes exception


int main(int argc, char **argv)
{
    double x, y;
    std::cout << "enter two numbers: ";
    while (std::cin >> x >> y) {
        try {
            std::cout << "harmonic mean of " << x << " and " << y
                      << " is " << hmean(x, y) << std::endl;
            std::cout << "geometric mean of " << x << " and " << y
                      << " is " << gmean(x, y) << std::endl;
            std::cout << "enter next set of numbers <q to quit>: ";
        } catch (BadHmean &bg) {
            bg.mesg();
            std::cout << "enter a new pair of numbers: ";
            continue;
        } catch (BadGmean &hg) {
            std::cout << hg.mesg();
            std::cout << "vlues used: " << hg.v1 << ", " << hg.v2 << std::endl;
            std::cout << "sorry, you don't get to play any more.\n";
            break;
        }
    }
    std::cout << "done.\n";

    return 0;
}


double hmean(double a, double b)
{
    if (a == -b)
        throw BadHmean(a, b);
    return 2.0 * a * b / (a + b);
}


double gmean(double a, double b)
{
    if (a < 0 || b < 0)
        throw BadGmean(a, b);
    return std::sqrt(a * b);
}


double add(double a, double b)
{
    return a + b;
}