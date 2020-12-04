#include "plorg.h"
#include <cstring>

Plorg::Plorg()
{
    strcpy(p_name, "Plorga");
    p_ci = 50;
}

Plorg::Plorg(char* name, int ci)
{
    strcpy(p_name, name);
    p_ci = ci;
}

void Plorg::setCI(int ci)
{
    p_ci = ci;
}

void Plorg::showPlorg() const
{
    using namespace std;
    cout << "Name: " << p_name << ", CI: " << p_ci << endl;
}
