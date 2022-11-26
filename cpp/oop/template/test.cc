/**
 * @file test.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include "stack.h"
#include "array.h"
#include "pairs.h"
#include "template_para.h"
#include "friend.h"

#include <string>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <array>

const int32_t N = 10;

template <typename T>
using arrtype = std::array<T, 10>;


int main(int argc, char **argv)
{
    /* Stack<std::string> st;
    char ch;
    std::string po;
    std::cout << "please enter A to add a purchase order,\n"
              << "P to process a PO, or Q to quit.\n";
    while (std::cin >> ch && std::toupper(ch) != 'Q') {
        while (std::cin.get() != '\n')
            continue;
        if (!std::isalpha(ch)) {
            std::cout << '\a';
            continue;
        }
        switch (ch)
        {
            case 'A':
            case 'a':
                std::cout << "enter a PO number to add: ";
                std::cin >> po;
                if (st.is_full())
                    std::cout << "stack already full.\n";
                else
                    st.push(po);
                break;
            case 'P':
            case 'p':
                if (st.is_empty()) {
                    std::cout << "stack already empty\n";
                } else {
                    st.pop(po);
                    std::cout << "PO #" << po << " popped.\n";
                }
                break;

            default:
                break;
        }
        std::cout << "please enter A to add a purchase order,\n"
                  << "P to process a PO, or Q to quit.\n";
    }
    std::cout << "done.\n"; */

    std::srand(std::time(0));
    std::cout << "please enter stack size: ";
    int32_t stack_size;
    std::cin >> stack_size;

    Stack<const char *> st(stack_size);
    const char *in[N] = {
        " 1: Hank Gilgamesh", " 2: Kiki Ishtar",
        " 3: Betty Rocker", " 4: Ian Flagranti",
        " 5: Wolfgang Kibble", " 6: Portia Koop",
        " 7: Joy Almondo", " 8: Xaverie Paprika",
        " 9: Juan Moore", " 10: Misha Mache"
    };
    const char *out[N];
    int32_t processed = 0;
    int32_t nextin = 0;
    while (processed < N) {
        if (st.is_empty())
            st.push(in[nextin++]);
        else if (st.is_full())
            st.pop(out[processed++]);
        else if (std::rand() % 2 && nextin < N)
            st.push(in[nextin++]);
        else
            st.pop(out[processed++]);
    }
    for (int i = 0; i < N; ++i)
        std::cout << out[i] << std::endl;

    std::cout << "stack done.\n";



    /* the template creates different class */
    Array<int32_t, 2> arr2;
    Array<int32_t, 3> arr3;

    Array<int32_t, 10> sums;
    Array<double, 10> aves;
    Array<Array<int32_t, 5>, 10> twodee;

    for (int i = 0; i < 10; ++i) {
        sums[i] = 0;
        for (int j = 0; j < 5; ++j) {
            twodee[i][j] = (i + 1) * (j + 1);
            sums[i] += twodee[i][j];
        }
        aves[i] = sums[i] / 10.0;
    }
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 5; ++j) {
            std::cout.width(2);
            std::cout << twodee[i][j] << ' ';
        }
        std::cout << ": sum = ";
        std::cout.width(3);
        std::cout << sums[i] << ", average = " << aves[i] << std::endl;
    }
    std::cout << "array done.\n";



    Pairs<std::string, int32_t> ratings[4] = {
        Pairs<std::string, int32_t>("The Purpled Duck", 5),
        Pairs<std::string, int32_t>("Jaquie's Frisco AI Fresco", 4),
        Pairs<std::string, int32_t>("Cafe Souffle", 5),
        Pairs<std::string, int32_t>("Bertie's Eats", 3)
    };
    int32_t joints = sizeof(ratings) / sizeof(Pairs<std::string, int32_t>);
    std::cout << "rating:\t ratery\n";
    for (int i = 0; i < joints; ++i)
        std::cout << ratings[i].second() << ":\t " << ratings[i].first() << std::endl;
    std::cout << "oops! revised rating:\n";
    ratings[3].first() = "Bertie's Fab Eats";
    ratings[3].second() = 6;
    std::cout << ratings[3].second() << ":\t " << ratings[3].first() << std::endl; 


    /* template paraments */
    Crab<Stack, int32_t, double> nebula;
    int32_t ni;
    double nb;
    std::cout << "enter int double pairs, such as 4 3.5 (0 0 to end):\n";
    while (std::cin >> ni >> nb && ni > 0 && nb > 0) {
        if (!nebula.push(ni, nb))
            break;
    }
    while (nebula.pop(ni, nb))
        std::cout << ni << ", " << nb << std::endl;
    std::cout << "template paraments done.\n";



    /* template class and friend */
    std::cout << "no onjects declared: ";
    counts();
    HasFriend<int32_t> hfi1(10);
    std::cout << "after hfi1 declared: ";
    counts();
    HasFriend<int32_t> hfi2(20);
    std::cout << "after hfi2 declared: ";
    counts();
    HasFriend<double> hfdb(10.4);
    std::cout << "after hfdb declared: ";
    counts();
    reports(hfi1);
    reports(hfi2);
    reports(hfdb);
    // bound template friend
    countst<int32_t>();
    HasFriendT<int32_t> hfi32(10);
    HasFriendT<int32_t> hfi32_copy(20);
    HasFriendT<double> hfdouble(10.5);
    reportt(hfi32);
    reportt(hfi32_copy);
    reportt(hfdouble);
    std::cout << "countst<int32_t> output:\n";
    countst<int32_t>();
    std::cout << "countst<double> output:\n";
    countst<double>();
    // unbound template friend
    ManyFriend<int32_t> h1(10);
    ManyFriend<int32_t> h2(20);
    ManyFriend<double> d1(1.23);
    std::cout << "h1, h2: ";
    show2(h1, h2);
    std::cout << "h1, d1: ";
    show2(h1, d1);


    // typedef ?
    arrtype<double> a;
    for (int i = 0; i < 10; ++i)
        std::cout << a[i] << ' ';
    std::cout << std::endl;

    typedef const char * pc1;
    using pc2 = const char *;

    
    return 0;
}
