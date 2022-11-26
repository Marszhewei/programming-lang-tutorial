/**
 * @file main.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "multi_inherit.h"

#include <cstring>


// const int32_t LIM = 4;
const int32_t SIZE = 5;

int main(int argc, char **argv)
{
    /* Waiter bob("bob apple", 314, 5);
    Singer bev("beverly hills", 522, 3);
    Waiter w_temp;
    Singer s_temp;

    Worker *pw[LIM] = {&bob, &bev, &w_temp, &s_temp};
    
    for (int i = 2; i < LIM; ++i)
        pw[i]->set();
    for (int i = 0; i < LIM; ++i) {
        pw[i]->show();
        std::cout << std::endl;
    } */
    
    Worker *lolas[SIZE];
    int32_t ct;
    for (ct = 0; ct < SIZE; ++ct) {
        char choice;
        std::cout << "enter the employee category:\n"
                  << "w: waiter  s: string  t: singing waiter  q: quit\n";
        std::cin >> choice;
        while (strchr("wstq", choice) == NULL) {
            std::cout << "please enter w s t, or q: ";
            std::cin >> choice;
        }
        if (choice == 'q')
            break;
        switch(choice)
        {
            case 'w':   lolas[ct] = new Waiter;
                        break;
            case 's':   lolas[ct] = new Singer;
                        break;
            case 't':   lolas[ct] = new SingingWaiter;
                        break;
        }
        std::cin.get();
        lolas[ct]->set();
    }

    std::cout << "\nhere is your staff:\n";
    for (int i = 0; i < ct; ++i) {
        std::cout << std::endl;
        lolas[i]->show();
    }
    for (int i = 0; i < ct; ++i)
        delete lolas[i];
    std::cout << "done.\n";

    return 0;
}