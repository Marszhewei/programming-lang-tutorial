/**
 * @file sales.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include "sales.h"


Sales::bad_index::bad_index(int32_t index, const std::string &s)
                            : std::logic_error(s), m_index(index) {}


Sales::Sales(int32_t yy)
{
    this->m_year = yy;
    for (int i = 0; i < MONTHS; ++i)
        this->m_gross[i] = 0;
}


Sales::Sales(int32_t yy, const double *gr, int32_t n)
{
    this->m_year = yy;
    int32_t lim = (n < MONTHS) ? n : MONTHS;
    int i;
    for (i = 0; i < lim; ++i)
        this->m_gross[i] = gr[i];
    for ( ; i < MONTHS; ++i)
        this->m_gross[i] = 0;
}


double Sales::operator[](int32_t i) const
{
    if (i < 0 || i >= MONTHS)
        throw bad_index(i);
    return this->m_gross[i];
}


double &Sales::operator[](int32_t i)
{
    if (i < 0 || i >= MONTHS)
        throw bad_index(i);
    return this->m_gross[i];
}


/* LabeledSales Class Methods */
LabeledSales::nbad_index::nbad_index(const std::string &lb, int32_t index,
                                    const std::string &s) : Sales::bad_index(index, s)
{
    this->m_lb_one = lb;
}


LabeledSales::LabeledSales(const std::string &label, int32_t yy, const double *gr,
                            int32_t n) : Sales(yy, gr, n)
{
    this->m_label = label;
}                            


LabeledSales::LabeledSales(const std::string &label, int32_t yy) : Sales(yy)
{
    this->m_label = label;
}


double LabeledSales::operator[](int32_t i) const
{
    if (i < 0 || i >= MONTHS)
        throw nbad_index(get_label(), i);
    return Sales::operator[](i);
}


double &LabeledSales::operator[](int32_t i)
{
    if (i < 0 || i >= MONTHS)
        throw nbad_index(get_label(), i);
    return Sales::operator[](i);
}