/**
 * @file main.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include "str.h"


/**
 * how to use copy constructor
 * 1. String b(a);
 * 2. String b = a;
 * 3. String b = String(a);
 * 4. String *pb = new String(a);
*/


void call1(String &s);
void call2(String s);


const int32_t buf_size = 0xffff; 


int main(int argc, char **argv)
{
    String s1("everything is ok.");
    String s2 = String("yeap.");
    String s3;
    // something wrong here(fixing by create copy constructor)
    String s2_copy = s2;

    std::cout << "s1 is: " << s1 << std::endl;
    call1(s1);      // by reference  
    call2(s1);          // by value
    // something wrong here(fixing by create copy constructor)
    std::cout << "s1 is: " << s1 << std::endl;
    std::cout << "s2 is: " << s2 << std::endl;
    std::cout << "s3 is: " << s3 << std::endl;
    std::cout << "s2 copy is: " << s2_copy << std::endl;

    // something wrong here(fixing by overload operator=)
    s2_copy = s1;
    std::cout << "s2 copy? s1 copy!: " << s2_copy << std::endl;
    std::cout << "string nums is: " << String::how_many() << std::endl;

    String *ps = new String("in heap.");
    std::cout << "*ps is: " << *ps << std::endl;
    delete ps;
    ps = nullptr;

    // must call the ~String to free memory
    char *buffer = new char[buf_size];
    String *p = new (buffer) String("in buffer.");
    std::cout << "*p is: " << *p << std::endl;
    p->~String();
    delete [] buffer;
    buffer = nullptr;

    return 0;
}


void call1(String &s)
{
    std::cout << "string passed by reference:\n";
    std::cout << "    \"" << s << "\"\n";
}


void call2(String s)
{
    std::cout << "string passed by value:\n";
    std::cout << "    \"" << s << "\"\n";
}