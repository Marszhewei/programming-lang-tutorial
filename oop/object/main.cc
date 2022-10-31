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

#include "calc.h"


int main(int argc, char **argv)
{
    using XDU::Calc;
    int32_t x = 3, y = 4;
    Calc c(x, y);
    // or
    // Calc c = Calc(x, y);
    std::pair<int32_t, int32_t> p = c.get_pos();
    std::cout << "posx : " << p.first << ',' << "posy : " << p.second << std::endl;

    Calc a;
    a.set_pos(5, 6);
    a.calc_area();
    std::cout << "area is: " << a.get_area() << std::endl;

    // const 

    return 0;
}