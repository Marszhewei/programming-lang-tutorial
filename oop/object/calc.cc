/**
 * @file calc.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include "calc.h"


namespace XDU
{
    void Calc::set_pos(int32_t posx, int32_t posy)
    {
        this->m_posx = posx;
        this->m_posy = posy;
    }

    std::pair<int32_t, int32_t> Calc::get_pos() const
    {
        return  std::make_pair(this->m_posx, this->m_posy);
    }

    int32_t Calc::get_area() const
    {
        return this->m_area;
    }

    void Calc::calc_area()
    {
        this->m_area = this->m_posx * m_posy;
    }

    void Calc::show() const
    {
        std::cout << "posx: " << this->m_posx << ',' << "posy: " << this->m_posy << std::endl;
    }
}