#ifndef _SAVINGS_ACCOUNT_H_
#define _SAVINGS_ACCOUNT_H_
#include <iostream>
#include <string>
#include "Account.h"
using namespace std;

/*  Savings Account is a type of Account
*   adds an interest rate
*   Withdraw - same as a regular account
*   Deposit - amount supplied to deposit will be incremented by (account * int_rate/100)
*               and then the updated amount will be deposited
*/

class Savings_Account: public Account {
    friend ostream &operator<<(ostream &os, const Savings_Account &account);

public:
    Savings_Account(string name = def_name, double balance = def_balance, double int_rate = def_int_rate);
    bool deposit(double amount);

protected:
    double int_rate;

private:
    static constexpr const char *def_name = "Unnamed Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 0.0;
};

#endif