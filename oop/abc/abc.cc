/**
 * @file abc.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include "abc.h"


AcctABC::AcctABC(const std::string &name, uint32_t acct_num, double balance)
                 : m_name(name), m_acct_num(acct_num), m_balance(balance) {}


void AcctABC::deposit(double amt)
{
    if (amt < 0)
        std::cout << "negative deposit not allowed; deposit is cancelled.\n";
    else
        this->m_balance += amt;
}


void AcctABC::with_draw(double amt)
{
    this->m_balance -= amt;
}


AcctABC::Formatting AcctABC::set_format() const
{
    Formatting fmt;
    fmt.flag = std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
    fmt.pr = std::cout.precision(2);
    return fmt;
}


void AcctABC::restore(AcctABC::Formatting &fmt) const
{
    std::cout.setf(fmt.flag, std::ios_base::floatfield);
    std::cout.precision(fmt.pr);
}


/* Brass Class Methods */
void Brass::with_draw(double amt)
{
    if (amt < 0)
        std::cout << "withdraw amount must be positive; withdraw cancelled.\n";
    else if (amt <= get_balance())
        AcctABC::with_draw(amt);
    else
        std::cout << "withdraw amount of $" << amt << "exceeds your balance.\n"
                  << "withdraw cancelled.\n";
}


void Brass::view_acct() const
{
    Formatting fmt = set_format();
    std::cout << "brass client: " << get_name() << std::endl;
    std::cout << "account number: " << get_acct_num() << std::endl;
    std::cout << "balance: $" << get_balance() << std::endl;
    restore(fmt); 
}


/* Brass Plus Class Methods */
BrassPlus::BrassPlus(const std::string &name, uint32_t acct_num, double balance,
                     double max_loan, double rate) : AcctABC(name, acct_num, balance)
{
    this->m_max_loan = max_loan;
    this->m_owes_bank = 0.0;
    this->m_rate = rate;
}


BrassPlus::BrassPlus(const Brass &ba, double max_loan, double rate)
                     : AcctABC(ba), m_max_loan(max_loan), m_owes_bank(0.0), m_rate(rate) {}


void BrassPlus::view_acct() const
{
    Formatting fmt = set_format();

    std::cout << "brassplus client: "<< get_name() << std::endl;
    std::cout << "acccount number: " << get_acct_num() << std::endl;
    std::cout << "balance: $" << get_balance() << std::endl;
    std::cout << "maximum loan: $" << this->m_max_loan << std::endl;
    std::cout << "owed to bank: $" << m_owes_bank << std::endl;
    std::cout.precision(3);
    std::cout << "loan rate: " << 100 * this->m_rate << "%\n";
    restore(fmt);
}


void BrassPlus::with_draw(double amt)
{
    Formatting fmt = set_format();

    double balance = get_balance();
    if (amt <= balance) {
        AcctABC::with_draw(amt);
    } else if (amt <= balance + this->m_max_loan - this->m_owes_bank) {
        double advance = amt - balance;
        this->m_owes_bank += advance * (1.0 + this->m_rate);
        std::cout << "bank advance: $" << advance << std::endl;
        std::cout << "finance charge: $" << advance * this->m_rate << std::endl;
        deposit(advance);
        AcctABC::with_draw(amt);
    } else {
        std::cout << "credit limit exceeded. transaction cancelled.\n";
    }
    restore(fmt);
}

