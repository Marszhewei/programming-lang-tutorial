/**
 * @file static_cast.cc
 * @author fetch150zy (Mars_zhewei@Outlook.com)
 * @brief static cast
 * @version 0.1
 * @date 2022-11-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <iostream>

class High {};
class Low : public High {};
class Bond {};


int main(int argc, char **argv)
{
    High bar;
    Low foo;
    High *ph = static_cast<High *>(&foo);
    Low *pl = static_cast<Low *>(&bar);
    // Bond *pb = static_cast<Bond *>(&bar);
    // Bond *pb = static_cast<Bond *>(&foo); invalid, bond unrelated

    /* for basic type */
    double a;
    int32_t b = static_cast<long>(a);

    return 0;
}