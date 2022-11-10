/**
 * @file instream.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief IO
 * @version 0.1
 * @date 2022-11-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <cstdio>
#include <istream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
    freopen("in", "r", stdin);
    freopen("out", "wb", stdout);

    /* int double */
    int32_t i32v = 100;
    double d1 = 3.14;
    std::cin >> i32v >> d1;
    std::cout << "int32_t val => " << i32v << std::endl;
    std::cout << "double val => " << i32v << std::endl;

    /* bool */
    bool flag = true;
    std::cin >> flag;
    std::cout << "bool val => " << std::boolalpha << flag << std::endl;

    /* char */
    getchar();
    char ch;
    std::cin.get(ch);
    std::cout << "char val => " << ch << std::endl;
    ch = std::cin.get();
    std::cout << "char val => " << ch << std::endl;
    ch = getchar();
    std::cout << "char val => " << ch << std::endl;
    ch = fgetc(stdin);
    std::cout << "char val => " << ch << std::endl;
    std::cin >> ch;
    std::cout << "char val => " << ch << std::endl;

    /* char[] */
    char pcv[100];
    // read the \n
    getchar();
    // read a word, you need to use getchar to read \n
    std::cin >> pcv;
    std::cout << "char * val => " << pcv << std::endl;
    getchar();
    // read a line, but you don't need to use getchar to read \n
    std::cin.getline(pcv, 100, '?');
    while (ch != '\n')
        ch = getchar();
    ch = '\0';
    std::cout << "char * val => " << pcv << std::endl;
    // read a line, but you need to use getchar to read \n
    std::cin.get(pcv, 100);
    std::cout << "char * val => " << pcv << std::endl;


    // std::string
    std::string sv;
    // read a word
    std::cin >> sv;
    std::cout << "string val => " << sv << std::endl;
    getchar();
    // read a line, discard \n
    getline(std::cin, sv, ':'); // end with :
    while (ch != '\n')
        ch = getchar();
    std::cout << "string val => " << sv << std::endl;

    /* read loop until read # */
    int cnt = 0;
    std::cin.get(ch);
    while ('#' != ch) {
        std::cout << ch;
        ++cnt;
        std::cin.get(ch);
    }
    std::cout << std::endl << "characters counter = " << cnt << std::endl;
    while (ch != '\n')
        ch = getchar();

    /* read loop until eof */
    cnt = 0;
    std::cin.get(ch);
    while (!std::cin.fail()) {  // (ch != EOF) or !std::cin.eof()
        std::cout << ch;
        ++cnt;
        std::cin.get(ch);
    }
    std::cout << std::endl << "characters counter = " << cnt << std::endl;

    /* use owe std::cin */
    int n = 0;
    std::istream mycin(nullptr);
    std::filebuf fb;
    fb.open(nullptr, std::ios_base::in);
    mycin.rdbuf(&fb);
    mycin >> n;
    std::cout << n << std::endl;

    std::ifstream fin;
    fin.open("a.in");
    std::ofstream fout;
    fout.open("a.out");
    int a;
    while (fin >> a) {
        fout << a << ' ';
    }
    /*
    while (!fin.eof()) {
        fin >> a;
        fout << a << ' ';
    }
    */
    fout << std::endl;

    fin.close();
    fout.close();

    return 0;
}
