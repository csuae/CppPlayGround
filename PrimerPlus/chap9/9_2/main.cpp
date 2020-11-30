//
//  main.cpp
//  static
//
//  Created by Chunyou SU on 2020/11/30.
//  Copyright © 2020 csuae. All rights reserved.
//

#include <iostream>
#include <string>
#include <cctype>

void strcount(const std::string);

int main(int argc, const char * argv[]) {
    using namespace std;
    string input;
    
    cout << "Enter a line:\n";
    getline(cin, input);
    while (input != "")
    {
        strcount(input);
        cout << "Enter next line (empty line to quit):\n";
        getline(cin, input);
    }
    cout << "Bye!\n";
    return 0;
}

void strcount(const std::string str)
{
    using namespace std;
    static int total = 0;
    int count = 0;
    
    cout << "\"" << str <<"\" contains ";
    for (int i=0; i<(int)str.size(); i++)
    {
        if (!isblank(str[i])) // go to end of string
            count++;
    }
    total += count;
    cout << count << " characters\n";
    cout << total << " characters total\n";
}
