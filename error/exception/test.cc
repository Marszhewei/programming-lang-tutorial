/**
 * @file test.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include "sales.h"


int main(int argc, char **argv)
{
    double vals1[12] = {
        1220, 1100, 1122, 2212, 1232, 2334,
        2884, 2393, 3302, 2922, 3002, 3544
    };
    double vals2[12] = {
        12, 11, 22, 21, 32, 34,
        28, 29, 33, 29, 32, 35
    };
    Sales sales1(2011, vals1, 12);
    LabeledSales sales2("blogstar", 2012, vals2, 12);

    std::cout << "first try block:\n";
    try {
        int32_t i;
        std::cout << "year = " << sales1.get_year() << std::endl;
        for (i = 0; i < 12; ++i) {
            std::cout << sales1[i] << ' ';
            if (i % 6 == 5)
                std::cout << std::endl;
        }
        std::cout << "year = " << sales2.get_year() << std::endl;
        std::cout << "label = " << sales2.get_label() << std::endl;
        for (i = 0; i < 12; ++i) {
            std::cout << sales2[i] << ' ';
            if (i % 6 == 5)
                std::cout << std::endl;
        }
        std::cout << "end of try block 1.\n";
    } catch (LabeledSales::nbad_index &bad) {
        std::cout << bad.what();
        std::cout << "company: " << bad.label_val() << std::endl;
        std::cout << "bad index: " << bad.get_index() << std::endl;
    } catch (Sales::bad_index &bad) {
        std::cout << bad.what();
        std::cout << "bad index: " << bad.get_index() << std::endl;
    }

    std::cout << "\nnext try block:\n";
    try {
        sales2[2] = 37.5;
        sales2[20] = 23345;
        std::cout << "end of try block 2.\n";
    } catch (LabeledSales::nbad_index &bad) {
        std::cout << bad.what();
        std::cout << "company: " << bad.label_val() << std::endl;
        std::cout << "bad index: " << bad.get_index() << std::endl;
    } catch (Sales::bad_index &bad) {
        std::cout << bad.what();
        std::cout << "bad index: " << bad.get_index() << std::endl;
    }
    std::cout << "done.\n";
    
    return 0;
}