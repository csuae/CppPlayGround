//
//  main.cpp
//  display_demo
//
//  Created by Chunyou SU on 2020/11/12.
//  Copyright © 2020 Chunyou SU. All rights reserved.
//

#include <iostream>

void DisplayNameAddress();
void Furlong2Yards(int);
void DisplayAgeInMonths(); //capture age in year from keyboard input
double TempC2F(double);
void DisplayTime(int, int);

int main(int argc, const char * argv[]) {
    using namespace std;
    //DisplayNameAddress();
    
    //int valFurlong = 3;
    //Furlong2Yards(valFurlong);
    
    DisplayAgeInMonths();
    /*
    double valTempF, valTempC;
    cout << "Please enter a Celsius value: ";
    cin >> valTempC;
    valTempF = TempC2F(valTempC);
    cout << valTempC << " degrees Celsius is " << valTempF << " degrees Fahrenheit." << endl;
    */
    
    /*
    int valHour, valMin;
    cout << "Enter the number of hours: ";
    cin >> valHour;
    cout << "Enter the number of minutes: ";
    cin >> valMin;
    DisplayTime(valHour, valMin);
    */
    
    return 0;
}

void DisplayNameAddress()
{
    using namespace std;
    cout << "Name: Chunyou SU" << endl;
    cout << "Address: Clear Water Bay, HKUST, HongKong SAR" << endl;
}

void Furlong2Yards(int valFurlong)
{
    using namespace std;
    cout << valFurlong << " Furlongs are " << 220*valFurlong << " Yards." << endl;
}

void DisplayAgeInMonths()
{
    using namespace std;
    cout << "Enter your age: ";
    int age;
    cin >> age;
    cout << "Your age in months is: " << 12*age << endl;
}

double TempC2F(double valTempC)
{
    return 1.8*valTempC+32;
}

void DisplayTime(int valHour, int valMin)
{
    using namespace std;
    cout << "Time: " << valHour << ":" << valMin << endl;
}
