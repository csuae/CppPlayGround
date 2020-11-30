//
//  main.cpp
//  golf
//
//  Created by Chunyou SU on 2020/11/30.
//  Copyright © 2020 csuae. All rights reserved.
//

#include <iostream>
#include "golf.h"

int main(int argc, const char * argv[]) {
    golf gfArr[5];
    setgolf(gfArr[0], "Ann Birdfree", 24);
    
    for (int i=1; i<5; i++)
    {
        if (!setgolf(gfArr[i]))
            break;
        showgolf(gfArr[i-1]);
    }
    handicap(gfArr[4], 21);
    showgolf(gfArr[4]);
    
    return 0;
}
