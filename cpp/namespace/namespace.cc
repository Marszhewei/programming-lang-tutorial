/**
 * @file namespace.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief some code about namespace
 * @version 0.1
 * @date 2022-10-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <cmath>


// use nonname namespace to replace static variable
namespace
{
    int32_t var1 = 10;
}
// same as
static int32_t var2 = 10;


namespace A
{
    template<typename tn> void my_print(tn val);
    const double pi = std::acos(-1);
    struct Node
    {
        int32_t data;
        Node *next;
    };
};


namespace B
{
    template<typename tn> void my_print(tn val);
    const double pi = 3.14;
    struct Node
    {
        int32_t data;
        Node *next;
    };
};


namespace C
{
    namespace D
    {
        #define square(x) \
                (x * x)
        double x = 3.2;
    };
};

void test();

int main(int argc, char **argv)
{
    int32_t val = 100;
    A::my_print<int32_t>(val);
    B::my_print<int32_t>(val);

    std::cout << "use square macro and x in namespace D which is in namespace C." << std::endl;
    // macro is not limited by namespace 
    std::cout << "square " << C::D::x << " is : " << square(C::D::x) << std::endl;

    // if we don't want to use :: everytime
    using A::pi;
    // and we can use pi in namespace A directly
    std::cout << "use pi in namespace A : " << pi << std::endl; 

    // use all things in namespace C::D
    using namespace C::D;
    std::cout << "use x in namespace C::D : " << x << std::endl;

    test();

    return 0;
}


void test()
{
    // using A::pi just work in main function
    // std::cout << pi << std::endl;

    // use alias
    namespace CD = C::D;
    using CD::x;
    std::cout << "use x in namespace CD(alias) : " << x << std::endl;
}


namespace A
{
    template<typename tn> void my_print(tn val)
    {
        std::cout << "pi in namespace A is : " << pi << std::endl;
        std::cout << "pi * val is : " << val * pi << std::endl;
    }
};


namespace B
{
    template<typename tn> void my_print(tn val)
    {
        std::cout << "pi in namespace B is : " << pi << std::endl;
        std::cout << "pi * val is : " << val * pi << std::endl;
    }
}