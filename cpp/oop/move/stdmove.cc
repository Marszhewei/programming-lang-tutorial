/**
 * @file stdmove.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <iostream>
#include <utility>


class Useless
{
private:
    int n;              // number of elements
    char *pc;           // pointer to data
    static int ct;      // number of objects
    void show_object() const;
public:
    Useless();                  // default constructor
    explicit Useless(int k);
    Useless(int k, char ch);
    Useless(const Useless &f);  // copy constructor
    Useless(Useless &&f);       // move constructor
    ~Useless();
    Useless operator+(const Useless &f) const;
    Useless &operator=(const Useless &f);
    Useless &operator=(Useless &&f);
    void show_data() const;
};

int Useless::ct = 0;

Useless::Useless()
{
    ++ct;
    this->n = 0;
    this->pc = nullptr;
}

Useless::Useless(int k) : n(k)
{
    ++ct;
    this->pc = new char[this->n];
}

Useless::Useless(int k, char ch) : n(k)
{
    ++ct;
    this->pc = new char[this->n];
    for (int i = 0; i < this->n; ++i)
        this->pc[i] = ch;
}

Useless::Useless(const Useless &f) : n(f.n)
{
    ++ct;
    this->pc = new char[this->n];
    for (int i = 0; i < this->n; ++i)
        this->pc[i] = f.pc[i];
}

Useless::Useless(Useless &&f) : n(f.n)
{
    ++ct;
    this->pc = f.pc;
    f.pc = nullptr;
    f.n = 0;
}

Useless::~Useless()
{
    delete [] this->pc;
}

Useless Useless::operator+(const Useless &f) const
{
    Useless tmp = Useless(this->n + f.n);
    for (int i = 0; i < this->n; ++i)
        tmp.pc[i] = this->pc[i];
    for (int i = n; i < tmp.n; ++i)
        tmp.pc[i] = f.pc[i - this->n];
    return tmp;
}

Useless &Useless::operator=(const Useless &f)
{
    std::cout << "copy assigment operator called:\n";
    if (this == &f)
        return *this;
    delete [] this->pc;
    this->n = f.n;
    this->pc = new char[this->n];
    for (int i = 0; i < this->n; ++i)
        this->pc[i] = f.pc[i];
    return *this;
}

Useless &Useless::operator=(Useless &&f)
{
    std::cout << "move assigment operator called:\n";
    if (this == &f)
        return *this;
    delete [] this->pc;
    this->n = f.n;
    this->pc = f.pc;
    f.n = 0;
    f.pc = nullptr;
    return *this;
}

void Useless::show_object() const
{
    std::cout << "number of elements: " << this->n;
    std::cout << " data address: " << (void *)pc << std::endl;
}

void Useless::show_data() const
{
    if (this->n == 0)
        std::cout << "(object empty)";
    else
        for (int i = 0; i < this->n; ++i)
            std::cout << this->pc[i];
    std::cout << std::endl;
}


int main(int argc, char **argv)
{
    Useless one(10, 'x');
    Useless two = one + one;
    std::cout << "object one: ";
    one.show_data();
    std::cout << "object two: ";
    two.show_data();

    Useless three, four;
    std::cout << "three = one\n";
    three = one;
    std::cout << "now onject three = ";
    three.show_data();
    std::cout << "and object one = ";
    one.show_data();
    std::cout << "four = one + two\n";
    four = one + two;
    std::cout << "now object four = ";
    four.show_data();
    std::cout << "four = move(one)\n";
    four = std::move(one);
    std::cout << "now object four = ";
    four.show_data();
    std::cout << "and object one = ";
    one.show_data();

    return 0;
}