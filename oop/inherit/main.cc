/**
 * @file main.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief just for testing class
 * @version 0.1
 * @date 2022-11-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include "base.h"
#include "rated_player.hpp"


int main(int argc, char **argv)
{
    TableTennisPlayer player1("chuck", "blizzard", true);
    TableTennisPlayer player2("tara", "boomdea", false);
    player1.name();
    
    if (player1.has_table())
        std::cout << ": has a table.\n";
    else
        std::cout << ": hasn't a table.\n";


    RatedPlayer rp(90, "fetch", "150zy", true);
    rp.name();
    std::cout << std::endl << "rating is: " << rp.get_rating() << std::endl;

    return 0;
}