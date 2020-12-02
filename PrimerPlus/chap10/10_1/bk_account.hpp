//
//  bk_account.hpp
//  bank_account
//
//  Created by Chunyou SU on 2020/12/1.
//  Copyright © 2020 csuae. All rights reserved.
//

#ifndef bk_account_hpp
#define bk_account_hpp

#include <iostream>
#include <string>

class BankAccount
{
private:
    std::string m_name;
    int m_numberID;
    double m_balance;
public:
    BankAccount() {m_name=""; m_numberID=0; m_balance=0;}; //Default Constructor
    BankAccount(const std::string name="None", int numberID=0, double balance=0.0); //Constructor
    ~BankAccount();
    void Display() const;
    void Deposit(double InBalance);
    void Withdraw(double OutBalance);
};

#endif /* bk_account_hpp */
