#include <iostream>
#include "person.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	using namespace std;

	Person one; // use default constructor
	Person two("Smythecraft"); // use #2 with one default argument
	Person three("Dimwiddy", "Sam"); // use #2, no defaults
	one.Show();
	cout << endl;
	one.FormalShow();
	
	two.Show();
	cout << endl;
	two.FormalShow();

	three.Show();
	cout << endl;
	three.FormalShow();
	
	return 0;
}
