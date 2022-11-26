/**
 * @file abc.h
 * @author fetch150Zy (Mars_zhewei@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#ifndef ABC_H_
#define ABC_H_

#include <iostream>
#include <string>

class AcctABC
{
private:
    std::string m_name;
    uint32_t m_acct_num;
    double m_balance;

protected:
    struct Formatting
    {
        std::ios_base::fmtflags flag;
        std::streamsize pr;
    };
    const std::string &get_name() const { return this->m_name; }
    uint32_t get_acct_num() const { return this->m_acct_num; }
    Formatting set_format() const;
    void restore(Formatting &fmt) const;

public:
    AcctABC(const std::string &name = "nullbody", uint32_t acct_num = 0,
            double balance = 0.0);
    void deposit(double amt);
    virtual void with_draw(double amt) = 0;
    double get_balance() const { return this->m_balance; }
    virtual void view_acct() const = 0;
    virtual ~AcctABC() {}
};


/* Brass Account Class */
class Brass : public AcctABC
{
public:
    Brass(const std::string &name = "nullbody", uint32_t acct_num = 0,
          double balance = 0.0) : AcctABC(name, acct_num, balance) {}
    virtual void with_draw(double amt);
    virtual void view_acct() const;
    virtual ~Brass() {}
};


/* Brass Plus Account Class */
class BrassPlus : public AcctABC
{
private:
    double m_max_loan;
    double m_rate;
    double m_owes_bank;

public:
    BrassPlus(const std::string &name = "nullbody", uint32_t acct_num = 0,
              double balance = 0.0, double max_loan = 500.0, double rate = 0.10);
    BrassPlus(const Brass &ba, double max_loan = 500.0, double rate = 0.10);
    virtual void with_draw(double amt);
    virtual void view_acct() const;
    void reset_max_loan(double max_loan) { this->m_max_loan = max_loan; }
    void reset_rate(double rate) { this->m_rate = rate; }
    void reset_owes() { this->m_owes_bank = 0.0; }
};


#endif
