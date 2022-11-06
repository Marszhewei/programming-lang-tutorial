/**
 * @file multi_inherit.h
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief multi inherit
 * @version 0.1
 * @date 2022-11-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#ifndef MULTI_INHERIT_H_
#define MULTI_INHERIT_H_

#include <iostream>


class Worker
{
private:
    std::string m_name;
    uint32_t m_id;

protected:
    virtual void data() const;
    virtual void get();

public:
    Worker() : m_name("no one"), m_id(0) {}
    Worker(const std::string &name, uint32_t id) : m_name(name), m_id(id) {}
    virtual ~Worker() = 0;
    virtual void set() = 0;
    virtual void show() const = 0;
};


class Waiter : virtual public Worker
{
private:
    int32_t m_panache;

protected:
    virtual void data() const;
    virtual void get();

public:
    Waiter() : Worker(), m_panache(0) {}
    Waiter(const std::string &name, uint32_t id, int32_t p)
            : Worker(name, id), m_panache(p) {}
    Waiter(const Worker &wk, int32_t p) : Worker(wk), m_panache(p) {}
    virtual void set();
    virtual void show() const;
};


class Singer : virtual public Worker
{
protected:
    enum {other, alto, contralto, soprano, bass, baritone, tenor};
    enum {vtypes = 7};
    virtual void data() const;
    virtual void get();

private:
    static char *pv[vtypes];
    int32_t m_voice;

public:
    Singer() : Worker(), m_voice(other) {}
    Singer(const std::string &name, uint32_t id, int32_t v = other)
            : Worker(name, id), m_voice(v) {}
    Singer(const Worker &wk, int32_t v = other) : Worker(wk), m_voice(v) {}
    virtual void set();
    virtual void show() const;
};


class SingingWaiter : public Singer, public Waiter
{
protected:
    virtual void data() const;
    virtual void get();

public:
    SingingWaiter() {}
    SingingWaiter(const std::string &name, uint32_t id, int32_t p = 0, int32_t v = Singer::other)
                    : Worker(name, id), Waiter(name, id, p), Singer(name, id, v) {}
    SingingWaiter(const Worker &wk, int32_t p = 0, int32_t v = Singer::other)
                    : Worker(wk), Waiter(wk, p), Singer(wk, v) {}
    SingingWaiter(const Waiter &wt, int32_t v = Singer::other)
                    : Worker(wt), Waiter(wt), Singer(wt, v) {}
    SingingWaiter(const Singer &sg, int32_t p = 0)
                    : Worker(sg), Waiter(sg, p), Singer(sg) {}

    virtual void set();
    virtual void show() const;
};


#endif

