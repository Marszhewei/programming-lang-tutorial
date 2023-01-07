/**
 * @file modern_cpp.cpp
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 现代C++
 * @version 0.1
 * @date 2022-12-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

// 资源和智能指针
#include <memory>
class widget
{
private:
    std::unique_ptr<int[]> data; // 不需要我们在析构函数中显式的释放
public:
    widget(const int size) { data = std::make_unique<int[]>(size); }
    void do_something() { std::cout << "do something here.\n"; }
};

void functionUsingWidget() {
    widget w(1000000);  // lifetime automatically tied to enclosing scope
                        // constructs w, including the w.data gadget member
    // ...
    w.do_something();
    // ...
} // automatic destruction and deallocation for w and w.data


// std::string and std::string_view

// 在标准库时在详细介绍

// std::vector和其它标准库容器(map set...)
vector<string> apples;
// apples.push_back("Granny Smith");


// 标准库算法
void testSTL()
{
    // auto comp = [](const widget& w1, const widget& w2)
    // { return w1.weight() < w2.weight(); }

    // sort( v.begin(), v.end(), comp );

    // auto i = lower_bound( v.begin(), v.end(), widget{0}, comp );

    std::vector<int> v {1,2,3};

    // C-style
    for(int i = 0; i < v.size(); ++i)
        std::cout << v[i];

    // Modern C++:
    for(auto& num : v)
        std::cout << num;
    
    #define SIZE 10 // C-style
    constexpr int size = 10; // modern C++
}

int main(int argc, char **argv)
{
    functionUsingWidget();


    return 0;
}