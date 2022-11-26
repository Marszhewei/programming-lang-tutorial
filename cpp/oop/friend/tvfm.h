/**
 * @file tvfm.h
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef TVFM_H_
#define TVFM_H_

#include <iostream>

/* forward declaration */
class Tv;

class Remote
{
private:
    int32_t m_mode;

public:
    enum { OFF, ON };
    enum { MIN_VAL, MAX_VAL = 20 };
    enum { ANTENNA, CABLE };
    enum { TV, DVD }; 

    Remote(int32_t m = TV) : m_mode(m) {}
    bool volumn_up(Tv &t);
    bool volumn_down(Tv &t);
    void onoff(Tv &t);
    void channel_up(Tv &t);
    void channel_down(Tv &t);
    void set_channel(Tv &t, int32_t channel);
    void set_mode(Tv &t);
    void set_input(Tv &t);
};


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
    friend void Remote::set_channel(Tv &t, int32_t channel);
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


inline bool Remote::volumn_up(Tv &t) { return t.volumn_up(); }
inline bool Remote::volumn_down(Tv &t) { return t.volumn_down(); }
inline void Remote::onoff(Tv &t) { t.onoff(); }
inline void Remote::channel_up(Tv &t) { t.channel_up(); }
inline void Remote::channel_down(Tv &t) { t.channel_down(); }
inline void Remote::set_mode(Tv &t) { t.set_mode(); }
inline void Remote::set_input(Tv &t) { t.set_input(); }
inline void Remote::set_channel(Tv &t, int32_t channel) { t.m_channel = channel; }


#endif
