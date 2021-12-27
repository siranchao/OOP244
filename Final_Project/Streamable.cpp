/* Final Project Milestone 5
Module: Streamable
Filename: .cpp
Author:	Siran Cao
Student ID:	159235209
Revision History
-----------------------------------------------------------
Version               Date                 Reason
1.0         	    12/02/2021           ms-5 submission
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
----------------------------------------------------------- */

#include <iostream>
#include "Streamable.h"
namespace sdds {
	Streamable::~Streamable() {
		// empty
	}

	std::ostream& operator<<(std::ostream& os, const Streamable& src) {
		if (src) src.write(os);
		return os;
	}
	std::istream& operator>>(std::istream& is, Streamable& src) {
		return src.read(is);
	}

}