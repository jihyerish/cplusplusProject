#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <iostream>
#include <string>

class Account {
    friend std::ostream &operator<<(std::ostream &os, const Account &account);

public:
    Account(std::string name = def_name, double balance = def_balance);
    bool deposit(double amount);
    bool withdraw(double amount);
    double get_balance() const;

protected:
    std::string name;
    double balance;

private:
    static constexpr const char *def_name = "Unnamed Account";
    static constexpr double def_balance = 0.0;

    // same with
    // Account(string name = "Unnamed Account", double balance = 0.0g);
};

#endif