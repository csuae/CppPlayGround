#include <iostream>
#include "sale.h"

using namespace SALES;

Sales::Sales(const double ar[], int n)
{
    int i, num = (n<QUARTERS) ? n : QUARTERS;
    double t_max=ar[0], t_min=ar[0], t_avg=0;
    for (i=0; i<num; i++)
    {
        t_max = (ar[i]>t_max) ? ar[i] : t_max;
        t_min = (ar[i]<t_min) ? ar[i] : t_min;
        sales[i] = ar[i];
        t_avg += ar[i];
    }
    t_avg /= QUARTERS;
    for (; i<QUARTERS; i++)
        sales[i] = 0;
    max = t_max;
    min = t_min;
    avg = t_avg;
}

Sales::~Sales()
{
    // doing nothing
}

void Sales::setSales(void)
{
    using namespace std;
    double arr[QUARTERS];
    double tmpsale;
    for (int i=0; i<QUARTERS; i++)
    {
        cout << "Input the sale for " << i+1 << "th Quarter: ";
        cin >> tmpsale;
        arr[i] = tmpsale;
    }
    *this = Sales(arr, QUARTERS);
}

void Sales::showSales(void)
{
    using namespace std;
    cout << "Sale Info:\n";
    for (int i=0; i<QUARTERS; i++)
        cout << "Sale for " << i+1 << "th Quarter: " << sales[i] << endl;
    cout << "Max Sale: " << max << endl;
    cout << "Min Sale: " << min << endl;
    cout << "Avg Sale: " << avg << endl;
}

