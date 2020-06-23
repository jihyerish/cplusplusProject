#include <iostream>
#include <vector>
#include "Savings_account.h"
#include "Account.h"
#include "Account_util.h"

using namespace std;

int main() {
    cout.precision(2);
    cout << fixed;

    // Accounts
    vector<Account> accounts;
    accounts.push_back(Account {});
    accounts.push_back(Account {"Amy"});
    accounts.push_back(Account {"Bill", 2000});
    accounts.push_back(Account {"Chris", 5000});

    //display(accounts);
    //deposit(accounts, 1000);
    //withdraw(accounts, 2000);

    // Savings

    return 0;
}