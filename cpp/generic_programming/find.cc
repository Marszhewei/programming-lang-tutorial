/**
 * @file find.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief generic programming
 * @version 0.1
 * @date 2022-11-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <iostream>
#include <algorithm>


typedef double *iterator;
iterator find(iterator begin, iterator end, const double &val)
{
    iterator ar;
    for (ar = begin; ar != end; ++ar)
        if (*ar == val)
            return ar;
    return nullptr;
}


struct Node
{
    double item;
    Node *next;
};

class iter
{
private:
    Node *pt;
public:
    iter() : pt(nullptr) {}
    iter(Node *pn) : pt(pn) {}
    double operator*() { return this->pt->item; }
    iter &operator++() { this->pt = this->pt->next; return *this; }                     // ++pr
    iter operator++(int) { iter tmp = *this; this->pt = this->pt->next; return tmp; }   // pr++
    bool operator!=(void *p) { return this->pt->next != p; }
    bool operator==(void *p) { return this->pt->next == p; }
};


iter find_ll(iter head, const double &val)
{
    iter start;
    for (start = head; start != nullptr; ++start)
        if (*start == val)
            return start;
    return nullptr;
}


int main(int argc, char **argv)
{
    return 0;
}