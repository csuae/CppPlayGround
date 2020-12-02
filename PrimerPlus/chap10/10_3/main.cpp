#include <iostream>
#include "golf.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Golf Ann("Ann Birdfree", 24);
	Golf Bob;
	Bob.setgolf();
	Bob.showgolf();

	Ann.Handicap(23);
	Ann.showgolf();
	
	return 0;
}
