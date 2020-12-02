//
//  bk_account.cpp
//  bank_account
//
//  Created by Chunyou SU on 2020/12/1.
//  Copyright © 2020 csuae. All rights reserved.
//

#include <iomanip>
#include "bk_account.hpp"

BankAccount::BankAccount(const std::string name, int numberID, double balance)
{
    m_name = name;
    m_numberID = numberID;
    m_balance = balance;
}

BankAccount::~BankAccount()
{
    // doing nothing
}

void BankAccount::Display(void) const
{
    using namespace std;
    cout << "Account Name:\t\t" << m_name << endl;
    ios_base::fmtflags orig(cout.flags());
    
    cout.fill('0');
    cout << "Number ID:\t\t\t" << setw(6) << m_numberID << endl;
    cout.setf(ios_base::fixed);
    cout.precision(2);
    cout << "Remaining Balance:\t" << m_balance << endl;
    cout.flags(orig);
}

void BankAccount::Deposit(double InBalance)
{
    if (InBalance <= 0)
        std::cout << "Increased Balance must be positive\n";
    m_balance += InBalance;
}

void BankAccount::Withdraw(double OutBalance)
{
    if (OutBalance <= 0)
        std::cout << "Intended Withdraw Money must be positive\n";
    else if (OutBalance > m_balance)
        std::cout << "Current Balance $" << m_balance << " is not sufficient\n";
    else
        m_balance -= OutBalance;
}
