/**
 * @file test.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include "tv.h"


int main(int argc, char **argv)
{
    Tv s;
    std::cout << "init settings for 42\" TV:\n";
    s.display_settings();
    s.onoff();
    s.channel_up();
    std::cout << "\nadjusted settings for 42\" TV:\n";
    s.channel_up();
    std::cout << "\nadjusted settings for 42\" TV:\n";
    s.display_settings();

    Remote r;
    r.set_channel(s, 10);
    r.volumn_up(s);
    r.volumn_up(s);
    std::cout << "\n 42\" settings after using remote:\n";
    s.display_settings();

    Tv s58(Tv::ON);
    s58.set_mode();
    r.set_channel(s58, 28);
    std::cout << "\n58\" settings:\n";
    s58.display_settings();

    return 0;
}