//
//  main.cpp
//  bank_account
//
//  Created by Chunyou SU on 2020/12/1.
//  Copyright © 2020 csuae. All rights reserved.
//

#include <iostream>
#include "bk_account.hpp"

int main(int argc, const char * argv[]) {
    BankAccount Anne("Anne", 1, 256.00);
    //BankAccount Anne;
    Anne.Display();
    Anne.Deposit(144.50);
    Anne.Display();
    Anne.Withdraw(300.10);
    Anne.Display();
    
    return 0;
}
