/**
 * @file friend.h
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#ifndef FRIEND_H_
#define FRIEND_H_

#include <iostream>

template <typename T>
class HasFriend
{
private:
    T m_item;
    static int32_t ct;
public:
    HasFriend(const T &i) : m_item(i) { ct++; }
    ~HasFriend() { ct--; }
    friend void counts();
    friend void reports(HasFriend<T> &hf);
};


template <typename T>
int32_t HasFriend<T>::ct = 0;


void counts()
{
    std::cout << "int32_t count: " << HasFriend<int32_t>::ct << "; ";
    std::cout << "double count: " << HasFriend<double>::ct << std::endl;
}


void reports(HasFriend<int32_t> &hf)
{
    std::cout << "HasFriend<int32_t>: " << hf.m_item << std::endl;
}


void reports(HasFriend<double> &hf)
{
    std::cout << "HasFriend<double>: " << hf.m_item << std::endl;
}



/* bound template friend */
template <typename T> void countst();
template <typename T> void reportt(T &hf);

template <typename T>
class HasFriendT
{
private:
    T m_item;
    static int32_t ct;
public:
    HasFriendT(const T& item) : m_item(item) { ct++; }
    ~HasFriendT() { ct--; }
    friend void countst<T>();
    friend void reportt<HasFriendT<T>>(HasFriendT<T> &hf);
};


template <typename T>
int32_t HasFriendT<T>::ct = 0;


template <typename T>
void countst()
{
    std::cout << "template size: " << sizeof(HasFriendT<T>) << "; ";
    std::cout << "template counts(): " << HasFriendT<T>::ct << std::endl;
}


template <typename T>
void reportt(T &hf)
{
    std::cout << hf.m_item << std::endl;
}


/* unbound template friend */
template <typename T>
class ManyFriend
{
private:
    T m_item;

public:
    ManyFriend(const T &i) : m_item(i) {}
    template <typename C, typename D> friend void show2(const C &c, const D& d);
};


template <typename C, typename D> void show2(const C &c, const D &d)
{
    std::cout << c.m_item << ", " << d.m_item << std::endl;
}


#endif

