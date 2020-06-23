#ifndef _TRUST_ACCOUNT_H_
#define _TRUST_ACCOUNT_H_
#include <iostream>
#include <string>
#include "Account.h"
#include "Savings_Account.h"
using namespace std;

/*  Trust Account is a special type of Saving Account
*   adds an interest rate
*   Withdraw - same as a regular account
*   Deposit - amount supplied to deposit will be incremented by (account * int_rate/100).
              Plus, any deposits of $5000 or more will receive a $50 bonus deposited to the account.
*             And then the updated amount will be deposited
*/

class Trust_Account : public Savings_Account{
    friend ostream & operator<<(ostream & os, const Trust_Account& account);

public:
    Trust_Account(string name = def_name, double balance = def_balance, double int_rate = def_int_rate, double bonus = def_bonus);
    bool deposit(double amount);

protected:
    double bonus;

private:
    static constexpr const char* def_name = "Unnamed Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 0.0;
    static constexpr double def_bonus = 50.0;
};

#endif