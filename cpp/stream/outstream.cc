/**
 * @file outstream.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief ostream
 * @version 0.1
 * @date 2022-11-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <string>
#include <cstring>


int main(int argc, char **argv)
{
    /* std::cout.put('a').put('b');

    const char *s1 = "florida";
    const char *s2 = "kansas";
    const char *s3 = "euphoria";
    int len = std::strlen(s2);
    std::cout << "increasing loop index:\n";
    for (int i = 1; i <= len; ++i) {
        std::cout.write(s2, i);
        std::cout.put('\n');
    }

    std::cout << "decreasing loop index:\n";
    for (int i = len; i > 0; --i)
        std::cout.write(s2, i) << std::endl;

    std::cout << "exceeding string length:\n";
    std::cout.write(s2, len + 5) << std::endl; */

    freopen("out", "wb", stdout);

    /* int double */
    int i = 10;
    double d = 3.14;
    std::cout << i << ' ' << d << std::endl;

    /* bool */
    bool flag = true;
    std::cout << std::boolalpha << flag << '\n';

    /* char */
    char ch = 'z';
    putchar(ch);
    fputc(ch, stdout);
    std::cout << ch;
    std::cout.put('\n');

    /* char[] */
    char s[10] = "hello";
    puts(s);                    // add
    fputs(s, stdout);
    std::cout << s;
    std::cout.write(s, 5);
    // flush
    std::cout << std::flush;

    /* string */
    std::string str = "ni hao";
    std::cout << str << std::endl;
    
    return 0;
}