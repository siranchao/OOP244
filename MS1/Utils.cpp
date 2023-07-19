// Final Project Milestone 1 
// Utlils Module
// Student Name: Siran Cao
// ID: 159235209
// Revision History
// -----------------------------------------------------------
// Version               Date                 Reason
// 1.0         	       11/7/2021             ms-1 submission
/////////////////////////////////////////////////////////////////

#include <iostream>
#include <ctype.h>
#include "Utils.h"
using namespace std;
namespace sdds {
	void getChar(std::istream& istr) {
		if (isdigit(istr.peek())) {
			istr.setstate(ios::failbit);
		}
		else {
			istr.get();
		}
	}

	int getInt(std::istream& istr, int limit) {
		int res = 0;
		istr >> res;
		while (!istr || res < 0 || res > limit) {
			istr.clear();
			istr.ignore(1024, '\n');
			cout << "Invalid Selection, try again: ";
			istr >> res;
		}
		return res;
	}





}