/**
 * @file funadap.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>

void show(double);
const int LIM = 6;

int main(int argc, char **argv)
{
    using namespace std;
    double arr1[LIM] = {28, 29, 30, 35, 38, 39};
    double arr2[LIM] = {63, 65, 69, 75, 80, 99};
    vector<double> gr8(arr1, arr1 + LIM);
    vector<double> m8(arr2, arr2 + LIM);
    cout.setf(ios_base::fixed);
    cout.precision(1);
    cout << "gr8:\t";
    for_each(gr8.begin(), gr8.end(), show);
    cout << endl;
    cout << "m8:\t";
    for_each(m8.begin(), m8.end(), show);
    cout << endl;

    vector<double> prod(LIM);
    transform(gr8.begin(), gr8.end(), prod.begin(),
                bind1st(multiplies<double>(), 2.5));
    cout << "prod:\t";
    for_each(prod.begin(), prod.end(), show);
    cout << endl;

    return 0;
}

void show(double x)
{
    std::cout.width(6);
    std::cout << x << ' ';
}