#include <iostream>


class Account
{
public:
    Account(double init_balance);
    double get_balance();
private:
    double balance = 0.0;
};

Account::Account(double init_balance)
{
    this->balance = init_balance;
}

double Account::get_balance()
{
    return this->balance;
}


int32_t val = 114514;


int main(int argc, char **argv)
{
    /* hide variable */
    int32_t i = 0;
    std::cout << "outer i val => " << i << std::endl;
    {
        int32_t i = 9;
        std::cout << "inner i val => " << i << std::endl;
    }
    std::cout << "outer i val => " << i << std::endl;

    /* hide class name */
    double Account = 147.3;
    std::cout << "This is variable Account => " << Account << std::endl;
    class Account ac(Account);
    std::cout << "This is class Account => " << ac.get_balance() << std::endl;

    /* hide global variable */
    int32_t val = 1919810;
    std::cout << "inner val => " << val << std::endl;
    std::cout << "outer val => " << ::val << std::endl;

    return 0;
}