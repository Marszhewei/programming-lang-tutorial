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
#include "rated_player.h"


int main(int argc, char **argv)
{
    TableTennisPlayer player1("chuck", "blizzard", true);
    TableTennisPlayer player2("tara", "boomdea", false);

    player1.name();
    if (player1.has_table())
        std::cout << ": has a table.\n";
    else
        std::cout << ": hasn't a table.\n";

    player2.name();
    if (player2.has_table())
        std::cout << ": has a table.\n";
    else
        std::cout << ": hasn't a table.\n";


    RatedPlayer rp(90, "150zy", "fetch", true);
    rp.name();
    std::cout << std::endl << "rating is: " << rp.get_rating() << std::endl;

    RatedPlayer rp1(87, player1);
    rp1.name();
    std::cout << std::endl << "rating is: " << rp1.get_rating() << std::endl;

    // inherit class to base class
    TableTennisPlayer &pr = rp;
    pr.reset_table(false);
    std::cout << "rp has table: ?" << std::boolalpha << rp.has_table() << std::endl;
    TableTennisPlayer *ppr = &rp;
    ppr->name();
    std::cout << std::endl;
    // but not allow base class to inherit class

    return 0;
}