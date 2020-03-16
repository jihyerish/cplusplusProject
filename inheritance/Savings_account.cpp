#include "Savings_account.h"
using namespace std;

Savings_Account::Savings_Account(string name, double balance, double int_rate)
    : Account{name, balance}, int_rate{int_rate} {

}

bool Savings_Account::deposit(double amount) {
    amount += amount * (int_rate/100);
    return Account::deposit(amount);
}

ostream &operator<<(ostream &os, const Savings_Account &account)
{
    os << "[Savings Account: " << account.name << " : " << account.balance << "," << account.int_rate << "% ]";
    return os;
}