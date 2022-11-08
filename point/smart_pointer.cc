/**
 * @file smart_pointer.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief C++ smart pointer (RAII)
 * @version 0.1
 * @date 2022-10-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <memory>

// differences among auto_ptr(c++98), unique_ptr(c++11), shared_ptr(c++11)
/**
 * owership (assignment transfers ownership)
 * auto_ptr and shared_ptr(stricter)
 * reference counting
 * shared_ptr(when the last pointer expires, free the memory)
 */


class Report
{
private:
    std::string m_str;
public:
    Report(const std::string s) : m_str(s) { std::cout << "Object created.\n"; }
    ~Report() { std::cout << "Object deleted.\n"; }
    void say() const { std::cout << this->m_str << "\n"; }
};


int main(int argc, char **argv)
{
    /* {
        std::auto_ptr<Report> ps (new Report("using auto_ptr"));
        ps->say();
    } */
    {
        std::shared_ptr<Report> ps (new Report("using shared_ptr"));
        ps->say();
    }
    {
        std::unique_ptr<Report> ps (new Report("using unique_ptr"));
        ps->say();
    }

    /* explicit constructor */
    std::shared_ptr<double> pd;
    double *p_reg = new double;
    // pd = p_reg;     not allowed(implicit conversion)
    pd = std::shared_ptr<double>(p_reg);
    // std::shared_ptr<double> pshared = p_reg;    not allowed(implicit conversion)
    std::shared_ptr<double> pshared(p_reg);

    //! avoid
    /* std::string vac("I wandered lonely as a cloud.");
    std::shared_ptr<std::string> pvac(&vac); */            // NO!!!

    return 0;
}
