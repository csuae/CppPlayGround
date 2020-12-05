#include <iostream>
#include <fstream>
#include <cstdlib> // rand(), srand() prototypes
#include <ctime> // time() prototype
#include "vect.h"

int main()
{
	using namespace std;
	using VECTOR::Vector;
	ofstream outFile;

	srand(time(0)); // seed random-number generator
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;
	cout << "Enter target distance (q to quit): ";
	
	outFile.open("record.txt");
	while (cin >> target)
	{
		cout << "Enter step length: ";
		if (!(cin >> dstep))
			break;
		outFile << "Target Distance: " << target << ", Step Size: " << dstep << endl;
		outFile << "0: (x,y) = (0, 0)\n";
		while (result.magval() < target)
		{
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
			steps++;
			outFile << steps <<": (x,y) = " << "(" << result.xval() << ", " << result.yval() << ")\n";
		}
		outFile << "After " << steps << " steps, the subject has the following location:\n";
		outFile << result << endl;
		result.polar_mode();
		outFile << " or\n" << result << endl;
		outFile << "Average outward distance per step = " << result.magval()/steps << endl;
		steps = 0;
		result.reset(0.0, 0.0);
		cout << "Enter target distance (q to quit): ";
	}
	cout << "Bye!\n";
	cin.clear();
	while (cin.get() != '\n')
		continue;

	outFile.close();
	return 0;
}
