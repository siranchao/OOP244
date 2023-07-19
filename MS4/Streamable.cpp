// Final Project Milestone 4
// Student Name: Siran Cao
// ID: 159235209
// Revision History
// -----------------------------------------------------------
// Version               Date                 Reason
// 1.0         	       11/26/2021             ms-4 submission
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