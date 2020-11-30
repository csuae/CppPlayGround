//
//  golf.cpp
//  golf
//
//  Created by Chunyou SU on 2020/11/30.
//  Copyright © 2020 csuae. All rights reserved.
//

#include <iostream>
#include <cstring>
#include "golf.h"

void setgolf(golf & g, const char* name, int hc)
{
    strncpy(g.fullname, name, Len-1);
    g.fullname[Len-1] = '\0';
    g.handicap = hc;
}

int setgolf(golf & g)
{
    using namespace std;
    int tmpHc;
    char tmpName[Len];
    cout << "Input a fullname: ";
    cin.getline(tmpName, Len);
    strncpy(g.fullname, tmpName, Len-1);
    g.fullname[Len-1] = '\0';
    
    cout << "Input the handicap: ";
    cin >> tmpHc;
    cin.get();
    g.handicap = tmpHc;
    return strcmp(tmpName, "");
}

void handicap(golf & g, int hc)
{
    g.handicap = hc;
}

void showgolf(const golf & g)
{
    using namespace std;
    cout << "Full Name:\t" << g.fullname << endl;
    cout << "Handicap:\t" << g.handicap << endl;
}
