/**
 * @file brass.h
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#ifndef BRASS_H_
#define BRASS_H_

#include <iostream>
#include <string>


class Brass
{
private:
    std::string m_name;
    uint32_t m_acct_num;
    double m_balance;

public:
    Brass(const std::string &s = "nullbody", uint32_t acct_num = 0,
          double balance = 0.0);
    Brass(const Brass &ba);
    void deposit(double amt);
    double get_balance() const;
    virtual void with_draw(double amt);
    virtual void view_acct() const;
    virtual ~Brass() {};
};


class BrassPlus : public Brass
{
private:
    double m_max_loan;
    double m_rate;
    double m_owes_bank;
public:
    BrassPlus(const std::string &s = "nullbody", uint32_t acct_num = 0,
              double balance = 0.0, double max_loan = 500.0, double rate = 0.11125);
    BrassPlus(const Brass &ba, double max_loan = 500.0, double rate = 0.11125);
    virtual void view_acct() const;
    virtual void with_draw(double amt);
    void reset_max_loan(double max_loan) { this->m_max_loan = max_loan; }
    void reset_rate(double rate) { this->m_rate = rate; }
    void reset_owes() { this->m_owes_bank = 0.0; }
};


#endif

