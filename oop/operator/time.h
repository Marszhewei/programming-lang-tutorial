/**
 * @file time.h
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#ifndef TIME_H_
#define TIME_H_

#include <iostream>

class Time
{
private:
    int32_t m_hours;
    int32_t m_minutes;
public:
    Time(int32_t hours = 0, int32_t minutes = 0);
    void add_minutes(int32_t minutes);
    void add_hours(int32_t hours);
    void reset(int32_t hours = 0, int32_t minutes = 0);
    // Time tsum(const Time & t) const;
    Time operator+(const Time &t) const;
    Time operator-(const Time &t) const;
    Time operator*(int32_t mult) const;
    friend Time operator*(int32_t mult, const Time &t);
    friend std::ostream &operator<<(std::ostream &os, const Time &t);
    void show() const;
    explicit operator int32_t() const;
    explicit operator double() const;
    // or
    int32_t obj_to_i32() const;
    double obj_to_f64() const;
    ~Time() {}
};

// not friend
// Time operator*(int32_t mult, const Time &t);

#endif
