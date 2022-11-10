/**
 * @file move.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief move semantics
 * @version 0.1
 * @date 2022-11-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <iostream>

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
    std::cout << "default constructor called; number of objects: " << ct << std::endl;
    show_object();
}

Useless::Useless(int k) : n(k)
{
    ++ct;
    std::cout << "int constructor called; number of objects: " << ct << std::endl;
    this->pc = new char[this->n];
    show_object();
}

Useless::Useless(int k, char ch) : n(k)
{
    ++ct;
    std::cout << "int, char constructor called; number of objects: " << ct << std::endl;
    this->pc = new char[this->n];
    for (int i = 0; i < this->n; ++i)
        this->pc[i] = ch;
    show_object();
}

Useless::Useless(const Useless &f) : n(f.n)
{
    ++ct;
    std::cout << "copy constructor called; number of objects: " << ct << std::endl;
    this->pc = new char[this->n];
    for (int i = 0; i < this->n; ++i)
        this->pc[i] = f.pc[i];
    show_object();
}

Useless::Useless(Useless &&f) : n(f.n)
{
    ++ct;
    std::cout << "move constructor called; number of objects: " << ct << std::endl;
    this->pc = f.pc;
    f.pc = nullptr;
    f.n = 0;
    show_object();
}

Useless::~Useless()
{
    std::cout << "destructor called; objects left: " << --ct << std::endl;
    std::cout << "deleted object:\n";
    show_object();
    delete [] this->pc;
}

Useless Useless::operator+(const Useless &f) const
{
    std::cout << "enter operator+()\n";
    Useless tmp = Useless(this->n + f.n);
    for (int i = 0; i < this->n; ++i)
        tmp.pc[i] = this->pc[i];
    for (int i = n; i < tmp.n; ++i)
        tmp.pc[i] = f.pc[i - this->n];
    std::cout << "tmp object:\n";
    std::cout << "leaving operator+()\n";
    return tmp;
}

Useless &Useless::operator=(const Useless &f)
{
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
    std::cout << " dara address: " << (void *)pc << std::endl;
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
    Useless two (one);
    Useless three(20, 'o');
    // but it output any info about move constructor
    // because of the compiler optimization
    Useless four = (one + three);
    std::cout << "object one: ";
    one.show_data();
    std::cout << "object two: ";
    two.show_data();
    std::cout << "object three: ";
    three.show_data();
    std::cout << "object four: ";
    four.show_data();

    return 0;
}