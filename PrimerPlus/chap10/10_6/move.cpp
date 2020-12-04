#include "move.h"


Move::Move(double a, double b)
{
    x = a;
    y = b;
}

Move::showmove() const
{
    using namespace std;
    cout << "x=" << x << ", y=" << y << endl;
}

Move Move::add(const Move & m) const
{
    Move tmpObj(x+m.x, y+m.y);
    return tmpObj;
}

Move::reset(double a, double b)
{
    x = a;
    y = b;
}

