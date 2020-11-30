//
//  sale.cpp
//  sales
//
//  Created by Chunyou SU on 2020/11/30.
//  Copyright © 2020 csuae. All rights reserved.
//

#include <iostream>
#include "sale.h"

namespace SALES {
    void setSales(Sales & s, const double ar[], int n)
    {
        int i, num = (n<QUARTERS) ? n : QUARTERS;
        double max=ar[0], min=ar[0], avg=0;
        for (i=0; i<num; i++)
        {
            max = (ar[i]>max) ? ar[i] : max;
            min = (ar[i]<min) ? ar[i] : min;
            s.sales[i] = ar[i];
            avg += ar[i];
        }
        avg /= QUARTERS;
        for (; i<QUARTERS; i++)
            s.sales[i] = 0;
        s.max = max;
        s.min = min;
        s.average = avg;
    }
    void setSales(Sales & s)
    {
        using namespace std;
        double sale, max=0, min=0, avg=0;
        for (int i=0; i<QUARTERS; i++)
        {
            cout << "Input the sale for " << i+1 << "th Quarter: ";
            cin >> sale;
            s.sales[i] = sale;
            max = (i==0) ? sale
                         : (sale>max) ? sale : max;
            min = (i==0) ? sale
                         : (sale<min) ? sale : min;
            avg += sale;
        }
        avg /= QUARTERS;
        s.max = max;
        s.min = min;
        s.average = avg;
    }
    void showSales(const Sales & s)
    {
        using namespace std;
        cout << "Sale Info:\n";
        for (int i=0; i<QUARTERS; i++)
            cout << "Sale for " << i+1 << "th Quarter: " << s.sales[i] << endl;
        cout << "Max Sale: " << s.max << endl;
        cout << "Min Sale: " << s.min << endl;
        cout << "Avg Sale: " << s.average << endl;
    }
}



