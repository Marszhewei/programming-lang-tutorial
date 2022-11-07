/**
 * @file sales.h
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief an example about exception, class, inherit
 * @version 0.1
 * @date 2022-11-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#ifndef SALES_H_
#define SALES_H_

#include <stdexcept>
#include <iostream>
#include <string>


class Sales
{
public:
    enum { MONTHS = 12 };
    class bad_index : public std::logic_error
    {
    private:
        int32_t m_index;
    public:
        explicit bad_index(int32_t index,
                            const std::string &s = "Index error in Sales object\n");
        int32_t get_index() const { return this->m_index; }
        virtual ~bad_index() throw() {}
    };
    explicit Sales(int32_t yy = 0);
    Sales(int32_t yy, const double * gr, int32_t n);
    virtual ~Sales() {}
    int32_t get_year() const { return this->m_year; }
    virtual double operator[](int32_t i) const;
    virtual double &operator[](int32_t i);

private:
    double m_gross[MONTHS];
    int32_t m_year;
};


class LabeledSales : public Sales
{
private:
    std::string m_label;

public:
    class nbad_index : public Sales::bad_index
    {
    private:
        std::string m_lb_one;
    public:
        nbad_index(const std::string &lb, int32_t index,
                    const std::string &s = "Index error in LabeldSales object\n");
        const std::string &label_val() const { return this->m_lb_one; }
        virtual ~nbad_index() throw() {}
    };
    explicit LabeledSales(const std::string &label = "none", int32_t yy = 0);
    LabeledSales(const std::string &label, int32_t yy, const double *gr, int32_t n);
    virtual ~LabeledSales() {}
    const std::string &get_label() const { return this->m_label; }
    virtual double operator[](int32_t i) const;
    virtual double &operator[](int32_t i);
};


#endif

