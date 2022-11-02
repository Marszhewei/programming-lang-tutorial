/**
 * @file str.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include "str.h"

#include <cstring>


int32_t String::m_string_nums = 0;


// constructor
String::String(const char *str)
{
    this->m_len = std::strlen(str);
    this->m_str = new char[this->m_len + 1];
    std::strcpy(this->m_str, str);
    ++(this->m_string_nums);
    // std::cout << this->m_string_nums << ": \"" << this->m_str 
    //           << "\" object created\n";
}


// default constructor
String::String()
{
    this->m_len = 0;
    this->m_str = new char[this->m_len + 1];
    this->m_str[0] = '\0';
    ++(this->m_string_nums);
    // std::cout << this->m_string_nums << ": \"" << this->m_str 
    //           << "\" default object created\n";
}


// copy constructor
String::String(const String &s)
{
    this->m_string_nums++;
    this->m_len = s.m_len;
    this->m_str = new char[this->m_len + 1];
    std::strcpy(this->m_str, s.m_str);
    // std::cout << this->m_string_nums << ": \"" << this->m_str
    //           << "\" object created\n";
}


// destructor
String::~String()
{
    // std::cout << "\"" << this->m_str << "\" object deleted, ";
    --(this->m_string_nums);
    // std::cout << this->m_string_nums << " left\n";
    delete [] this->m_str;
    this->m_str = nullptr;
}


/* overload operator methods */
String &String::operator=(const String &s)
{
    if (this == &s)
        return *this;
    delete [] this->m_str;
    this->m_len = s.m_len;
    this->m_str = new char [this->m_len + 1];
    std::strcpy(this->m_str, s.m_str);
    return *this;
}


String &String::operator=(const char *str)
{
    delete [] this->m_str;
    this->m_len = std::strlen(str);
    this->m_str = new char[this->m_len + 1];
    std::strcpy(this->m_str, str);
    return *this;
}


char &String::operator[](int32_t i)
{
    return this->m_str[i];
}


// for use with const string objects
const char &String::operator[](int32_t i) const
{
    return this->m_str[i];
}


/* overload operator friends */
std::ostream &operator<<(std::ostream &os, const String &s)
{
    os << s.m_str;
    return os;
}


std::istream &operator>>(std::istream &is, String &s)
{
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if (is)
        s = temp;
    while (is && is.get() != '\n')
        continue;
    return is;
}


bool operator<(const String &s1, const String &s2)
{
    return (std::strcmp(s1.m_str, s2.m_str) < 0);
}


bool operator>(const String &s1, const String &s2)
{
    return s2 < s1;
}


bool operator==(const String &s1, const String &s2)
{
    return (std::strcmp(s1.m_str, s2.m_str) == 0);
}