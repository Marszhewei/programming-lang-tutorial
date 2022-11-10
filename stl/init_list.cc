/**
 * @file init_list.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief initializer list (C++11)
 * @version 0.1
 * @date 2022-11-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <iostream>
#include <initializer_list>

double sum(std::initializer_list<double> il);
double average(const std::initializer_list<double> &ril);


int main(int argc, char **argv)
{
    using namespace std;

    cout << "list 1: sum = " << sum({2, 3, 4})
              << ", ave = " << average({2, 3, 4}) << endl;
    initializer_list<double> dl = {1.1, 2.2, 3.3, 4.4, 5.5};
    cout << "list 2: sum = " << sum(dl) << ", ave = "
         << average(dl) << endl;
    dl = {16.0, 25.0, 36.0, 40.0, 64.0};
    cout << "list 3: sum = " << sum(dl)
         << ", ave = " << average(dl) << endl;
        
    return 0;
}


double sum(std::initializer_list<double> il)
{
    double tot = 0;
    for (auto p = il.begin(); p != il.end(); ++p)
        tot += *p;
    return tot;
}


double average(const std::initializer_list<double> &ril)
{
    double tot = 0;
    int n = ril.size();
    double ave = 0;
    if (n > 0) {
        for (auto p = ril.begin(); p != ril.end(); ++p)
            tot += *p;
        ave = tot / n;
    }
    return ave;
}