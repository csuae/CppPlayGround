#include <iostream>
#include "lst.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void showItem(Item &);
void doubleItem(Item &);

int main(int argc, char** argv) {
	List lst;
	for (int i=0; i<9; i++)
		lst.addItem(10-i);
	lst.visit(showItem);
	std::cout << std:: endl;
	lst.visit(doubleItem);
	lst.visit(showItem);

	return 0;
}

void showItem(Item & item)
{
	using namespace std;
	cout << item << ' ';
}

void doubleItem(Item & item)
{
	item*=2;
}

