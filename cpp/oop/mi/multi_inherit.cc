/**
 * @file multi_inherit.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include "multi_inherit.h"


Worker::~Worker() {}


void Worker::data() const
{
    std::cout << "name: " << this->m_name << std::endl;
    std::cout << "employee ID: " << this->m_id << std::endl;
}


void Worker::get()
{
    getline(std::cin, this->m_name);
    std::cout << "enter worker's ID: ";
    std::cin >> this->m_id;
    while (std::cin.get() != '\n')
        continue;
}


void Worker::set()
{
    std::cout << "enter worker's name: ";
    getline(std::cin, this->m_name);
    std::cout << "enter worker's id: ";
    std::cin >> this->m_id;
    while (std::cin.get() != '\n')
        continue;
}


void Worker::show() const
{
    std::cout << "name: " << this->m_name << std::endl;
    std::cout << "employee ID: " << this->m_id << std::endl;
}


/* Waiter Class Methods */
void Waiter::data() const
{
    std::cout << "panache rating: " << this->m_panache << std::endl;
}


void Waiter::get()
{
    std::cout << "enter waiter's panache rating: ";
    std::cin >> this->m_panache;
    while (std::cin.get() != '\n')
        continue;
}


void Waiter::set()
{
    std::cout << "enter waiter's name: ";
    Worker::get();
    get();
    /* Worker::set();
    std::cout << "enter waiter's panache rating: ";
    std::cin >> this->m_panache;
    while (std::cin.get() != '\n')
        continue; */
}


void Waiter::show() const
{
    std::cout << "category: waiter\n";
    Worker::data();
    data();
    /* Worker::show();
    std::cout << "panache rating: " << this->m_panache << std::endl; */
}


/* Singer Class Methods */
char *Singer::pv[] = {"other", "alto", "contralto", "soprano", "bass",
                        "baritone", "tenor"};


void Singer::data() const
{
    std::cout << "vocal range: " << pv[this->m_voice] << std::endl;
}


void Singer::get()
{
    std::cout << "enter number for singer's vocal range:\n";
    int i;
    for (i = 0; i < vtypes; ++i) {
        std::cout << i << ": " << pv[i] << "  ";
        if (i % 4 == 3)
            std::cout << std::endl;
    }
    if (i % 4 != 0)
        std::cout << std::endl;
    while (std::cin >> this->m_voice && (this->m_voice < 0 || this->m_voice >= vtypes))
        std::cout << "please enter a value >= 0 and < " << vtypes << std::endl;

    while (std::cin.get() != '\n')
        continue;
}


void Singer::set()
{
    std::cout << "enter singer's name: ";
    Worker::get();
    get();
    /* Worker::set();
    std::cout << "enter number for singer's vocal range:\n";
    int i;
    for (i = 0; i < vtypes; ++i) {
        std::cout << i << ": " << pv[i] << "  ";
        if (i % 4 == 3)
            std::cout << std::endl;
    }
    if (i % 4 != 0)
        std::cout << std::endl;
    while (std::cin >> this->m_voice && (this->m_voice < 0 || this->m_voice >= vtypes))
        std::cout << "please enter a value >= 0 and < " << vtypes << std::endl;

    while (std::cin.get() != '\n')
        continue; */
}


void Singer::show() const
{
    std::cout << "category: singer\n";
    Worker::data();
    data();
    /* Worker::show();
    std::cout << "vocal range: " << pv[this->m_voice] << std::endl; */
}


/* SingingWaiter Class Methods */
void SingingWaiter::data() const
{
    Waiter::data();
    Singer::data();
}


void SingingWaiter::get()
{
    Waiter::get();
    Singer::get();
}


void SingingWaiter::set()
{
    std::cout << "enter singing waiter's name: ";
    Worker::get();
    get();
}


void SingingWaiter::show() const
{
    std::cout << "category: singing waiter:\n";
    Worker::data();
    data();
}