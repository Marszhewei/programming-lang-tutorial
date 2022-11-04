/**
 * @file rated_player.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief inherit class source code
 * @version 0.1
 * @date 2022-11-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include "rated_player.h"


RatedPlayer::RatedPlayer(uint32_t r,
                const std::string &fn,
                const std::string &ln,
                bool ht) : TableTennisPlayer(fn, ln, ht)
{
    this->m_rating = r;
}


/* or */
RatedPlayer::RatedPlayer(uint32_t r, const TableTennisPlayer &tp)
                        : TableTennisPlayer(tp),  m_rating(r) {}

