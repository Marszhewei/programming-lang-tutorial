/**
 * @file sstream.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief incore formatting
 * @version 0.1
 * @date 2022-11-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <sstream>
#include <string>


int main(int argc, char **argv)
{
    using namespace std;

    ostringstream outstr;
    string hdisk;
    cout << "what's the name of your hard disk? ";
    getline(cin, hdisk);
    int cap;
    cout << "what's its capacity in GB? ";
    cin >> cap;

    outstr << "the hard disk " << hdisk << " has a capacity of "
            << cap << " gigabytes.\n";
    string res = outstr.str();
    cout << res;

    return 0;
}