/**
 * @file lambda.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief lambda function
 * @version 0.1
 * @date 2022-11-11
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <functional>

// use function pointer
bool f3(int x) { return x % 3 == 0; }
bool f13(int x) { return x % 13 == 0; }

// use functor
class f_mod
{
private:
    int dv;
public:
    f_mod(int d = 1) : dv(d) {}
    bool operator()(int x) { return x % dv == 0; }
};

int main(int argc, char **argv)
{
    std::srand(std::time(0));
    std::vector<int> numbers(1000);
    std::generate(numbers.begin(), numbers.end(), std::rand);

    // use function pointer
    int cnt3 = std::count_if(numbers.begin(), numbers.end(), f3);
    int cnt13 = std::count_if(numbers.begin(), numbers.end(), f13);
    std::cout << "cnt3 = " << cnt3 << ", " << "cnt13 = " << cnt13 << std::endl;

    // use functor
    cnt3 = std::count_if(numbers.begin(), numbers.end(), f_mod(3));
    cnt13 = std::count_if(numbers.begin(), numbers.end(), f_mod(13));
    std::cout << "cnt3 = " << cnt3 << ", " << "cnt13 = " << cnt13 << std::endl;

    // use lambda function
    cnt3 = std::count_if(numbers.begin(), numbers.end(), 
                            [](int x) -> bool { return x % 3 == 0; } );
    cnt13 = std::count_if(numbers.begin(), numbers.end(), 
                            [](int x) -> bool { return x % 13 == 0; } );
    std::cout << "cnt3 = " << cnt3 << ", " << "cnt13 = " << cnt13 << std::endl;
    // if we want to use the same lambda function twicens
    auto mod3 = [](int x) ->bool { return x % 3 == 0; };
    auto mod13 = [](int x) -> bool { return x % 13 == 0; };
    cnt3 = std::count_if(numbers.begin(), numbers.end(), mod3);
    cnt13 = std::count_if(numbers.begin(), numbers.end(), mod13);
    std::cout << "cnt3 = " << cnt3 << ", " << "cnt13 = " << cnt13 << std::endl;
    // and we can use lambda function as the simple function
    bool res = mod3(100);
    std::cout << "100 can div by s: " << std::boolalpha << res << std::endl;

    // & =
    /**
     * use all variables by value
     * [=](int x) { } 
     * use all variables by reference
     * [&](int x) { }
     */
    cnt13 = 0;
    std::for_each(numbers.begin(), numbers.end(), 
                    [&cnt13](int x) { cnt13 += x % 13 == 0; });
    std::cout << "cnt13 = " << cnt13 << std::endl;
    cnt3 = 0, cnt13 = 0;
    std::for_each(numbers.begin(), numbers.end(),
                    [&](int x) { cnt3 += x % 3 == 0, cnt13 += x % 13 == 0; });
    std::cout << "cnt3 = " << cnt3 << ", " << "cnt13 = " << cnt13 << std::endl;

    return 0;
}