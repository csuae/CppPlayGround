//
//  main.cpp
//  sales
//
//  Created by Chunyou SU on 2020/11/30.
//  Copyright © 2020 csuae. All rights reserved.
//

#include <iostream>
#include "sale.h"

int main(int argc, const char * argv[]) {
    using namespace SALES;
    double saleVal[QUARTERS] = {12.3, 46.7, 32.4, 87.5};
    Sales arr[2];
    setSales(arr[0], saleVal, 4);
    setSales(arr[1]);
    
    showSales(arr[0]);
    showSales(arr[1]);
    
    return 0;
}
