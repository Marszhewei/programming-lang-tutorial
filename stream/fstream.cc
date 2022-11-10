/**
 * @file fstream.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief ifstream ofstream
 * @version 0.1
 * @date 2022-11-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <iostream>
#include <string>
#include <fstream>


int main(int argc, char **argv)
{
    using namespace std;

    string s;

    /**
     * ios_base::in     open file(read)
     * ios_base::out    open file(write)
     * ios_base::ate    open file(move to the end of file)
     * ios_base::app    append
     * ios_base::trunc  cover
     * ios_base::binary binary
     */

    ifstream fin;
    fin.open("input");
    // or 
    // ifstream fin ("input");
    if (!fin.is_open()) {   // fin.fail() or !fin or !fin.good()
        cerr << "open file failed.\n";
        exit(EXIT_FAILURE);
    }
    getline(fin, s);

    ofstream fout;
    fout.open("output", ios_base::out | ios_base::app);
    // or 
    // ofstream fout ("output");
    fout << s << endl;

    fin.clear();
    fin.close();
    fout.clear();
    fout.close();

    return 0;
}