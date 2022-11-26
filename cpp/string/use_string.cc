/**
 * @file use_string.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief use string
 * @version 0.1
 * @date 2022-11-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <iostream>
#include <string>

using namespace std;

/**
 * template<typename charT, typename traits = char _traits<charT>
 *          typename Allocator = alloctor<charT> >
 * basic_string {...};
 */
// it has four explicit reification
/**
 * typedef basic_string<char> string;
 * typedef basic_string<wchar_t> wstring;
 * typedef basic_string<char16_t> u16string; C++11
 * typedef basic_string<char32_t> u32string; C++11
 */

int main(int argc, char **argv)
{
    string snake1("cobra");
    string snake2("cora1");
    char snake3[20] = "anaconda";
    if (snake1 < snake2)
        cout << "snake1 < snake2\n";
    if (snake1 == snake2)
        cout << "snake1 == snake2\n";
    if (snake1 != snake2)
        cout << "snake1 != snake2\n";
    if (snake1.length() == snake2.size())
        cout << "both strings have the same length.\n";

    return 0;
}