/**
 * @file stack.h
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief stack<type>
 * @version 0.1
 * @date 2022-11-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#ifndef STACK_H_
#define STACK_H_

#include <iostream>


template<typename Type>
class Stack
{
private:
    enum {SIZE = 10};
    Type *m_items;
    int32_t m_stack_size;
    int32_t m_top;

public:
    explicit Stack(int32_t ss = SIZE);
    Stack(const Stack &st);
    ~Stack() { delete [] m_items; }
    bool is_empty() const { return 0 == this->m_top; }
    bool is_full() const { return this->m_top == this->m_stack_size; }
    bool push(const Type& item);
    bool pop(Type &item);
    Stack &operator=(const Stack &st);
};


template<typename Type>
Stack<Type>::Stack(int32_t ss) : m_stack_size(ss), m_top(0)
{
    this->m_items = new Type[this->m_stack_size];
}


template<typename Type>
Stack<Type>::Stack(const Stack &st)
{
    this->m_stack_size = st.m_stack_size;
    this->m_top = st.m_top;
    this->m_items = new Type[this->m_stack_size];
    for (int i = 0; i < this->m_top; ++i)
        this->m_items[i] = st.m_items[i];
}


template<typename Type>
bool Stack<Type>::push(const Type& item)
{
    if (this->m_top < this->m_stack_size) {
        this->m_items[this->m_top++] = item;
        return true;
    } else {
        return false;
    }
}


template<typename Type>
bool Stack<Type>::pop(Type &item)
{
    if (this->m_top > 0) {
        item = this->m_items[--this->m_top];
        return true;
    } else {
        return false;
    }
}


template<typename Type>
Stack<Type> &Stack<Type>::operator=(const Stack<Type> &st)
{
    if (this == &st)
        return *this;
    delete [] this->m_items;
    this->m_stack_size = st.m_stack_size;
    this->m_top = st.m_top;
    this->m_items = new Type[this->m_stack_size];
    for (int i = 0; i < this->m_top; ++i)
        this->m_items[i] = st.m_items[i];
    return *this;
}


#endif

