/**
 * @file rated_player.hpp
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief inherit class
 * @version 0.1
 * @date 2022-11-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#ifndef RATED_PLAYER_H_
#define RATED_PLAYER_H_


#include "base.h"


class RatedPlayer : public TableTennisPlayer
{
private:
    uint32_t m_rating;

public:
    RatedPlayer(uint32_t r = 0,
            const std::string &fn = "none", 
            const std::string &ln = "none",
            bool ht = false);
    RatedPlayer(uint32_t r, const TableTennisPlayer &tp);
    uint32_t get_rating() const { return this->m_rating; }
    void reset_rating(uint32_t r) { this->m_rating = r; }
};


#endif


