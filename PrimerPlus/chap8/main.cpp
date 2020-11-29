//
//  main.cpp
//  func_advanced
//
//  Created by Chunyou SU on 2020/11/29.
//  Copyright © 2020 Chunyou SU. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <string>
#include <cctype>
#include <array>

inline void ShowString(char* str) { std::cout << str << std::endl; }
void ShowString(char*, int); //1

struct CandyBar {
    std::string brandName;
    double weight;
    int numCalo;
};
void CandyBarMdfy(CandyBar &, std::string brandName="Millennium Munch", double weight=2.85, int numCalo=350);
void CandyBarShow(const CandyBar &); //2

void Str2Upper(std::string &);
void StrInvoke(); //3

struct stringy {
    char * str;
    int ct;
};
void set(stringy &, const char*);
void show(const stringy &str, int n=1); //print member string
void show(const char* str, int n=1); //print C-string
void InvokeFour(); //4

template <typename T>
T max5(T* ar);
void InvokeFive(); //5

template <typename T>
T maxn(T* ar, int n);
const int ArSize = 40;
template <> char* maxn<char*>(char* strAr[], int n); //explicit specialization
void InvokeSix(); //6

struct debts {
    char name[50];
    double amount;
};
template <typename T>
void SumArray(T arr[], int n);
template <typename T>
void SumArray(T* arr[], int n);
void InvokeSeven(); //7


int main(int argc, const char * argv[]) {
    //ShowString("Hello from the other side");
    //ShowString("It's me", 0);
    //ShowString("Adele", 9);
    //ShowString("Good Time", 4); //1
    
    //CandyBar demo = {"Arrow", 3.36, 420};
    //CandyBarShow(demo);
    //CandyBarMdfy(demo);
    //CandyBarShow(demo); //2
    
    //StrInvoke(); //3
    //InvokeFour(); //4
    //InvokeFive(); //5
    //InvokeSix(); //6
    InvokeSeven(); //7
    
    return 0;
}

void ShowString(char* str, int n)
{
    static int m = 1;
    if (n)
        for (int i=0; i<m; i++)
            std::cout << str << std::endl;
    ++m;
}

void CandyBarMdfy(CandyBar & cdy, std::string brandName, double weight, int numCalo)
{
    cdy.brandName = brandName;
    cdy.weight = weight;
    cdy.numCalo = numCalo;
}

void CandyBarShow(const CandyBar & cdy)
{
    using namespace std;
    cout << "BrandName:\t" << cdy.brandName << endl;
    cout << "Weight:\t\t" << cdy.weight << endl;
    cout << "Calories:\t" << cdy.numCalo << endl;
}

void StrInvoke(void)
{
    using namespace std;
    string tmpStr;
    
    cout << "Enter a string (q to quit): ";
    getline(cin, tmpStr);
    while (tmpStr != "q")
    {
        Str2Upper(tmpStr);
        cout << "Enter a string (q to quit): ";
        getline(cin, tmpStr);
    }
}

void Str2Upper(std::string &str)
{
    for (int i=0; i<str.size(); i++)
        str[i] = toupper(str[i]);
    std::cout << str << std::endl;
}

void InvokeFour(void)
{
    using namespace std;
    stringy beany;
    char testing[] = "Reality isn't what it used to be.";

    set(beany, testing);
    show(beany);
    show(beany, 2);
    testing[0] = 'D';
    testing[1] = 'u';
    show(testing);
    show(testing, 3);
    show("Done!");
}

void set(stringy &str, const char* inStr)
{
    char* tmpStr = new char[strlen(inStr)+1];
    strcpy(tmpStr, inStr);
    str.str = tmpStr;
    str.ct = strlen(tmpStr);
}

void show(const stringy &str, int n)
{
    using namespace std;
    for (int i=0; i<n; i++)
        cout << str.str << endl;
}

void show(const char* str, int n)
{
    using namespace std;
    for (int i=0; i<n; i++)
        cout << str << endl;
}

template <typename T>
T max5(T* ar)
{
    T maxval = ar[0];
    for (int i=1; i<5; i++)
        if (ar[i]>maxval)
            maxval = ar[i];
    return maxval;
}

void InvokeFive(void)
{
    using namespace std;
    int ar1[5] = {3, 1, 4, 1, 5};
    double ar2[5] = {3.14, 1.59, 2.65, 3.58, 9.79};
    cout << max5(ar1) << endl;
    cout << max5(ar2) << endl;
}

template <typename T>
T maxn(T* ar, int n)
{
    T maxval = ar[0];
    for (int i=1; i<n; i++)
        if (ar[i]>maxval)
            maxval = ar[i];
    return maxval;
}

template <> char* maxn<char*>(char* strAr[], int n)
{
    int idx = 0;
    int maxlen = strlen(strAr[0]);
    for (int i=1; i<n; i++)
    {
        if (strlen(strAr[i])>maxlen)
        {
            idx = i;
            maxlen = strlen(strAr[i]);
        }
    }
    return strAr[idx];
}

void InvokeSix(void)
{
    using namespace std;
    int ar1[6] = {3, 1, 4, 1, 5, 9};
    double ar2[4] = {2.7, 1.8, 2.8, 6.5};
    char *strAr[5] = {
        "Hey Jude",
        "Don't make it bad",
        "Remember to let her into your heart",
        "Take a sad song",
        "And make it better",
    };
    
    cout << maxn(ar1, 6) << endl;
    cout << maxn(ar2, 4) << endl;
    cout << (void *)maxn(strAr, 5) << endl;
}

template <typename T>
void SumArray(T arr[], int n)
{
    using namespace std;
    T sum = 0;
    for (int i=0; i<n; i++)
        sum += arr[i];
    cout << "Ver1. #elements: " << n << endl;
    cout << "Sum: " << sum << endl;
}

template <typename T>
void SumArray(T* arr[], int n)
{
    using namespace std;
    T sum = 0;
    for (int i=0; i<n; i++)
        sum += *arr[i];
    cout << "Ver2. #elements: " << n << endl;
    cout << "Sum: " << sum << endl;
}

void InvokeSeven(void)
{
    int things[6] = {13, 31, 103, 301, 310, 130};
    struct debts mr_E[3] = {
        {"Ima Wolfe", 2400.0},
        {"Ura Foxe", 1300.0},
        {"Iby Stout", 1800.0}
    };
    double * pd[3];
    for (int i = 0; i < 3; i++)
        pd[i] = &mr_E[i].amount;
    SumArray(things, 6);
    SumArray(pd, 3);
}
