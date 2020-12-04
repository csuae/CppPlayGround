#include "lst.h"

List::List()
{
    ptr = 0;
}

bool List::isempty() const
{
    return ptr==0;
}

bool List::isfull() const
{
    return ptr==MAX-1;
}

void List::addItem(const Item & item)
{
    if (isfull())
    {
        std::cout << "List is full, cannot add.\n";
        return;
    }
    items[ptr++] = item;
}

void List::visit(void (*pf)(Item &))
{
    for (int i=0; i<ptr; i++)
        (*pf)(items[i]);
}
