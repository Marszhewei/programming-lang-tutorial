/**
 * @file chose_ptr.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief how to chose smart pointer
 * @version 0.1
 * @date 2022-11-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <iostream>
#include <memory>
#include <vector>
#include <cstdlib>
#include <ctime>


std::unique_ptr<int> make_it(int n)
{
    return std::unique_ptr<int> (new int(n));
}


void show1(std::unique_ptr<int> &pi)
{
    std::cout << *pi << std::endl;
}


int main(int argc, char **argv)
{
    std::srand(std::time(0));
    std::vector<std::unique_ptr<int>> vp(10);
    for (int i = 0; i < vp.size(); ++i) {
        vp[i] = make_it(std::rand() % 1000);
    }
    vp.push_back(make_it(std::rand() % 1000));
    for (int i = 0; i < vp.size(); ++i) {
        show1(vp[i]);
    }

    return 0;
}
