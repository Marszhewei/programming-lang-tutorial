/**
 * @file pairs.h
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief pairs<type, type>
 * @version 0.1
 * @date 2022-11-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#ifndef PAIRS_H_
#define PAIRS_H_

#include <iostream>


template <typename T1, typename T2>
class Pairs
{
private:
    T1 m_first;
    T2 m_second;

public:
    T1 &first();
    T2 &second();
    T1 first() const { return this->m_first; }
    T2 second() const { return this->m_second; }
    Pairs(const T1 &val1, const T2 &val2) : m_first(val1), m_second(val2) {}
    Pairs() {}
};


// explicit instantiation
// template class Pairs<std::string, int32_t>;

// explicit specialization
// template <> class Pairs<const char *, int32_t> {};

// partial specialization
// template <typename T1> class Pairs<T1, int32_t> {};


/* choice which one? */
/* Pairs<double, double> p1;       // use general pairs template
Pairs<double, int32_t> p2;      // use Pairs<T1, int32_t> partial sepcialzation
Pairs<const char *, int32_t> p3;// use Pairs<const char *, int32_t> explicit sepcialization */


// pointer template partial specialization
// template<typename T> class A {};
// template<typename T* > class A {};


template<typename T1, typename T2>
T1 &Pairs<T1, T2>::first()
{
    return this->m_first;
}


template<typename T1, typename T2>
T2 &Pairs<T1, T2>::second()
{
    return this->m_second;
}


#endif

