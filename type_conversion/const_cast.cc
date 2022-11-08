/**
 * @file const_cast.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief const_cast
 * @version 0.1
 * @date 2022-11-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <iostream>


void change(const int32_t *pt, int32_t n);


int main(int argc, char **argv)
{
    int32_t pop1 = 38383;
    const int32_t pop2 = 2000;

    std::cout << "pop1, pop2: " << pop1 << ", " << pop2 << std::endl;
    change(&pop1, -103);
    change(&pop2, -103);
    // pop1 not changed, pop2 changed
    std::cout << "pop1, pop2: " << pop1 << ", " << pop2 << std::endl;

    return 0;
}


void change(const int32_t *pt, int32_t n)
{
    int32_t *pc;
    pc = const_cast<int32_t *>(pt);
    *pc += n;
}
