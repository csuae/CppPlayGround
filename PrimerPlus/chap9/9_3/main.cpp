//
//  main.cpp
//  chaff
//
//  Created by Chunyou SU on 2020/11/30.
//  Copyright © 2020 csuae. All rights reserved.
//

#include <iostream>
#include <cstring>

struct chaff
{
    char dross[20];
    int slag;
};

int main(int argc, const char * argv[]) {
    double buffer[40];
    chaff *ptr;
    const char drosses[2][20] = {
        "Timmy",
        "Lordy"
    };
    
    ptr = new (buffer) chaff[2]; // placement new
    for (int i=0; i<2; i++)
    {
        strcpy(ptr[i].dross, drosses[i]);
        ptr[i].slag = i+10;
        std::cout << i << ":\t" << ptr[i].dross << "\t" << ptr[i].slag << std::endl;
    }
    
    return 0;
}
