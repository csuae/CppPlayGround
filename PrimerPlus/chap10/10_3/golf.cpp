#include <iostream>
#include <cstring>
#include "golf.h"

Golf::Golf(const char* fn, int hdcap)
{
    strncpy(fullname, fn, Len-1);
    fullname[Len-1] = '\0';
    handicap = hdcap;
}

Golf::~Golf()
{
    // doing nothing
}

void Golf::setgolf(void)
{
    using namespace std;
    int tmpHc;
    char tmpName[Len];
    cout << "Input a fullname: ";
    cin.getline(tmpName, Len-1);
    tmpName[Len-1] = '\0';
    
    cout << "Input the handicap: ";
    cin >> tmpHc;
    cin.get();

    *this = Golf(tmpName, tmpHc);
}

void Golf::Handicap(int hp)
{
    handicap = hp;
}

void Golf::showgolf(void)
{
    using namespace std;
    cout << "Full Name:\t" << fullname << endl;
    cout << "Handicap:\t" << handicap << endl;
}
