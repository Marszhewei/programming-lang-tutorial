/**
 * @file vector.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief an example about vector
 * @version 0.1
 * @date 2022-11-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <iostream>
#include <vector>
#include <algorithm>


void show(int x)
{
    std::cout << x << ' ';
}


int main(int argc, char **argv)
{
    std::vector<int> v {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::random_shuffle(v.begin(), v.end());
    std::vector<int>::iterator pr;
    for (pr = v.begin(); pr != v.end(); ++pr)
        show(*pr);
    std::cout << std::endl;
    std::for_each(v.begin(), v.end(), show);
    std::cout << std::endl;

    std::sort(v.begin(), v.end());
    for (auto &x: v)
        show(x);
    std::cout << std::endl;

    return 0;
}