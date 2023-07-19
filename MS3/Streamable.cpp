// Final Project Milestone 3
// Menu Module
// Student Name: Siran Cao
// ID: 159235209
// Revision History
// -----------------------------------------------------------
// Version               Date                 Reason
// 1.0         	       11/14/2021             ms-3 submission
/////////////////////////////////////////////////////////////////
#include <iostream>
#include "Streamable.h"
using namespace std;
namespace sdds {
	Streamable::~Streamable() {
		// empty
	}

	ostream& operator<<(ostream& os, const Streamable& src) {
		if (src) src.write(os);
		return os;
	}
	istream& operator>>(istream& is, Streamable& src) {
		return src.read(is);
	}

}