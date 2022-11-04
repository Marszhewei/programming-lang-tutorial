/**
 * @file hasa.h
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief an example class of (has a)
 * @version 0.1
 * @date 2022-11-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */


// Contains should generally be used to establish a has-a relationship
// If the new class needs to access protected members of the original class
// or needs to redefine virtual functions, private inheritance should be used


#ifndef HASA_H_
#define HASA_H_

#include <iostream>
#include <string>
#include <valarray>

class Student
{
private: 
    std::string m_name;
    std::valarray<double> m_scores;
    std::ostream &arr_out(std::ostream &os) const;

public:
    Student() : m_name("null student"), m_scores() {}
    explicit Student(const std::string &name) : m_name(name), m_scores() {}
    explicit Student(int32_t n) : m_name("null student"), m_scores(n) {}
    Student(const std::string &name, int32_t n) : m_name(name), m_scores(n) {}
    Student(const std::string &name, const std::valarray<double> &a)
            : m_name(name), m_scores(a) {}
    Student(const char *str, const double *pd, int32_t n)
            : m_name(str), m_scores(pd, n) {}
    ~Student() {}

    double average() const;
    const std::string &get_name() const;
    double &operator[](int32_t i);
    double operator[](int32_t i) const;

    /* friends */
    friend std::istream &operator>>(std::istream &is, Student &stu);
    friend std::istream &getline(std::istream &is, Student &stu);
    friend std::ostream &operator<<(std::ostream &os, const Student &stu);
};


/* use private inherit */
class StudentP : private std::string, private std::valarray<double>
{
private:
    std::ostream &arr_out(std::ostream &os) const;
public:
    StudentP() : std::string("null student"), std::valarray<double>() {}
    explicit StudentP(const std::string &name) : std::string(name), std::valarray<double>() {}
    explicit StudentP(int32_t n) : std::string("null student"), std::valarray<double>(n) {}
    StudentP(const std::string &name, int32_t n)
            : std::string(name), std::valarray<double>(n) {}
    StudentP(const std::string &name, const std::valarray<double> &a)
            : std::string(name), std::valarray<double>(a) {}
    StudentP(const char *str, const double *pd, int32_t n)
            : std::string(str), std::valarray<double>(pd, n) {}
    ~StudentP() {}

    double average() const;
    double &operator[](int32_t i);
    double operator[](int32_t i) const;
    const std::string &get_name() const;

    /* friends */
    friend std::istream &operator>>(std::istream &is, StudentP &stu);
    friend std::istream &getline(std::istream &is, StudentP &stu);
    friend std::ostream &operator<<(std::ostream &os, const StudentP &stu);
};


#endif

