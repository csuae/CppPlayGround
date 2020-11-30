//
//  golf.h
//  golf
//
//  Created by Chunyou SU on 2020/11/30.
//  Copyright © 2020 csuae. All rights reserved.
//

#ifndef golf_h
#define golf_h

const int Len = 40;
struct golf
{
    char fullname[Len];
    int handicap;
};

// non-interactive version
void setgolf(golf & g, const char * name, int hc);

// interactive version
int setgolf(golf & g);

// function resets handicap to new value
void handicap(golf & g, int hc);

// function displays contents of golf structure
void showgolf(const golf & g);

#endif /* golf_h */
