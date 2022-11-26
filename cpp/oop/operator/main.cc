/**
 * @file main.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "time.h"


int main(int argc, char **argv)
{
    Time planning;
    Time coding(2, 40);
    Time fixing(5, 55);
    Time total;

    std::cout << "planning time = ";
    planning.show();

    std::cout << "coding time = ";
    coding.show();

    std::cout << "fixing time = ";
    fixing.show();

    total = coding + fixing;
    std::cout << "total = ";
    total.show();

    total = fixing - coding;
    std::cout << "total = ";
    total.show();

    // total = coding * 3;
    total = 3 * coding;
    std::cout << "total = " << total << std::endl;

    double dms = double(total);
    int32_t ims = int32_t(total);
    std::cout << "dms is: " << dms << ", ims is: " << ims << std::endl;
    // but if i want to use int64_t
    // int64_t lms = total;    not allowed
    int64_t lms = int32_t(total);

    return 0;
}

/* double + obj ? */
// operator+(const OBJ &obj1, const OBJ &obj2);
// or
// OBJ operator+(double x);                        member function
// friend OBJ operator+(double x, OBJ &obj);
