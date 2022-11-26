/**
 * @file str.h
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#ifndef STRING_H_
#define STRING_H_

#include <iostream>

class String
{
private:
    char *m_str;
    int32_t m_len;
    // static varibale, can't init here
    static int32_t m_string_nums;
    // static const variable, can init here
    static const int32_t CINLIM = 80;
public:
    // constructor
    String(const char *str);
    // default constructor
    String();
    // copy constructor
    String(const String &s);
    // destructor
    ~String();
    
    // objects methods
    int32_t length() const { return this->m_len; }

    /* overload operator methods */
    String &operator=(const String &s);
    String &operator=(const char *str);
    char &operator[](int32_t i);
    const char &operator[](int32_t i) const;

    /* overload operator friends */
    friend std::ostream &operator<<(std::ostream &os, const String &s);
    friend std::istream &operator>>(std::istream &is, String &s);
    friend bool operator<(const String &s1, const String &s2);
    friend bool operator>(const String &s1, const String &s2);
    friend bool operator==(const String &s1, const String &s2);

    // class(static) method
    static int32_t how_many() { return m_string_nums; }
};


#endif
