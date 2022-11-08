/**
 * @file auto_unique.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief why unique_ptr is better than auto_ptr
 * @version 0.1
 * @date 2022-11-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <iostream>
#include <memory>


std::unique_ptr<std::string> get(const char *str)
{
    std::unique_ptr<std::string> temp (new std::string(str));
    return temp;
}


int main(int argc, char **argv)
{
    /* std::auto_ptr<std::string> p1(new std::string("auto"));
    std::auto_ptr<std::string> p2;
    p2 = p1; */

    std::unique_ptr<std::string> p3 (new std::string("unique"));
    std::unique_ptr<std::string> p4;
    // p4 = p3;

    std::unique_ptr<std::string> pu1 (new std::string("Hi ho!"));
    std::unique_ptr<std::string> pu2;
    // pu2 = pu1;
    pu2 = std::unique_ptr<std::string>(new std::string("Yo!"));

    /* but if i want to use such as pu2 = pu1, how can i do? */
    std::unique_ptr<std::string> ps1, ps2;
    ps1 = get("uniquely special");
    std::unique_ptr<std::string> tmp (new std::string(" and more."));
    ps2 = std::move(tmp);
    std::cout << *ps1 << *ps2 << std::endl;
    
    /* array */
    std::unique_ptr<double []> pda (new double(5));

    return 0;
}