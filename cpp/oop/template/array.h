/**
 * @file array.h
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief array<type, size>
 * @version 0.1
 * @date 2022-11-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#ifndef ARRAY_H_
#define ARRAY_H_

#include <iostream>

template<typename Type, int32_t n>
class Array
{
private:
    Type m_arr[n];

public:
    Array() {}
    explicit Array(const Type &a);
    virtual Type &operator[](int32_t i);
    virtual Type operator[](int32_t i) const;
};


template<typename Type, int32_t n>
Array<Type, n>::Array(const Type &v)
{
    for (int i = 0; i < n; ++i)
        this->m_arr[i] = v;
}


template<typename Type, int32_t n>
Type &Array<Type, n>::operator[](int32_t i)
{
    if (i < 0 || i >= n) {
        std::cerr << "error in array limits: " << i
                  << " is out of range\n";
        std::exit(EXIT_FAILURE);
    }
    return this->m_arr[i];
}


template<typename Type, int32_t n>
Type Array<Type, n>::operator[](int32_t i) const
{
    if (i < 0 || i >= n) {
        std::cerr << "error in array limits: " << i
                  << " is out of range\n";
        std::exit(EXIT_FAILURE);
    }
    return this->m_arr[i];
}


#endif

