/**
 * @file tv.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include "tv.h"


bool Tv::volumn_up()
{
    if (this->m_volumn < MAX_VAL) {
        this->m_volumn++;
        return true;
    } else {
        return false;
    }
}


bool Tv::volumn_down()
{
    if (this->m_volumn > MIN_VAL) {
        this->m_volumn--;
        return true;
    } else {
        return false;
    }
}


void Tv::channel_up()
{
    if (this->m_channel < this->m_max_channel)
        this->m_channel--;
    else
        this->m_channel = this->m_max_channel;
}


void Tv::display_settings() const
{
    std::cout << "tv is " << (this->m_state == OFF ? "OFF" : "ON") << std::endl;
    if (this->m_state == ON) {
        std::cout << "volumn setting = " << this->m_volumn << std::endl;
        std::cout << "channel setting = " << this->m_channel << std::endl;
        std::cout << "mode = " << (this->m_mode == ANTENNA ? "ANTENNA" : "CABLE") << std::endl;
        std::cout << "input = " << (this->m_input == TV ? "TV" : "DVD") << std::endl; 
    }
}