/**
 * @file demo.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>


class bad_1 {};
class bad_2 {};
class bad_3 {};

void duper(bool oh_no, bool rats, bool drat)
{
    if (oh_no)
        throw bad_1();
    if (rats)
        throw bad_2();
    if (drat)
        throw bad_3();
}

int main(int argc, char **argv)
{
    try {
        duper(true, false, false);
    } catch (bad_3 &be) {
        std::cout << "cause bad_1 exception.\n";
    } catch (bad_2 &be) {
        std::cout << "cause bad_2 exception.\n";
    } catch (bad_3 &be) {
        std::cout << "cause bad_3 exception.\n";
    } catch (...) {
        std::cout << "unkonw exception.\n"; 
    }
}