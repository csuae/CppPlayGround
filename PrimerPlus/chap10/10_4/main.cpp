#include <iostream>
#include "sale.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	using namespace SALES;
	double saleVal[QUARTERS] = {12.3, 46.7, 32.4, 87.5};
	Sales sy1(saleVal, QUARTERS);
	Sales sy2;
	sy2.setSales();

	sy1.showSales();
	sy2.showSales();
	return 0;
}
