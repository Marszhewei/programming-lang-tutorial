/**
 * @file typeid.cc
 * @author fetch140zy (Mars_zhewei@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <typeinfo>


class Grand
{
private:
    int32_t m_hold;
public:
    Grand(int32_t hold = 0) : m_hold(hold) {}
    virtual void speak() const { std::cout << "I am a grand class!\n"; }
    virtual int32_t get_hold() const { return this->m_hold; }
};


class Superb : public Grand
{
public:
    Superb(int32_t hold = 0) : Grand(hold) {}
    void speak() const { std::cout << "I am a superb class!\n"; }
    virtual void say() const 
        { std::cout << "I hold the superb value of " << get_hold() << "!\n"; }
};


class Magnificent : public Superb
{
private:
    char ch;
public:
    Magnificent(int32_t hold = 0, char c = 'A') : Superb(hold), ch(c) {}
    void speak() const { std::cout << "I am a magnificent class!\n"; }
    void say() const { std::cout << "I hold the character " << ch 
                                << " and the integer " << get_hold() << "!\n"; }
};


Grand *get_one();

int main(int argc, char **argv)
{
    std::srand(std::time(0));
    Grand *pg;
    Superb *ps;
    for (int i = 0; i < 5; ++i) {
        pg = get_one();
        std::cout << "now processing type " << typeid(*pg).name() << ".\n";
        pg->speak();
        if (ps = dynamic_cast<Superb *>(pg))
            ps->say();
        if (typeid(Magnificent) == typeid(*pg))
            std::cout << "yes, you're rellay magnificent.\n";
    }
    return 0;
}


Grand *get_one()
{
    Grand *p;
    switch(std::rand() % 3)
    {
        case 0: p = new Grand(std::rand() % 100);
                break;
        case 1: p = new Superb(std::rand() % 100);
                break;
        case 2: p = new Magnificent(std::rand() % 100,
                                'A' + std::rand() % 26);
                break;
    }
    return p;
}