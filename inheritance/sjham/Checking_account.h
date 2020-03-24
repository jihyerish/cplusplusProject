#ifndef _CHECKING_ACCOUNT_H_
#define _CHECKING_ACCOUNT_H_
#include <iostream>
#include <string>
#include "Account.h"
using namespace std;

/*  Checking Account is a type of Account
*   adds an fee per withdrawal transaction
*   Deposit - same as a regular account
*   Withdraw - amount supplied to withdraw will be decremented by fee
*               and then the updated amount will be withdrawed
*/

class Checking_Account : public Account {
    friend ostream& operator<<(ostream& os, const Checking_Account& account);

public:
    Checking_Account(string name = def_name, double balance = def_balance, double fee = def_fee);
    bool withdraw(double amount);

protected:
    double fee;

private:
    static constexpr const char* def_name = "Unnamed Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_fee = 1.5;
};

#endif