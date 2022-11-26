/**
 * @file strfile.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief read string from file
 * @version 0.1
 * @date 2022-11-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>


int main(int argc, char **argv)
{
    std::ifstream fin;
    fin.open("tobuy.in");
    if (!fin.is_open()) {
        std::cerr << "can't open file. bye.\n";
        exit(EXIT_FAILURE);
    }
    std::string item;
    int32_t cnt = 0;
    getline(fin, item, ':');
    while (fin) {
        ++cnt;
        std::cout << cnt << ": " << item << std::endl;
        getline(fin, item, ':');
    }
    std::cout << "done.\n";
    fin.close();

    return 0;
}