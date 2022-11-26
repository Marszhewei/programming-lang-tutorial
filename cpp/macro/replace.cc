/**
 * @file replace.cc
 * @author fetch50zy (Mars_zhewei@outlook.com)
 * @brief some macro
 * @version 0.1
 * @date 2022-10-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <cstdio>
#include <tuple>

// info
#define RUNTIME_INFO() \
    if (1 == __STDC_HOSTED__) { \
        std::cout << "It is runing on OS." << std::endl; \
    } else { \
        std::cout << "It is not runing on OS." << std::endl; \
    } \
    std::cout << "Cpp version   => " <<  __cplusplus << std::endl; \
    std::cout << "File name     => " << __FILE__ << std::endl; \
    std::cout << "Call at       => " << __LINE__ << std::endl; \
    std::cout << "Run date      => " << __DATE__ << std::endl; \
    std::cout << "Run time      => " << __TIME__ << std::endl; \
    std::cout << "std::size_t   => " << __STDCPP_DEFAULT_NEW_ALIGNMENT__ << std::endl; \
    std::cout << "Something about C\n"; \
    std::cout << "C             => " << __STDC__ << std::endl; \
    std::cout << "About Unicode => " << __STDC_ISO_10646__ << std::endl; \
    std::cout << "About thread  => " << __STDCPP_THREADS__ << std::endl; \
    // std::cout << "C version     => " << __STDC_VERSION__ << std::endl; \
    std::cout << "Support std::pointer_safety   => " << __STDCPP_STRICT_POINTER_SAFETY__ << std::endl; \



// #define label replace_list
#define REPLACE_TEXT "this is a replace text."
// #define label(args) replace_list
#define ADD(x1, x2) \
    (x1 + x2)
// #define label(args, ...) replace_list
#define DEBUG(id, ...) \
    printf("Error id: %d ==> %s%s\n", id, ##__VA_ARGS__) // __VA_ARGS__ is empty, ignore ,
// #define label(...) replace_list
#define INIT(...) \
    { __VA_ARGS__ }

// #undef label
#define TEMP 1145141919810
#undef TEMP

// # and ##
#define EVERYTHING_TO_STRING(t) \
    #t
#define FUNC_AUTOMATON(name) \
    void func_##name() { \
        std::cout << "This is func_" << #name << std::endl; \
    }
FUNC_AUTOMATON(a)
FUNC_AUTOMATON(b)


// self __VA_OPT__ (get length of __VA_ARGS__) ==> max length is 9
#define ELEVENTH(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, N, ...) N
#define COUNT_DURING_PREPROCESS(...) ELEVENTH(dummy, ##__VA_ARGS__, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)

// at compile time
#define COUNT_DURING_COMPILE(...) \
    std::tuple_size<decltype(std::make_tuple(__VA_ARGS__))>::value

// final __VA_OPT__
#define CAT(a, b) a##b
#define FIRST(first, ...) first
#define SECOND(first, second, ...) second
#define IS_PROBE(...) SECOND(__VA_ARGS__, 0)
#define PROBE() ~, 1
#define NOT(x) IS_PROBE(CAT(_NOT_, x))
#define _NOT_0 PROBE()
#define BOOL(x) NOT(NOT(x))
#define HAS_ARGS(...) BOOL(FIRST(_END_OF_ARGUMENTS_ __VA_ARGS__)())
#define _END_OF_ARGUMENTS_() 0

#define IF_ELSE(condition) _IF_ELSE(BOOL(condition))
#define _IF_ELSE(condition) CAT(_IF_, condition)
#define _IF_1(...) __VA_ARGS__ _IF_1_ELSE
#define _IF_0(...) _IF_0_ELSE
#define _IF_1_ELSE(...)
#define _IF_0_ELSE(...) __VA_ARGS__

#define TENTH(_1, _2, _3, _4, _5, _6, _7, _8, _9, N, ...) N
#define COUNT(...) \
    IF_ELSE(HAS_ARGS(__VA_ARGS__)) \
    (TENTH(__VA_ARGS__, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0))(0)


#define CHECK_RET(expr, ...) \
    do { \
        int _ret = (expr); \
        if (0 != _ret) { \
            return IF_ELSE(HAS_ARGS(__VA_ARGS__))(__VA_ARGS__)(_ret); \
        } \
    } while (0)

// use class with macro realize
/*
* do {
*     ...;
*     if(...) break;
*     ...;
*     if (...) break;
*     ...;
* } while(0);
*/
class CheckRet {
public:
    template <class F>
    auto operator-(const F &func) -> typename std::result_of<F()>::type {
        return func();
    }
};
#define BLOCK CheckRet() - [&]


int main(int argc, char **argv)
{
    RUNTIME_INFO()
// #ifdef REPLACE_TEXT
    std::cout << REPLACE_TEXT << std::endl;
    std::cout << ADD(10, 20) << std::endl;
    DEBUG(10, "The index is ", "out of boundary.");
    int arr[] = INIT(1, 2, 3);
    for (auto i: arr) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
    std::cout << "This is " << EVERYTHING_TO_STRING(string) << std::endl;
    func_a();
    func_b();

    std::cout << COUNT_DURING_PREPROCESS(0) << std::endl;
    std::cout << COUNT_DURING_PREPROCESS(0, 1) << std::endl;
    std::cout << COUNT_DURING_PREPROCESS(0, 1, 2) << std::endl;

    std::cout << COUNT_DURING_COMPILE(0) << std::endl;
    std::cout << COUNT_DURING_COMPILE(0, 1) << std::endl;
    std::cout << COUNT_DURING_COMPILE(0, 1, 2) << std::endl;
    std::cout << COUNT_DURING_COMPILE(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12) << std::endl;


    CHECK_RET(0);
    CHECK_RET(1, 200);

    int ret = BLOCK {
        nullptr;
        if (true) return -1;
        nullptr;
        if (false) return -2;
        nullptr;
        return 0;
    };
// #endif
    return 0;
}