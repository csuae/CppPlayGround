#include <iostream>
#include "move.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Move m[2] = {
		Move(3.0, 4.0),
		Move(5.0, 12.0)
	};
	m[0].showmove();
	m[1].showmove();
	
	m[0].add(m[1]).showmove();
	m[1].reset(1.414, 1.414);
	m[1].showmove();

	return 0;
}
