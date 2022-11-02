/**
 * @file base.h
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief base class
 * @version 0.1
 * @date 2022-11-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef BASE_H_
#define BASE_H_

#include <iostream>
#include <string>


class TableTennisPlayer
{
private:
    std::string m_first_name;
    std::string m_last_name;
    bool m_has_table;

public:
    TableTennisPlayer(const std::string &fn = "none",
                    const std::string &ln = "none", bool ht = false);
    void name() const;
    bool has_table() const { return this->m_has_table; }
    void reset_table(bool flag) { this->m_has_table = flag; } 
};


#endif
