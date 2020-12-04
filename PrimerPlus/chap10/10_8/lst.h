#include <iostream>
#ifndef LST_H_
#define LST_H_

typedef int Item;

class List
{
private:
    enum {MAX = 10};
    Item items[MAX];
    int ptr;
public:
    List();
    bool isempty() const;
    bool isfull() const;
    void addItem(const Item & item);
    void visit(void (*pf)(Item &)); // visit an item and perform some action
};

#endif
