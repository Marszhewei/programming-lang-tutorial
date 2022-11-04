/**
 * @file hasa.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include "hasa.h"


/* priavte methods */
std::ostream &Student::arr_out(std::ostream &os) const
{
    int32_t i, lim = this->m_scores.size();
    if (lim > 0) {
        for (i = 0; i < lim; ++i) {
            os << m_scores[i] << ' ';
            if (i % 5 == 4)
                os << std::endl;
        }
        if (i % 5 != 0)
            os << std::endl;
    } else {
        os << " empty array ";
    }
    return os;
}


/* public methods */
double Student::average() const
{
    if (this->m_scores.size() > 0)
        return this->m_scores.sum() / this->m_scores.size();
    else
        return 0;
}


const std::string &Student::get_name() const
{
    return this->m_name;
}


double &Student::operator[](int32_t i)
{
    return this->m_scores[i];
}


double Student::operator[](int32_t i) const
{
    return this->m_scores[i];
}


/* firends function */
std::istream &operator>>(std::istream &is, Student &stu)
{
    is >> stu.m_name;
    return is;
}


// use string friend getline(ostream &, const string &)
std::istream &getline(std::istream &is, Student &stu)
{
    getline(is, stu.m_name);
    return is;
}


std::ostream &operator<<(std::ostream &os, const Student &stu)
{
    os << "scores for " << stu.m_name << ":\n";
    stu.arr_out(os);
    return os;
}


/* use private inherit */
double StudentP::average() const
{
    if (std::valarray<double>::size() > 0)
        return std::valarray<double>::sum() / std::valarray<double>::size();
    else
        return 0;
}


double &StudentP::operator[](int32_t i)
{
    return std::valarray<double>::operator[](i);
}


double StudentP::operator[](int32_t i) const
{
    return std::valarray<double>::operator[](i);
}


const std::string &StudentP::get_name() const
{
    return (const std::string &) *this;
}


// private method
std::ostream &StudentP::arr_out(std::ostream &os) const
{
    int32_t i, lim = std::valarray<double>::size();
    if (lim > 0) {
        for (i = 0; i < lim; ++i) {
            os << std::valarray<double>::operator[](i) << ' ';
            if (i % 5 == 4)
                os << std::endl;
        }
        if (i % 5 != 0)
            os << std::endl;
    } else {
        os << " empty array ";
    }
    return os;
}


// friends
std::istream &operator>>(std::istream &is, StudentP &stu)
{
    is >> (std::string &)stu;
    return is;
}


std::istream &getline(std::istream &is, StudentP &stu)
{
    getline(is, (std::string &)stu);
    return is;
}


std::ostream &operator<<(std::ostream &os, const StudentP &stu)
{
    os << "scores for " << (const std::string &)stu << ":\n";
    stu.arr_out(os);
    return os;
}