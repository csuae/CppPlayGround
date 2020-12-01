#include "person.h"
#include <cstring>

Person::Person(const std::string & ln, const char * fn)
{
    lname = ln;
    strncpy(fname, fn, LIMIT);
    fname[LIMIT] = '\0';
}

void Person::Show(void) const
{
    using namespace std;
    cout << fname << " " << lname << endl;
}

void Person::FormalShow(void) const
{
    using namespace std;
    cout << lname << ", " << fname << endl;
}
