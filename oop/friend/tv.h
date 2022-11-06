/**
 * @file tv.h
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#ifndef TV_H_
#define TV_H_

#include <iostream>

class Tv
{
private:
    int32_t m_state;
    int32_t m_volumn;
    int32_t m_max_channel;
    int32_t m_channel;
    int32_t m_mode;
    int32_t m_input;

public:
    friend class Remote;
    enum { OFF, ON };
    enum { MIN_VAL, MAX_VAL = 20 };
    enum { ANTENNA, CABLE };
    enum { TV, DVD };

    Tv(int32_t state = OFF, int32_t max_channel = 125) : m_state(state), m_volumn(5),
        m_max_channel(max_channel), m_channel(2), m_mode(CABLE), m_input(TV) {}
    void onoff() { this->m_state ^= 1; }
    bool ison() const { return this->m_state == ON; }
    bool volumn_up();
    bool volumn_down();
    void channel_up();
    void channel_down();
    void set_mode() { this->m_mode = (this->m_mode == ANTENNA) ? CABLE : ANTENNA; }
    void set_input() { this->m_input = (this->m_input == TV) ? DVD : TV; }
    void display_settings() const;
};


class Remote
{
private:
    int32_t m_mode;

public:
    Remote(int32_t m = Tv::TV) : m_mode(m) {}
    bool volumn_up(Tv &t) { return t.volumn_up(); }
    bool volumn_down(Tv &t) { return t.volumn_down(); }
    void onoff(Tv &t) { t.onoff(); }
    void channel_up(Tv &t) { t.channel_up(); }
    void channel_down(Tv &t) { t.channel_down(); }
    void set_channel(Tv &t, int32_t channel) { t.m_channel = channel; }
    void set_mode(Tv &t) { t.set_mode(); }
    void set_input(Tv &t) { t.set_input(); }
};


#endif

