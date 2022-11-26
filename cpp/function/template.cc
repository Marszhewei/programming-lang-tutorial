/**
 * @file template.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief about function template
 * @version 0.1
 * @date 2022-10-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <string>

#define SHOW(arr, n) \
        for (int i = 0; i < n; ++i) \
            std::cout << arr[i] << ' '; \
        std::cout << std::endl; \


struct stu
{
    std::string name;
    int age;
};

template<typename tn> void swapv(tn &a, tn &b);
template<typename tn> void swapv(tn *a, tn *b, int n);
// explicit specialization
template <> void swapv<stu>(stu &a, stu& b);

void swapv(stu &a, stu &b)
{
    stu t;
    t.age = a.age;
    a.age = b.age;
    b.age = t.age;
}

// Implicit instantiation (when I pass in two int type parameters, the function definition is implicitly instantiated) 
template<typename tn> void func(tn &a, tn &b)
{
    tn t = a;
    a = b;
    b = t;
}
// Explicit instantiation (creating an instance of a specific type, i.e. a function definition)
template void func<char>(char &, char &);
// Reified (generate function definition without template, use function definition defined for specified type) 
template <> void func<int>(int &a, int &b);
// or
template <> void func(int &a, int &b);


// we can't know the type of variable
template<typename tn1, typename tn2> void ft(tn1 a, tn2 b)
{
    // use decltype
    decltype(a + b) res = a + b;
}

// but if we don't know the return type?
template<typename tn1, typename tn2> auto gt(tn1 a, tn2 b) -> decltype(a + b)
{
    // ...
    return a + b;
}

int main(int argc, char **argv)
{
    int a = 10, b = 20;
    std::cout << a << ' ' << b << std::endl;
    swapv<int>(a, b);
    std::cout << a << ' ' << b << std::endl;

    double da = 10.1, db = 20.2;
    std::cout << da << ' ' << db << std::endl;
    swapv<double>(da, db);
    std::cout << da << ' ' << db << std::endl;

    const uint32_t c_size = 5;
    int arr1[c_size] {0, 7, 4, 3, 1};
    int arr2[c_size] {2, 8, 8, 2, 0};
    SHOW(arr1, c_size);
    SHOW(arr2, c_size);
    swapv<int>(arr1, arr2, c_size);
    SHOW(arr1, c_size);
    SHOW(arr2, c_size);

    stu stua { "jack", 18 };
    stu stub { "fetch", 20 };
    std::cout << stua.name << ' ' << stua.age << std::endl;
    std::cout << stub.name << ' ' << stub.age << std::endl;
    swapv<stu>(stua, stub);
    std::cout << stua.name << ' ' << stua.age << std::endl;
    std::cout << stub.name << ' ' << stub.age << std::endl;

    return 0;
}


template<typename tn>
void swapv(tn &a, tn &b)
{
    tn t = a;
    a = b;
    b = t;
}


template<typename tn>
void swapv(tn *a, tn *b, int n)
{
    tn t;
    for (int i = 0; i < n; ++i) {
        t = *(a + i);
        *(a + i) = *(b + i);
        *(b + i) = t;
    }
}


template <> void swapv<stu>(stu &a, stu& b)
{
    stu t;
    t.age = a.age;
    a.age = b.age;
    b.age = t.age;
}