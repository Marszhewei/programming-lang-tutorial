/**
 * @file main.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include "hasa.h"


void set(Student &sa, int32_t n);
const int32_t pupils = 3;
const int32_t quizzes = 5;


int main(int argc, char **argv)
{
    Student ada[pupils] = {Student(quizzes), Student(quizzes), Student(quizzes)};
    for (int i = 0; i < pupils; ++i)
        set(ada[i], quizzes);
    std::cout << "\nstudent list:\n";
    for (int i = 0; i < pupils; ++i)
        std::cout << ada[i].get_name() << std::endl;
    std::cout << "\nresults:";
    for (int i = 0; i < pupils; ++i) {
        std::cout << std::endl << ada[i];
        std::cout << "average: " << ada[i].average() << std::endl;
    }
    std::cout << "done.\n";
    
    return 0;
}


void set(Student &sa, int32_t n)
{
    std::cout << "please enter the student's name: ";
    getline(std::cin, sa);
    std::cout << "please enter " << n << " quiz scores:\n";
    for (int i = 0; i < n; ++i)
        std::cin >> sa[i];
    while (std::cin.get() != '\n')
        continue;
}