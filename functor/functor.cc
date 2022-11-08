/**
 * @file functor.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

template <typename T>
bool too_big(const T &val, const T &lim) { return val > lim; }

template <typename T>
class TooBig2
{
private:
    T m_cutoff;
public:
    TooBig2(const T &t) : m_cutoff(t) {}
    bool operator()(const T &v) { return too_big<T>(v, this->m_cutoff); }
};

template <typename T>
class TooBig
{
private:
    T m_cutoff;
public:
    TooBig(const T &t) : m_cutoff(t) {}
    bool operator() (const T &v) { return v > this->m_cutoff; }
};

void output(int n) { std::cout << n << ' '; }

int main(int argc, char **argv)
{
    using namespace std;
    TooBig<int> f100(100);
    int vals[10] = {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};
    list<int> yadayada(vals, vals + 10);
    list<int> etcetera(vals, vals + 10);
    std::cout << "original lists:\n";
    for_each(yadayada.begin(), yadayada.end(), output);
    cout << endl;
    for_each(etcetera.begin(), etcetera.end(), output);
    cout << endl;
    // use a named function object
    yadayada.remove_if(f100);
    // construct a function object
    etcetera.remove_if(TooBig<int>(200));
    cout << "trimmed lists:\n";
    for_each(yadayada.begin(), yadayada.end(), output);
    cout << endl;
    for_each(etcetera.begin(), etcetera.end(), output);
    cout << endl;

    return 0;
}
