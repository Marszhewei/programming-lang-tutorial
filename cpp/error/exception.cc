/**
 * @file exception.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <exception>
#include <iostream>
#include <stdexcept>


class bad_hmean : public std::exception
{
public:
    virtual const char *what() { return "bad arguments to hmean()"; }
};

class bad_gmean : public std::exception
{
public:
    virtual const char *what() { return "bad arguments to gmean()"; }
};


int main(int argc, char **argv)
{
    try {
        nullptr;
    } catch (bad_gmean &bg) {
        std::cout << bg.what() << std::endl;
    } catch (bad_hmean &bh) {
        std::cout << bh.what() << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    /* logic-error */
    try {
        nullptr;
    } catch (std::out_of_range &oor) {
        std::cout << oor.what() << std::endl;
    } catch (std::domain_error &de) {
        std::cout << de.what() << std::endl;
    } catch (std::invalid_argument &ia) {
        std::cout << ia.what() << std::endl;
    } catch (std::length_error &le) {
        std::cout << le.what() << std::endl;
    } catch (std::logic_error &le) {
        std::cout << le.what() << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    /* runtime-error */
    try {
        nullptr;
    } catch (std::range_error &re) {
        std::cout << re.what() << std::endl;
    } catch (std::overflow_error &oe) {
        std::cout << oe.what() << std::endl;
    } catch (std::underflow_error &ue) {
        std::cout << ue.what() << std::endl;
    } catch (std::runtime_error &re) {
        std::cout << re.what() << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}