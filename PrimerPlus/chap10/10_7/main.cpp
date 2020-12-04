#include <iostream>
#include "plorg.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Plorg p;
	p.showPlorg();
	Plorg q("QiJiang");
	q.showPlorg();
	q.setCI(22);
	q.showPlorg();
	
	return 0;
}
