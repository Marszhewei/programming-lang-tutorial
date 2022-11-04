/**
 * @file main.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include "abc.h"


const int32_t CLIENTS = 4;

int main(int argc, char **argv)
{
    /* Brass piggy("porcelot piggy", 381299, 4000.0);
    BrassPlus hoggy("horatio hoggy", 382288, 3000.0);
    piggy.view_acct();
    std::cout << std::endl;
    hoggy.view_acct();
    std::cout << std::endl;
    std::cout << "depositing $1000 into the hoggy account:\n";
    hoggy.deposit(1000.0);
    std::cout << "new balance: $" << hoggy.get_balance() << std::endl;
    std::cout << "withdraw $4200 from the piggy account:\n";
    piggy.with_draw(4200.0);
    std::cout << "piggy account balance: $" << piggy.get_balance() << std::endl;
    std::cout << "withdraw $4200 from the hoggy account:\n";
    hoggy.with_draw(4200.0);
    hoggy.view_acct(); */


    // check virtual function
    AcctABC *p_client[CLIENTS];
    std::string temp;
    uint32_t temp_num;
    double temp_balance;
    char kind;

    for (int i = 0; i < CLIENTS; ++i) {
        std::cout << "enter client's name: ";
        getline(std::cin, temp);
        std::cout << "enter client's account number: ";
        std::cin >> temp_num;
        std::cout << "enter opening balance: $";
        std::cin >> temp_balance;
        std::cout << "enter 1 for Brass account or 2 for brass BrassPlus account: ";
        while (std::cin >> kind && (kind != '1' && kind != '2'))
            std::cout << "enter either 1 or 2: ";
        if (kind == '1') {
            p_client[i] = new Brass(temp, temp_num, temp_balance);
        } else {
            double tmax, trate;
            std::cout << "enter the overdraft limit: $";
            std::cin >> tmax;
            std::cout << "enter the interest rate as a decimal fraction: ";
            std::cin >> trate;
            p_client[i] = new BrassPlus(temp, temp_num, temp_balance, tmax, trate);
        }
        while (std::cin.get() != '\n')
            continue;
    }
    std::cout << std::endl;
    for (int i = 0; i < CLIENTS; ++i) {
        p_client[i]->view_acct();
        std::cout << std::endl;
    }
    for (int i = 0; i < CLIENTS; ++i) {
        delete p_client[i];
    }
    std::cout << "done.\n";

    return 0;
}