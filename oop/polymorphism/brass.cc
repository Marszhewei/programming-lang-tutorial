/**
 * @file brass.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include "brass.h"


std::ios_base::fmtflags set_format();
void restore(std::ios_base::fmtflags fmt, std::streamsize pc);


/* Brass class methods */
Brass::Brass(const std::string &s, uint32_t acct_num, double balance)
                    : m_name(s), m_acct_num(acct_num), m_balance(balance) {}


Brass::Brass(const Brass &ba)
{
    this->m_name = ba.m_name;
    this->m_acct_num = ba.m_acct_num;
    this->m_balance = ba.m_balance;
}


void Brass::deposit(double amt)
{
    if (amt < 0)
        std::cout << "negative deposit not allowed; "
                  << "deposit is cancelled.\n";
    else
        this->m_balance += amt;
}


double Brass::get_balance() const
{
    return this->m_balance;
}


void Brass::with_draw(double amt)
{
    std::ios_base::fmtflags init_status = set_format();
    std::streamsize prec = std::cout.precision(2);

    if (amt < 0)
        std::cout << "withdraw amount must be positive; "
                  << "withdraw cancelled.\n";
    else if (amt <= this->m_balance)
        this->m_balance -= amt;
    else
        std::cout << "withdraw amount of $" << amt
                  << " exceeds your balance.\n"
                  << "withdraw cancelled.\n";
    restore(init_status, prec);
}


void Brass::view_acct() const
{
    std::ios_base::fmtflags init_status = set_format();
    std::streamsize prec = std::cout.precision(2);

    std::cout << "client: " << this->m_name << std::endl;
    std::cout << "account number: " << this->m_acct_num << std::endl;
    std::cout << "balance: $" << this->m_balance << std::endl;

    restore(init_status, prec);
}


/* BrassPlus class methods */
BrassPlus::BrassPlus(const std::string &s, uint32_t acct_num, double balance,
                     double max_loan, double rate) : Brass(s, acct_num, balance),
                     m_max_loan(max_loan), m_rate(rate), m_owes_bank(0.0) {}


BrassPlus::BrassPlus(const Brass &ba, double max_loan, double rate)
                     : Brass(ba), m_max_loan(max_loan), m_rate(rate), m_owes_bank(0.0) {}


void BrassPlus::view_acct() const
{
    std::ios_base::fmtflags init_status = set_format();
    std::streamsize prec = std::cout.precision(2);

    Brass::view_acct();
    std::cout << "maximum loan: $" << this->m_max_loan << std::endl;
    std::cout << "owed to bank: $" << this->m_owes_bank << std::endl;
    std::cout.precision(3);
    std::cout << "loan rate: " << 100 * this->m_rate << "%\n";
    restore(init_status, prec);
}


void BrassPlus::with_draw(double amt)
{
    std::ios_base::fmtflags init_status = set_format();
    std::streamsize prec = std::cout.precision(2);

    double balance = get_balance();
    if (amt <= balance) {
        Brass::with_draw(amt);
    } else if (amt <= balance + this->m_max_loan - this->m_owes_bank) {
        double advance = amt - balance;
        this->m_owes_bank += advance * (1.0 + this->m_rate);
        std::cout << "bank advance: $" << advance << std::endl;
        std::cout << "finance charge: $" << advance * this->m_rate << std::endl;
        deposit(advance);
        Brass::with_draw(amt);
    } else {
        std::cout << "credit limit exceeded. transaction cancelled.\n";
    }
    restore(init_status, prec);
}


std::ios_base::fmtflags set_format()
{
    return std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
}


void restore(std::ios_base::fmtflags fmt, std::streamsize pc)
{
    std::cout.setf(fmt, std::ios_base::floatfield);
    std::cout.precision(pc);
}