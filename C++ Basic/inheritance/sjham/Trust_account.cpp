#include "Trust_account.h"
using namespace std;

Trust_Account::Trust_Account(string name, double balance, double int_rate, double bonus)
    : Savings_Account{ name, balance, int_rate }, bonus{ bonus } {

}

bool Trust_Account::deposit(double amount) {
    if (amount >= 5000)
        amount += bonus;
    return Savings_Account::deposit(amount);
}

ostream& operator<<(ostream& os, const Trust_Account& account)
{
    os << "[Trust Account: " << account.name << " : " << account.balance << "," << account.int_rate << "%," << " $" << account.bonus << "]";
    return os;
}