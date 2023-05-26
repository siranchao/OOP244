// Workshop 2:
// Version: 0.9
// Date: 2021/09/17
// Description:
// This file tests the lab section of your workshop
/////////////////////////////////////////////
#include <iostream>
#include "Fighter.h"

using namespace std;
using namespace sdds;

int main() {

	Competition mycompetition = {nullptr, 0};

	cout << "*********************************" << endl;
	cout << "Welcome to OOP244-Mortal Kombat" << endl;
	cout << "*********************************" << endl;
	int i;
	for (i = 0; i < 4; i++) {
		addFighter(mycompetition);
	}
	cout << "*********************************" << endl;
	cout << "List of fighters:" << endl;
	display(mycompetition);
	cout << "*********************************" << endl;
	cout << "Let the fights begin:" << endl;
	cout << "*********************************" << endl;
	while (mycompetition.numfighters > 1) {
		fight(mycompetition, mycompetition.fighters[0], mycompetition.fighters[1]);
		if (mycompetition.numfighters > 1) {
			cout << "*********************************" << endl;
			cout << "List of fighters Still Standing:" << endl;
			display(mycompetition);
			cout << "*********************************" << endl;
		}
	}
	cout << "*********************************" << endl;
	cout << "The winner of the competition is:" << endl;
	display(mycompetition);
	delete[] mycompetition.fighters;
	return 0;
}