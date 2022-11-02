/**
 * @file calc.h
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef CALC_H_
#define CALC_H_

#include <iostream>
#include <utility>

namespace XDU
{
    class Calc
    {
    private:
        int32_t m_posx;
        int32_t m_posy;
        int32_t m_area;
        // use const variable in class
        enum { Months = 12 };
        int32_t *m_ayeer;
        // another way
        static const uint8_t Days = 7;
        int32_t *m_aweek;
    public:
        // inline constructor
        // if you want to define at out of class, use inline
        /* Calc(int32_t posx, int32_t posy)
        {
            this->m_posx = posx;
            this->m_posy = posy;
        } */
        // default constructor
        // Calc() {}
        // or just use default paraments
        Calc(int32_t posx = 0, int32_t posy = 0);
        void set_pos(int32_t posx, int32_t posy);
        std::pair<int32_t, int32_t> get_pos() const;
        int32_t get_area() const;
        void calc_area();
        void show() const;
        ~Calc()
        {
            delete [] this->m_ayeer;
            delete [] this->m_aweek;
            this->m_ayeer = nullptr;
            this->m_aweek = nullptr;
        }
    };

    inline Calc::Calc(int32_t posx, int32_t posy)
    {
        this->m_posx = posx;
        this->m_posy = posy;
        this->m_ayeer = new int32_t[this->Months];
        this->m_aweek = new int32_t[this->Days];
    }
};


#endif