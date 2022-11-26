/**
 * @file member.h
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#ifndef MEMBER_H_
#define MEMBER_H_

#include <iostream>


template<typename T>
class Beta
{
private:
    template<typename V>
    class Hold
    {
    private:
        V m_val;
    public:
        Hold(V val = 0) : m_val(val) {}
        void show() const { std::cout << this->m_val << std::endl; }
        V get_value() const { return this->m_val; }    
    };
    Hold<T> m_q;
    Hold<int32_t> m_n;

public:
    Beta(const T &t, int32_t i) : m_q(t), m_n(i) {}
    template<typename U>
    U blab(U &u, T &t)
    {
        return ((this->m_n.get_value() + this->m_q.get_value()) * u / t);
    }
    void show() const { this->m_q.show(); this->m_n.show(); }
};


/* if you want to implement out of class */
template <typename T>
class Betaa
{
private:
    template <typename V> class Holdd;
    Holdd<T> m_q;
    Holdd<int32_t> m_n;

public:
    Betaa(const T &t, int32_t i) : m_q(t), m_n(i) {}
    template <typename U> U blab(const U &u, const T &t) const;
    void show() const { this->m_q.show(); this->m_n.show(); }
};


template <typename T>
template <typename V>
class Betaa<T>::Holdd
{
private:
    V m_val;
public:
    Holdd(const V &val) : m_val(val) {}
    void show() const { std::cout << this->m_val << std::endl; }
    V get_value() const { return this->m_val; }
};


template <typename T>
template <typename U>
U Betaa<T>::blab(const U &u, const T &t) const
{
    return (this->m_n.get_value() + this->m_q.get_value()) * u / t;
}

#endif

