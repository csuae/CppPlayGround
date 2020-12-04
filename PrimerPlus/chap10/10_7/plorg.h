#include <iostream>

#ifndef PLORG_H_
#define PLORG_H_

class Plorg
{
private:
    char p_name[20];
    int p_ci;
public:
    Plorg();
    Plorg(char* name, int ci=50);
    void setCI(int);
    void showPlorg() const;
};

#endif