/**
 * @file error.h
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef ERROR_H_
#define ERROR_H_

#include <iostream>


class BadHmean
{
private:
    double v1;
    double v2;
public:
    BadHmean(double a = 0, double b = 0) : v1(a), v2(b) {}
    void mesg() const;
};

inline void BadHmean::mesg() const
{
    std::cout << "hmean(" << this->v1 << ", " << this->v2
              << "): invalid arguments: a = -b\n";
}


class BadGmean
{
public:
    double v1;
    double v2;

    BadGmean(double a = 0, double b = 0) : v1(a), v2(b) {}
    const char *mesg() const;
};

inline const char *BadGmean::mesg() const
{
    return "gmean() arguments should be >= 0\n";
}


#endif

