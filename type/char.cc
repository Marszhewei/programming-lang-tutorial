/**
 * @file char.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief char char8_t (c++20) char16_t char32_t wchar_t (c++11) raw string
 * @version 0.1
 * @date 2022-10-17
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <string>

using namespace std::literals::string_literals;


int main(int argc, char **argv)
{
    /* base char (8 bits) */
    char base_ch = 'a';
    std::cout << "base char    => " << base_ch << std::endl;
    char base_s[] = "This is base string.";
    std::cout << "base char *  => " << base_s << std::endl;


    /* wchar_t (16 bits or 32 bits(GNU)) */
    wchar_t wide_ch = L'p';
    std::wcout << "wchar_t      => " << wide_ch << std::endl;
    wchar_t wide_s[] = L"This is wchar_t string.";
    std::wcout << "wchar_t *    => " << wide_s << std::endl;


    /* char8_t (8 bits) char16_t (16 bits) char32_t (32 bits) */
    char8_t ch8 = u8'b';
    std::wcout << "char8_t      => " << (char)ch8 << std::endl;
    // using the char16_t type is something that you need to consider carefully
    // char16_t ch16 = u'q';
    // std::wcout << "char16_t     => " << (wchar_t)ch16 << std::endl;
    // char16_t ch16_s[] = u    "This is char16_t string.";
    // std::wcout << "char16_t *   => " << (wchar_t*)ch16_s << std::endl;
    char32_t ch32 = U'i';
    std::wcout << "char32_t     => " << (wchar_t)ch32 << std::endl;
    char32_t ch32_s[] = U"This is char32_t string.";
    std::wcout << "char32_t *   => " << (wchar_t *)ch32_s << std::endl;
    /* not recommand use wcout and cout at the same time */
    freopen(nullptr, "a", stdout);

    /* raw string */
    char raw_s[] = R"(you can "see" the () and \n.)";
    std::cout << "raw string   => " << raw_s << std::endl;
    /* )" in string */
    char raw_ss[] = R"+*("(\n)")+*";
    std::cout << "raw string   => " << raw_ss << std::endl;


    /* std::string text */
    std::string s = "this is basic string."s;
    std::u8string u8s = u8"this is u8string."s;
    std::wstring ws = L"this is wchar_t string."s;
    std::u16string u16s = u"this is u16string."s;
    std::u32string u32s = U"this is u32string."s;
    std::u32string u32sr = UR"(this is raw u32string.)"s;

    
    /* get string length */
    const wchar_t *str = L"wchar_t string";
    const size_t byte_size = (wcslen(str) + 1) * sizeof(wchar_t);
    std::cout << "byte size of wchar_t string => " << byte_size << std::endl;
    /* others */
    const std::string cs = "this is "s + "string"s;
    std::cout << "contect string => " << cs << std::endl;
    std::cout << "emoji => \U0001F60E" << std::endl;

    return 0;
}
