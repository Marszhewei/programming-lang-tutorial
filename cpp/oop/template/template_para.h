/**
 * @file template_para.h
 * @author fetch150zy (Mars_zhewei@outlook.vom)
 * @brief 
 * @version 0.1
 * @date 2022-11-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#ifndef TEMPLATE_PARA_H_
#define TEMPLATE_PARA_H_

#include "stack.h"

#include <iostream>


template <template < typename T> class Thing, typename U, typename V>
class Crab
{
private:
    Thing<U> m_s1;
    Thing<V> m_s2;
public:
    Crab() {};
    bool push(int32_t a, double x) { return this->m_s1.push(a) && this->m_s2.push(x); }
    bool pop(int32_t &a, double &x) { return this->m_s1.pop(a) && this->m_s2.pop(x); }
};


#endif