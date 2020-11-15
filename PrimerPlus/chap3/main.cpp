//
//  main.cpp
//  basic_data_demo
//
//  Created by Chunyou SU on 2020/11/15.
//  Copyright © 2020 Chunyou SU. All rights reserved.
//

#include <iostream>

void inch2feet();
void BMIcalc();
void Latitude2dec();

int main(int argc, const char * argv[]) {
    // insert code here...
    //inch2feet();
    //BMIcalc();
    Latitude2dec();
    
    return 0;
}

void inch2feet(void)
{
    using namespace std;
    cout << "Input your height in inches:__\b\b"; //MacOS cannot deal with \b
    int valInch;
    cin >> valInch;
    const int Inches_per_foot = 12;
    int valFeet, valRemainInch;
    valFeet = valInch / Inches_per_foot;
    valRemainInch = valInch % Inches_per_foot;
    cout << "Your height is " << valFeet << " Feet, " << valRemainInch << " Inches" << endl;
}

void BMIcalc(void)
{
    using namespace std;
    cout << "Input your height in feet and inches:" << endl;
    int valFeet, valInch;
    cout << "#Feet: ";
    cin >> valFeet;
    cout << "#Inches: ";
    cin >> valInch;
    
    int valPounds;
    cout << "Input your weight in pounds: ";
    cin >> valPounds;
    
    double valMeter, valKilogram;
    const int Inches_per_foot = 12;
    const double Meter_per_inch = 0.0254;
    const double Pounds_per_kg = 2.2;
    valKilogram = valPounds / Pounds_per_kg;
    valMeter = (valFeet*Inches_per_foot + valInch) * Meter_per_inch;
    
    double valBMI;
    valBMI = valKilogram / (valMeter*valMeter);
    cout << "Your BMI value is: " << valBMI << endl;
}

void Latitude2dec()
{
    using namespace std;
    cout << "Enter a latitude in degrees, minutes, and seconds: " << endl;
    int valDegree, valMinute, valSecond;
    cout << "First, enter the degrees: ";
    cin >> valDegree;
    cout << "Next, enter the minutes of arc: ";
    cin >> valMinute;
    cout << "Finally, enter the seconds of arc: ";
    cin >> valSecond;
    
    double valDecimaldeg;
    valDecimaldeg = valDegree + valMinute/60.0 + valSecond/3600.0;
    cout << valDegree<< " degrees," << valMinute << " minutes," << valSecond << " seconds = " << valDecimaldeg << " degrees" << endl;
}
