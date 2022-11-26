/**
 * @file base.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief base class source code
 * @version 0.1
 * @date 2022-11-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include "base.h"


TableTennisPlayer::TableTennisPlayer(const std::string &fn, 
    const std::string &ln, bool ht) : m_first_name(fn),
        m_last_name(ln), m_has_table(ht) {}


TableTennisPlayer::TableTennisPlayer(const TableTennisPlayer &tp)
{
    this->m_first_name = tp.m_first_name;
    this->m_last_name = tp.m_last_name;
    this->m_has_table = tp.m_has_table;
}


void TableTennisPlayer::name() const
{
    std::cout << this->m_last_name << ", " << this->m_first_name;
}

