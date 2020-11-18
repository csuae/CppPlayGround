#include <iostream>
#include <cstring>
#include <string>
#include <array>

void RangeSum(); //1
void CalFactorial(); //2
void CumulativeSum(); //3
void InvestCmp(); //4
void SalesCount(); //5-6
void CarMsg(); //7
void Count2Done(); //8-9
void DisplayStar(); //10

int main(int argc, const char* argv[])
{
    //RangeSum();
    //CalFactorial();
    //CumulativeSum();
    //InvestCmp();
    //SalesCount();
    //CarMsg();
    //Count2Done();
    DisplayStar();
}

void RangeSum(void)
{
    using namespace std;
    int smallInt, bigInt;
    cout << "Input the smaller integer: ";
    cin >> smallInt;
    cout << "Input the bigger integer: ";
    cin >> bigInt;
    int sum = 0;
    for (int i=smallInt; i<=bigInt; i++)
        sum += i;
    cout << "Summation: " << sum << endl;
}

void CalFactorial(void)
{
    using namespace std;
    const int ArSize = 100;
    array <long double, ArSize> factorials;
    factorials[1] = factorials[0] = 1L;
    for (int i = 2; i <= ArSize; i++)
        factorials[i] = i * factorials[i-1];
    cout << ArSize << "! = " << factorials[100] << endl;
}

void CumulativeSum(void)
{
    using namespace std;
    int cumulSum = 0;
    int tmpInt;
    cout << "Input an integer, 0 to exit.\n";
    cin >> tmpInt;
    while (tmpInt)
    {
        cout << "Input one more integer: ";
        cumulSum += tmpInt;
        cin >> tmpInt;
    }
    cout << "The cumulative sum is: " << cumulSum << endl;
}

void InvestCmp(void)
{
    using namespace std;
    double totalMny1 = 100.0, totalMny2 = 100.0;
    int year = 0;

    do  {
        totalMny1 += 10;
        totalMny2 *= 1.05;
        ++year;
    } while (totalMny1>=totalMny2);
    cout << "Year " << year << ", Money1 = " << totalMny1 << ", Money2 = " << totalMny2 << endl;
}

void SalesCount(void)
{
    using namespace std;
    const string months[12] = {
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"
    };
    // int sales[12] {};
    // int sumSales = 0;
    // for (int i=0; i<12; i++)
    // {
    //     cout << "Input sales for " << months[i] << ": ";
    //     cin >> sales[i];
    //     sumSales += sales[i];
    // }
    // cout << "Total sum: " << sumSales << endl;
    int sales[3][12] {
        {},
        {},
        {}
    };
    int sumSales[3] = {};
    for (int j=0; j<3; j++)
    {
        for (int i=0; i<12; i++)
        {
            cout << "Input sales for Year " << j+1 << ", " << months[i] << ": ";
            cin >> sales[j][i];
            sumSales[j] += sales[j][i];
        }
        cout << "Total sum: for Year " << j+1 << ", " << sumSales[j] << endl;
    }

}

void CarMsg(void)
{
    using namespace std;
    struct car{
        string make;
        int builtYear;
    };
    int numCars;
    cout << "How many cars do you wish to catalog? ";
    cin >> numCars;
    cin.get(); //deal with newline
    car* carInfo = new car[numCars];
    
    for (int i=0; i<numCars; i++)
    {
        cout << "Car #" << i+1 << ":\n";
        cout << "Please enter the make: ";
		getline(cin, carInfo[i].make);

        cout << "Please enter the year made: ";
        cin >> carInfo[i].builtYear;
        cin.get(); //deal with newline
    }
    cout << "Here is your collection:\n";
    for (int i=0; i<numCars; i++)
        cout << carInfo[i].builtYear << " " << carInfo[i].make << endl;
}

void Count2Done(void)
{
    using namespace std;
    cout << "Enter words (to stop, type the word done):\n";
    int numWords = 0;
    // char tmpWord[20];
    // cin >> tmpWord;
    // while (strcmp(tmpWord, "done"))
    // {
    //     cin >> tmpWord;
    //     ++numWords;
    // }
    string tmpWord;
    cin >> tmpWord;
    while (tmpWord != "done")
    {
        cin >> tmpWord;
        ++numWords;
    }
    cout << "You entered a total of " << numWords << " words.";
}

void DisplayStar(void)
{
    using namespace std;
    int numRow;
    cout << "Enter number of rows: ";
    cin >> numRow;
    for (int i=1; i<=numRow; i++)
    {
        for (int j=numRow; j>i; j--)
            cout << ".";
        for (int j=0; j<i; j++)
            cout << "*";
        cout << endl;
    }
}
