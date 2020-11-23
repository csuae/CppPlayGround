//
//  main.cpp
//  chap7 func_basics, 1-8
//
//  Created by Chunyou SU on 2020/11/23.
//  Copyright © 2020 Chunyou SU. All rights reserved.
//

#include <iostream>

void HarmonicAvg(); //1
int GolfInput(double*);
void GolfDisplay(const double*, int);
void GolfAvg(const double*, int); //2

struct box {
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};
void UseStructArg();
void DisplayStruct(const box);
void ModifyStruct(box*); //3
void WinLotto();
long double ProbClac(unsigned numbers, unsigned picks); //4
void InvokeFact();
long FactClac(int); //5

void InvokeArray();
int Fill_array(double*, int);
void Show_array(double*, int);
void Reverse_array(double*, int); //6

void invoke_array();
double* fill_array(double*, int);
void show_array(const double* head, const double* tail);
void revalue(double, double* head, double* tail); //7

struct exp {
    double expAr[4];
};
void InvokeSeason();
void SeasonFillv1(const char SeasonName[][10], double*);
void SeasonShowv1(const char SeasonName[][10], double*);
void SeasonFillv2(const char SeasonName[][10], exp*);
void SeasonShowv2(const char SeasonName[][10], exp); //8


int main(int argc, const char * argv[]) {
    //HarmonicAvg(); //1
    
    //int numScore = 0;
    //double golfScore[10];
    //numScore = GolfInput(golfScore);
    //GolfDisplay(golfScore, numScore);
    //GolfAvg(golfScore, numScore); //2
    
    //UseStructArg(); //3
    //WinLotto(); //4
    
    //InvokeFact(); //5
    //InvokeArray(); //6
    //invoke_array(); //7
    InvokeSeason(); //8
    
    return 0;
}

void HarmonicAvg(void)
{
    using namespace std;
    cout << "Input a pair of numbers: ";
    double x, y, harmonicAvg;
    while (cin>>x>>y)
    {
        harmonicAvg = 2*x*y / (x+y);
        cout << "The Harmonic Average of " << x << " and " << y << " is " << harmonicAvg << endl;
        if (!harmonicAvg)
            break;
        cout << "Input a pair of numbers: ";
    }
}

int GolfInput(double* arScore)
{
    using namespace std;
    cout << "Input the Golf Score, up to 10 records, negtive value to terminate:\n";
    int i;
    double tmpScore;
    for (i=0; i<10; i++)
    {
        cin >> tmpScore;
        if (tmpScore<0)
            break;
        arScore[i] = tmpScore;
        cout << "Input Next Score:\n";
    }
    return i; //num. of scores
}

void GolfDisplay(const double* arScore, int numScore)
{
    using namespace std;
    cout << "Your Input Golf Scores are:\n";
    for (int i=0; i<numScore; i++)
        cout << i+1 << ": " << arScore[i] << endl;
}

void GolfAvg(const double* arScore, int numScore)
{
    using namespace std;
    double avg = 0.0, sum = 0.0;
    for (int i=0; i<numScore; i++)
        sum += arScore[i];
    avg = sum / numScore;
    cout << "Your Average Golf Score is: " << avg << endl;
}

void UseStructArg(void)
{
    using namespace std;
    box boxVal = {"PlainCube", 5.2, 5.2, 5.2, 125.2};
    DisplayStruct(boxVal);
    ModifyStruct(&boxVal);
    DisplayStruct(boxVal);
}

void DisplayStruct(box boxVal)
{
    using namespace std;
    cout << "Maker:\t" << boxVal.maker << endl;
    cout << "Height:\t" << boxVal.height << endl;
    cout << "Width:\t" << boxVal.width << endl;
    cout << "Length:\t" << boxVal.length << endl;
    cout << "Volume:\t" << boxVal.volume << endl;
}

void ModifyStruct(box* ptrBox)
{
    ptrBox->volume = ptrBox->height * ptrBox->width * ptrBox->length;
}

long double ProbClac(unsigned numbers, unsigned picks)
{
    long double result = 1.0; //local variables
    long double n;
    unsigned p;
    for (n = numbers, p = picks; p > 0; n--, p--)
        result = result * n / p ;
    return result;
}

void WinLotto(void)
{
    using namespace std;
    cout << "Enter the total number of choices of field numbers\n"
            "and the number of picks allowed:\n";
    unsigned numField, pickField, numMega;
    long double winBase = 1.0;
    
    while (cin >> numField >> pickField)
    {
        cout << "Enter the total number of choices of mega numbers\n";
        cin >> numMega;
        winBase = ProbClac(numField, pickField) * ProbClac(numMega, 1);
        cout << "You have one chance in " << winBase << " to win.\n";
        cout << "Enter next total number and allowed picks for field numbers\n"
                "(q to quit):";
    }
}

void InvokeFact(void)
{
    using namespace std;
    int n;
    long ans  = 1;
    cout << "Input an unsigned integer that you want to know its factorial:\n";
    
    while (cin >> n)
    {
        if (n<0)
            break;
        ans = FactClac(n);
        cout << n << "! = " << ans << endl;
        cout << "Next input: ";
    }
}

long FactClac(int n)
{
    if (n == 0)
        return 1;
    return n*FactClac(n-1);
}

int Fill_array(double* ar, int size)
{
    using namespace std;
    double tmpVal;
    int i = 0;
    cout << "Enter the " << i+1 << " th element of the array: \n";
    while (cin>>tmpVal)
    {
        ar[i++] = tmpVal;
        if (i>=size)
            break;
        cout << "Enter the " << i+1 << " th element of the array: \n";
    }
    return i;
}

void Show_array(double* ar, int size)
{
    using namespace std;
    for (int i=0; i<size; i++)
        cout << "ar[" << i << "] = " << ar[i] << endl;
}

void Reverse_array(double* ar, int size)
{
    int head = 0, tail = size-1;
    double tmpVal;
    while (head<tail)
    {
        tmpVal = ar[head];
        ar[head++] = ar[tail];
        ar[tail--] = tmpVal;
    }
}

void InvokeArray()
{
    using namespace std;
    int arSize, realSize;
    cout << "Input the max array size: ";
    cin >> arSize;
    double* ar = new double[arSize];
    realSize = Fill_array(ar, arSize);
    Show_array(ar, realSize);
    Reverse_array(ar, realSize);
    Show_array(ar, realSize);
}

void invoke_array()
{
    using namespace std;
    int arSize;
    double* arTail;
    cout << "Input the max array size: ";
    cin >> arSize;
    double* ar = new double[arSize];
    arTail = fill_array(ar, arSize);
    show_array(ar, arTail);
    revalue(2.1, ar, arTail);
    show_array(ar, arTail);
}

double* fill_array(double ar[], int limit)
{
    using namespace std;
    double temp;
    int i;
    double* tailAddr = ar;
    for (i = 0; i < limit; i++)
    {
        cout << "Enter value #" << (i + 1) << ": ";
        cin >> temp;
        if (!cin) // bad input
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Bad input; input process terminated.\n";
            break;
        }
        else if (temp < 0) // signal to terminate
            break;
        ar[i] = temp;
    }
    return (tailAddr+i);
}

void show_array(const double* head, const double* tail)
{
    using namespace std;
    for (int i=0; head+i<tail; i++)
        cout << "Property #" << (i + 1) << ": $" << head[i] << endl;
}

void revalue(double r, double* head, double* tail)
{
    using namespace std;
    cout << "Revaluing the array by the factor of " << r << endl;
    for (int i=0; head+i<tail; i++)
        head[i] *= r;
}

void InvokeSeason(void)
{
    const char SeasonName[4][10] = {
        "Spring",
        "Summer",
        "Autumn",
        "Winter"
    };
    //double expenses[4];
    //SeasonFillv1(SeasonName, expenses);
    //SeasonShowv1(SeasonName, expenses);
    
    exp expVal;
    SeasonFillv2(SeasonName, &expVal);
    SeasonShowv2(SeasonName, expVal);
}

void SeasonFillv1(const char SeasonName[][10], double* expenses)
{
    using namespace std;
    for (int i = 0; i < 4; i++)
    {
        cout << "Enter " << SeasonName[i] << " expenses: ";
        cin >> expenses[i];
    }
}

void SeasonShowv1(const char SeasonName[][10], double* expenses)
{
    using namespace std;
    double total = 0.0;
    cout << "\nEXPENSES\n";
    for (int i = 0; i < 4; i++)
    {
        cout << SeasonName[i] << ": $" << expenses[i] << endl;
        total += expenses[i];
    }
    cout << "Total Expenses: $" << total << endl;
}

void SeasonFillv2(const char SeasonName[][10], exp* expVal)
{
    using namespace std;
    for (int i = 0; i < 4; i++)
    {
        cout << "Enter " << SeasonName[i] << " expenses: ";
        cin >> expVal->expAr[i];
    }
}

void SeasonShowv2(const char SeasonName[][10], exp expVal)
{
    using namespace std;
    double total = 0.0;
    cout << "\nEXPENSES\n";
    for (int i = 0; i < 4; i++)
    {
        cout << SeasonName[i] << ": $" << expVal.expAr[i] << endl;
        total += expVal.expAr[i];
    }
    cout << "Total Expenses: $" << total << endl;
}
