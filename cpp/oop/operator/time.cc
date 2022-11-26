/**
 * @file time.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief operator overload
 * @version 0.1
 * @date 2022-10-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "time.h"


Time::Time(int32_t hours, int32_t minutes)
{
    this->m_hours = hours;
    this->m_minutes = minutes;
}


void Time::add_hours(int32_t hours)
{
    this->m_hours += hours;
}


void Time::add_minutes(int32_t minutes)
{
    this->m_minutes += minutes;
    this->m_hours += this->m_minutes / 60;
    this->m_minutes %= 60;
}


void Time::reset(int32_t hours, int32_t minutes)
{
    this->m_hours = hours;
    this->m_minutes = minutes;
}


/* Time Time::tsum(const Time &t) const
{
    Time sm;
    sm.m_minutes = this->m_minutes + t.m_minutes;
    sm.m_hours = this->m_hours + t.m_hours + sm.m_minutes / 60;
    sm.m_minutes %= 60;
    return sm;
} */


Time Time::operator+(const Time &t) const
{
    Time sm;
    sm.m_minutes = this->m_minutes + t.m_minutes;
    sm.m_hours = this->m_hours + t.m_hours + sm.m_minutes / 60;
    sm.m_minutes %= 60;
    return sm;
}


Time Time::operator-(const Time &t) const
{
    Time diff;
    int32_t tot1 = t.m_minutes + 60 * t.m_hours;
    int32_t tot2 = this->m_minutes + 60 * this->m_hours;
    diff.m_hours = (tot2 - tot1) / 60;
    diff.m_minutes = (tot2 - tot1) % 60;
    return diff;
}


Time Time::operator*(int32_t mult) const
{
    Time res;
    int64_t tm = this->m_hours * mult * 60 + this->m_minutes * mult;
    res.m_hours = tm / 60;
    res.m_minutes = tm % 60;
    return res;
}


void Time::show() const
{
    std::cout << this->m_hours << " hours, " << this->m_minutes << " minutes." << std::endl;
}


Time::operator int32_t() const
{
    return int32_t(this->m_hours * 60 + this->m_minutes);
}


Time::operator double() const
{
    return double(this->m_hours * 60 + this->m_minutes);
}


int32_t Time::obj_to_i32() const
{
    return int32_t(this->m_hours * 60 + this->m_minutes);
}


double Time::obj_to_f64() const
{
    return double(this->m_hours * 60 + this->m_minutes);
}


Time operator*(int32_t mult, const Time &t)
{
    Time res;
    int64_t tm = t.m_hours * mult * 60 + t.m_minutes * mult;
    res.m_hours = tm / 60;
    res.m_minutes = tm % 60;
    return res;
}


std::ostream &operator<<(std::ostream &os, const Time &t)
{
    os << t.m_hours << " hours, " << t.m_minutes << " minutes."; 
    return os;
}


/* Time operator*(int32_t mult, const Time &t)
{
    return t * mult;
} */