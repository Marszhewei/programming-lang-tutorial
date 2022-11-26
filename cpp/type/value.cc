/**
 * @file value.cc
 * @author fetch50zy (Mars_zhewei@outlook.com)
 * @brief lvalue rvalue glvalue prvalue xvalue
 * @version 0.1
 * @date 2022-10-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>

int32_t &func()
{
    int32_t x = 100;
    return x;
}

int main(int argc, char **argv)
{
    /* lvalue rvalue prvalue glvalue xvalue */
    /* glvalue = lvalue + xvalue, rvalue = prvalue + xvalue */
    // 能取地址或者是有名字的变量就是左值，不能取地址（表达式产生的中间值）就是纯右值，对纯右值取引用就是亡值
    // int32_t lv, *p;    // lv is lvalue
    // lv = 31;            // 31 is prvalue
    // p = &lv;
    int32_t x = &(1 + 2);
    std::cout << x << std::endl;


    /* <=> */
    int32_t a = 10, b = 11;
    // std::cout << "a <=> b : " << (a <=> b) << std::endl
    //           << "b <=> a : " << (b <=> a) << std::endl;

    return 0;
}