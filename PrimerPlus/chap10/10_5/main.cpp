#include <iostream>
#include "stack.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void PopReport(Stack & s, double & rt);

int main(int argc, char** argv) {
	Stack stk;
	customer cst[5] = {
		{"Misaka", 25.6},
		{"Thoka", 4.1},
		{"Origami", 11.4},
		{"Asuna", 7.82},
		{"Mayuri", 6.53}
	};
	double running_total = 0;

	stk.push(cst[1]);
	PopReport(stk, running_total);
	stk.push(cst[4]);
	PopReport(stk, running_total);

	stk.push(cst[3]);
	stk.push(cst[0]);
	stk.push(cst[2]);
	PopReport(stk, running_total);
	PopReport(stk, running_total);

	return 0;
}

void PopReport(Stack & s, double & rt)
{
	using namespace std;
	customer tmpCustomer;
	if (s.pop(tmpCustomer))
	{
		rt += tmpCustomer.payment;
		cout << "Current Running Total: " << rt << endl;
	}
	else
		cout << "Empty Stack\n.";
}

