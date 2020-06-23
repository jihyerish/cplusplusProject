#ifndef _ACCOUNT_UTIL_H_
#define _ACCOUNT_UTIL_H_
#include <vector>
#include "Account.h"
#include "Savings_account.h"
using namespace std;

void display(const vector<Account> &accounts);
void deposit(vector<Account> &accounts, double amount);
void withdraw(vector<Account> &accounts, double amount);

void display(const vector<Savings_Account> &accounts);
void deposit(vector<Savings_Account> &accounts, double amount);
void withdraw(vector<Savings_Account> &accounts, double amount);

#endif