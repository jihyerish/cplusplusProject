There are provided classes,
* Account - Base class
* Savings Account - Derived class from Account class

An Account has a name and a balance
A Saving Account is an Account and adds an interest rate

Also use account helper functions in Account_util.h and Account_util.cpp

Challenge:

1. Add a Checking account class to the Account hierarchy
    A Checking account has a name and a balance and has a fee of $1.50 per withdrawal transaction
    Every withdrawal transaction will be assessed this flat fee

2. Add a Trust account class to the Account hierarchy
    A Trust account has a name, a balance, and an interest rate
    The trust account deposit works just like a savings account deposit
    However, any deposits of $5000 or more will receive a $50 bonus deposited to the account