/**
 * @file delegate.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <iostream>
#include <string>


class Notes
{
private:
    int k;
    double x;
    std::string st;
public:
    Notes();
    Notes(int);
    Notes(int, double);
    Notes(int, double, std::string);
};

Notes::Notes(int kk, double xx, std::string stt)
            : k(kk), x(xx), st(stt) {}

Notes::Notes() : Notes(0, 0.01, "Oh") {}

Notes::Notes(int kk) : Notes(kk, 0.01, "Oh") {}

Notes::Notes(int kk, double xx) : Notes(kk, xx, "Oh") {}